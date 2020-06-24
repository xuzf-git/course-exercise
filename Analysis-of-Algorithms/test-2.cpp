#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    int d,w;
} data;
data num[10005];
int table[10005]; // 空闲时刻表
int n;

int cmp(const void *a, const void *b)
{
    if (((data *)b)->w > ((data *)a)->w)
        return 1;
    else
        return 0;
}

// 查找是否有空位
int find(int j)
{
    for (int i = j; i >= 0; i--)
    {
        if (table[i] == 0)
        {
            table[i] = 1;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int max_d = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i].d);
        if (num[i].d > max_d)
        {
            max_d = num[i].d;
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i].w);
    }
    if (max_d >= n)
    {
        printf("0\n");
    }
    else
    {
        // 按照惩罚排序
        qsort(num, n, sizeof(data), cmp);
        memset(table, sizeof(table), 0);
        int pos = -1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (num[i].d >= n)
            {
                pos = find(n - 1);
            }
            else
            {
                pos = find(num[i].d - 1);
            }
            if (pos == 0) // 没能完成
            {
                res += num[i].w;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
