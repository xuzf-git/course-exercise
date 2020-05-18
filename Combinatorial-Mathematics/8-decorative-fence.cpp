#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 21
long long dp[MAX][MAX][2];
int res[MAX];
int flag[MAX];

void calcu(int n, long long c)
{
    long long move = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j <= n; j++)
        {
            move = 0;
            if (flag[j] == 0)
            {
                k++;
                if (i == 1)
                {
                    move = dp[n][k][0] + dp[n][k][1];
                }
                else
                {
                    if (res[i - 1] < j && (i <= 2 || res[i - 2] > res[i - 1]))
                        move = dp[n - i + 1][k][1];
                    else if (res[i - 1] > j && (i <= 2 || res[i - 2] < res[i - 1]))
                        move = dp[n - i + 1][k][0];
                }
                if (move >= c)
                {
                    flag[j] = true;
                    res[i] = j;
                    break;
                }
                else
                    c -= move;
            }
        }
    }
}

int main()
{
    memset(dp, 0, sizeof(dp));
    dp[1][1][0] = dp[1][1][1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            for (int m = j; m < i; m++)
                dp[i][j][0] += dp[i - 1][m][1];
            for (int n = 1; n < j; n++)
                dp[i][j][1] += dp[i - 1][n][0];
        }
    }

    int num;
    scanf("%d", &num);
    while (num--)
    {
        memset(res, 0, sizeof(res));
        memset(flag, 0, sizeof(flag));
        int n;
        long long c;
        scanf("%d %lld", &n, &c);
        calcu(n, c);
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", res[i]);
        }
        printf("\n");
    }
    return 0;
}