#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, num[310], len[310], lpre[310], npre[310];
int dp[310][310][2];
int nsum(int i, int j)
{
    int tmp = (i != 0);
    j = n - j;
    return npre[j] - npre[i - tmp];
}
int lsum(int i, int j)
{
    return lpre[j] - lpre[i];
}
int dfs(int i, int j, int pos)
{
    if (dp[i][j][pos] != inf)
    {
        return dp[i][j][pos];
    }
    if (i + j >= n)
    {
        return dp[i][j][pos] = 0;
    }
    if (pos == 1)
    {
        dp[i][j][1] = min(dp[i][j][1], dfs(i, j + 1, 1) + len[n - (j + 1)] * nsum(i, j + 1));
        dp[i][j][1] = min(dp[i][j][1], dfs(i, j + 1, 0) + (lpre[i] + lsum(n - j, n)) * nsum(i, j + 1));
    }
    else
    {
        dp[i][j][0] = min(dp[i][j][0], dfs(i + 1, j, 0) + len[i] * nsum(i + 1, j));
        dp[i][j][0] = min(dp[i][j][0], dfs(i + 1, j, 1) + (lpre[i] + lsum(n - j, n)) * nsum(i + 1, j));
    }
    return dp[i][j][pos];
}
int main()
{
    while (~scanf("%d", &n))
    {
        if (!n)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &num[i], &len[i]);
        }
        lpre[0] = npre[0] = num[n] = 0;
        for (int i = 1; i <= n; i++)
        {
            lpre[i] = lpre[i - 1] + len[i - 1];
            npre[i] = npre[i - 1] + num[i];
        }
        memset(dp, inf, sizeof(dp));
        int ans = min(dfs(0, 0, 0), dfs(0, 0, 1));
        printf("%d\n", ans);
    }
    return 0;
}