#include <stdio.h>
#include <stdlib.h>
typedef struct data
{
    int w, h, g;
    int linju[501];
}data;
data num[510];
int max_h, cur_h, n;
int last;
int cmp(const void*a, const void *b)
{
    if (((data*)a)->w  < ((data*)b)->w)
        return 0;
    else
        return 1;
}

// 回溯
void backtrack(int t)
{
    if (t >= n)
    {
        if (cur_h > max_h)
        {
            max_h = cur_h;
        }
        return;
    }
    int pre_last = last;
    if (num[last].linju[t] == 1)
    {
        cur_h = cur_h - num[last].g + num[t].h + num[t].g;
        last = t;
        if (cur_h > max_h)
        {
            max_h = cur_h;
        }
        backtrack(t+1);
        last = pre_last;
        cur_h = cur_h + num[last].g - num[t].h - num[t].g;
    }
    backtrack(t+1);
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &num[i].w, &num[i].h, &num[i].g);
            int k = 0, tmp;
            scanf("%d", &k);
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &tmp);
                num[i].linju[tmp-1] = 1;
                num[tmp-1].linju[i] = 1;
            }
        }
        // 按照翅膀宽度从小到大排序
        qsort(num, n, sizeof(data), cmp);
        for (int i = 0; i < n - 1; i++)
        {
            cur_h = num[i].g + num[i].h;
            last = i;
            backtrack(i + 1);
        }
        printf("%d\n", max_h);
    }
    return 0;
}
