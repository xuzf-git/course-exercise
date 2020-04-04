#include <iostream>
#include <cstdio>
#include <cmath>
#define ex 1e-5
using namespace std;
typedef long long ll;
struct location
{
    int x;
    int y;
} point[155], circle[105];
int dp[155][155];
int available[155][155];
int n, g, r;
double r_sq;

double dis_sq(double ax, double ay, double bx, double by)
{
    return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

int judge(const int i, const int j)
{
    for (int k = 0; k < g; k++)
    {
        double ax = (double)point[i].x;
        double ay = (double)point[i].y;
        double bx = (double)point[j].x;
        double by = (double)point[j].y;
        double cx = (double)circle[k].x;
        double cy = (double)circle[k].y;

        double lik_sq = dis_sq(ax, ay, cx, cy);
        double ljk_sq = dis_sq(bx, by, cx, cy);
        double lij_sq = dis_sq(ax, ay, bx, by);

        if (lik_sq - r_sq <= ex|| ljk_sq - r_sq <= ex)
            return 0;

        double tmp = (cx - ax) * (cy - by) - (cx - bx) * (cy - ay);
        if (lij_sq * r_sq >= tmp * tmp)
        {
            if (ljk_sq + lij_sq - lik_sq >= ex && lik_sq + lij_sq - ljk_sq >= ex)
                return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    cin >> n >> g >> r;
    r_sq = (double)r * r;
    for (int i = 0; i < n; i++)
        cin >> point[i].x >> point[i].y;
    for (int i = 0; i < g; i++)
        cin >> circle[i].x >> circle[i].y;
    // 标记可用点对
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            available[i][j] = judge(i, j);
        }
    }
    // 0 和 n-1 相邻
    available[0][n - 1] = 0;
    // 动态规划
    for (int step = 2; step < n; step++)
    {
        for (int i = 0; i < n - step; i++)
        {
            int j = i + step;
            dp[i][j] = dp[i][i + 1] + dp[i + 1][j];
            for (int k = i + 2; k < j; k++)
            {
                int max = dp[i][k] + dp[k][j];
                if (max > dp[i][j])
                {
                    dp[i][j] = max;
                }
            }
            dp[i][j] += available[i][j];
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;

}

