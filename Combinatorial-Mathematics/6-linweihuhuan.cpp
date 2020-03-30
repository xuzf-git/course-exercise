#include <stdio.h>
#include <string.h>
#define MAX 15
int pos[MAX];
int path[MAX]; // 方向 0 向左，1向右；[
int m, n, k;
void Move()
{
    int flag = 0;
    for (int i = n; i > 0; i--)
    {
        if (path[i] == 0) // 向左移动
        {
            for (int j = i - 1; j > 0; j--)
                if (pos[j] == pos[i] - 1) // 可移动条件
                {
                    pos[i]--;
                    pos[j]++;
                    for (int k = i + 1; k <= n; k++)
                    {
                        path[k] = (path[k] + 1) % 2; // 更改比他大的元素的方向
                    }
                    flag = 1;
                    break;
                }
        }
        else // 向右移动
        {
            for (int j = i - 1; j > 0; j--)
                if (pos[j] == pos[i] + 1) // 可移动条件
                {
                    pos[i]++;
                    pos[j]--;
                    for (int k = i + 1; k <= n; k++)
                    {
                        path[k] = (path[k] + 1) % 2; // 更改比他大的元素的方向
                    }
                    flag = 1;
                    break;
                }
        }
        if (flag)
        {
            break;
        }
    }
}
void Print()
{
    int out[MAX];
    for (int i = 1; i <= n; i++)
    {
        out[pos[i]] = i;
    }
    for (int i = 1; i < n; i++)
    {
        printf("%d ", out[i]);
    }
    printf("%d\n", out[n]);
}
int main(int argc, char const *argv[])
{
    scanf("%d", &m);
    while (m--)
    {
        // n 是元素个数，k 是输出第几个排列
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            pos[i] = i;
        memset(path, 0, sizeof(path));
        for (int i = 1; i < k; i++)
        {
            Move();
        }
        Print();
    }
    return 0;
}
