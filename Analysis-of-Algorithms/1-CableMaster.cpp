#include <stdio.h>
#include <math.h>
#define MAX 10010
#define acc 1e-4
double leni[MAX];
int n, k;
int check(double x)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (int)(leni[i] / x);
    }
    if (ans >= k)
        return 1; // 能够切出该长度
    else
        return 0; // 不能切出该长度
}
int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &k);
    double low = 0, high = 0;
    // 存储数据，找出长度上界
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &leni[i]);
        if (high < leni[i])
        {
            high = leni[i];
        }
    }
    // 二分迭代得出结果
    double mid;
    while (high - low >= acc)
    {
        mid = (high + low) / 2;
        if (check(mid) == 1)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    printf("%.2lf\n", floor(high * 100) / 100);
    return 0;
}
