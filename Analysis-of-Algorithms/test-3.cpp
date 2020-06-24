#include <stdio.h>
#include <string.h>
int graph[22][22];
int is_used[22];
int max_num, cur_num, n, m;
void backtrack(int t)
{
    if (t > n)
    {
        max_num = cur_num;
        return;
    }
    int flag = 1;
    for (int i = 1; i < t; i++)
    {
        if (graph[t][i] == 1 && is_used[i] == 1)
        {
            flag = 0; // 不能带上这头牛
            break;
        }
    }
    // 左子树
    if (flag == 1)
    {
        cur_num++;
        if (max_num < cur_num)
        {
            max_num = cur_num;
        }
        is_used[t] = 1;
        backtrack(t + 1);
        cur_num--;
    }
    // 右子树
    if (cur_num + n - t >= max_num)
    {
        is_used[t] = 0;
        backtrack(t + 1);
    }
}

int main(int argc, char const *argv[])
{
    int x, y;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    cur_num = 0;
    max_num = 0;
    backtrack(1);
    printf("%d\n", max_num);
    return 0;
}
