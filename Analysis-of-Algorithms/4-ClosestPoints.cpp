#include <cstdio>
#include <math.h>
#include <algorithm>
#define MAX 100002
#define INF 1e30
using namespace std;
struct Point
{
    double x, y;
} points[MAX];
int selt[MAX];

bool cmp1(const Point &a, const Point &b)
{
    return a.x < b.x;
}

bool cmp2(const int &a, const int &b)
{
    return points[a].y < points[b].y;
}
// 计算两个点之间的距离
double len(const int &a, const int &b)
{
    return sqrt((points[a].x - points[b].x) * (points[a].x - points[b].x) + (points[a].y - points[b].y) * (points[a].y - points[b].y));
}

double Closest(int l, int r)
{
    if (l == r)
        return INF;
    if (l + 1 == r)
        return len(l, r);
    double min;
    int mid = (l + r) / 2;
    /* 计算分隔线同侧点对的最短距离 */
    double leng1 = Closest(l, mid);
    double leng2 = Closest(mid + 1, r);
    leng1 < leng2 ? min = leng1 : min = leng2;
    /* 计算分隔线两侧点对的距离 */
    int j = 0;
    // 找出所有离分隔线的距离小于min的点
    for (int i = l; i <= r; i++)
    {
        if (points[i].x - points[mid].x >= -min && points[i].x - points[mid].x <= min)
        {
            selt[j] = i;
            j++;
        }
    }
    // 把选出来的点，按照y排序
    sort(selt, selt + j, cmp2);
    // 对于y方向的相距小于min的点，测量距离，更新min
    for (int i = 0; i < j; i++)
    {
        for (int k = i + 1; k < j; k++)
        {
            if (points[selt[k]].y - points[selt[i]].y > min)
                break;
            double temp = len(selt[i], selt[k]);
            if (temp < min)
                min = temp;
        }
    }
    return min;
}

int main(int argc, char const *argv[])
{
    int n;
    while (true)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
        sort(points, points + n, cmp1);
        printf("%.2lf\n", Closest(0, n - 1) / 2);
    }
    return 0;
}
/*
2
0 0
1 1
2
1 1
1 1
3
-1.5 0
0 0
0 1.5
0
*/