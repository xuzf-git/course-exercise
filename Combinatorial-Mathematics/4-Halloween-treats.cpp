#include <stdio.h>
#include <string.h>
#define MAX 100010
int sum[MAX], exist[MAX];
int main(int argc, char const *argv[])
{
    int c, n;
    while (1)
    {
        scanf("%d %d", &c, &n);
        if (c == 0 && n == 0)
            break;

        memset(exist, 0, sizeof(exist)); // exist[i] 用于存储余数为 i 的s[]的索引
        exist[0] = 1;

        int temp;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &temp);
            sum[i] = (sum[i - 1] + temp) % c;
        }
        int flag;
        for (int i = 1; i <= n; i++)
        {
            if (exist[sum[i]] > 0)
            {
                flag = i;
                break;
            }
            else
            {
                exist[sum[i]] = i + 1;
            }
        }
        for (int i = exist[sum[flag]]; i < flag; i++)
        {
            printf("%d ", i);
        }
        printf("%d\n", flag);
    }
    return 0;
}
