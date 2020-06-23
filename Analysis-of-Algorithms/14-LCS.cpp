// 最长公共子序列 LCS DP
/*
    输入: 字符串 X = x1x2…xn, Y = y1y2…ym, 
    输出: X 和 Y最长的公共子序列 (LCS) 
    样例: X=ABCBDAB, Y=BDCABA, 输出: BCAB 
    - 子结构：Xi = x[1:i]; Yj = y[1:j]
    - 状态：dp[i][j] 表示 Xi和 Y[j] 的最长公共子序列长度
    - 转移方程：
    - - dp[i][j] = 
            0                              i = 0 or j = 0
            dp[i-1][j-1] + 1               i,j > 0 and x[i] = y[j]
            max{dp[i-1][j], dp[i][j-1]}    i,j > 0 and x[i]1 = y[j]
*/
#include <cstdio>
#include <iostream>
using namespace std;
// DP 求解最长公共子序长度
int LCSleng(int n, int m, char *x, char *y)
{
    // 定义未知大小的 dp 数组
    int **dp = new int*[n];
    for(int i = 0; i < n; i++)
    {
        dp[i] = new int[m];
    }
    // 数组初始化：
    for(int i = 0; i < n; i++)
        dp[i][0] = 0;
    for(int i = 0; i < m; i++)
        dp[0][m] = 0;
    // 自底向上更新决策数组
    for(int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (x[i] == y[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else if (dp[i-1][j] > dp[1][j-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}
// 空间优化版 LCS (滚动数组)
int LCSleng_optim(int n, int m, char *x, char *y)
{
    int **dp = new int*[2];
    dp[0] = new int[m];  // cur dp[i][0:m]
    dp[1] = new int[m];  // pre dp[i-1][0:m]
    // 初始化
    for(int i = 0; i < m; i++)
    {
        dp[1][i] = 0;
    }
    // 更新dp
    int cur = 0, pre = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if (x[i] == y[j])
            {
                dp[cur][j] = dp[pre][j-1] + 1;
            }
            else if (dp[pre][j] > dp[cur][j-1])
            {
                dp[cur][j] = dp[pre][j];
            }
        }
        int tmp = cur;
        cur = pre;
        pre = cur;
    }
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    char *x = new char[n], *y = new char[m];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < m; i++)
        cin >> y[i];

    // 输出最长公共子序列长度
    cout << LCSleng(n, m, x, y) << endl;
    cout << LCSleng_optim(n, m, x, y) << endl;
    // return 0;
}
