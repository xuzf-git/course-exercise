#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        int tmp = b;
        b = a % b;
        a = tmp;
        return gcd(a, b);
    }
}

long long pow(int m, int n)
{
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= m;
    }
    return res;
}

long long polya(int c, int s)
{
    long long count = 0;
    for (int i = 1; i <= s; i++)
    {
        count += pow(c, gcd(s, i));
    }
    if (s % 2 == 1)
    {
        count += s * pow(c, (s + 1) / 2);
    }
    else
    {
        count += (pow(c, s / 2 + 1) + pow(c, s / 2)) * s / 2;
    }
    count = (count / 2) / s;
    return count;
}

int main()
{
    int c = 1, s = 1;
    while (true)
    {
        scanf("%d%d", &c, &s);
        if (c == 0 && s == 0)
        {
            break;
        }
        printf("%lld\n", polya(c, s));
    }
    return 0;
}