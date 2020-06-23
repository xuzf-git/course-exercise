// 矩阵连乘问题(动态规划)
#include <iostream>
#define INF (2 << 31) - 1
#define MAX 110
using namespace std;
int m[MAX][MAX];
int q[MAX];
int s[MAX][MAX]; // 记录 i 到 j 的分隔点
// 打印矩阵连乘计算策略
void printPath(int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printPath(i, s[i][j]);
        printPath(s[i][j] + 1, j);
        cout << ")";
    }
}
int main(int argc, char const *argv[])
{
    int n, i, j, k, d;
    cin >> n;
    for (i = 0; i <= n; i++)
        cin >> q[i];
    // 初始化规划量列表
    for (i = 0; i <= n; i++)
        m[i][i] = 0;
    // 动态规划，自底向上
    for (d = 1; d < n; d++)  // d 为步长
    {
        for (i = 1; i <= n - d; i++)  // 计算 A[i, j] 最低代价 
        {
            j = i + d;
            m[i][j] = m[i][i] + m[i + 1][j] + q[i - 1] * q[i] * q[j];
            s[i][j] = i;
            for (k = i + 1; k < j; k++)
            {
                int temp = m[i][k] + m[k + 1][j] + q[i - 1] * q[k] * q[j];
                if (temp < m[i][j]) 
                {
                    m[i][j] = temp;
                    s[i][j] = k;                
                }
            }
        }
    }
    cout << m[1][n] << endl; 
    if (m[i][n] == 0)
    {
        cout << "(A1)" << endl; 
    }
    else
    {
        printPath(1, n);
        cout << endl;
    }
    return 0;
}
