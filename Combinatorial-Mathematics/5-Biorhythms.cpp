#include <stdio.h>
int main(int argc, char const *argv[])
{
    int p, e, i, d, count = 1;
    while (1)
    {
        scanf("%d %d %d %d", &p, &e, &i, &d);
        if (p == -1 && e == -1 && i == -1 && d == -1)
            break;
        p %= 23, e %= 28, i %= 33; 
        for (int j = d + 1; j <= d + 21253; j++)
        {
            if ((j - p) % 23 == 0 && (j - e) % 28 == 0 && (j - i) % 33 == 0)
            {
                printf("Case %d: the next triple peak occurs in %d days.\n", count, j - d);
                break;
            }
        }
        count++;
    }
    return 0;
}


// 注意特殊测试数据
// 24 29 34 0 1
// 24 29 34 1 21252
// 24 29 34 2 21251
// 0 0 0 0 21252