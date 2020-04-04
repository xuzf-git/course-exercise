#include <iostream>
#define MAX 10010
using namespace std;
int c[MAX];
int y[MAX];
int main(int argc, char const *argv[])
{
    int n, s;
    long long int cost = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> y[i];
    }
    // 找出每周的最低成本
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        int min_c = c[flag] + s * (i - flag);
        for (int j = flag + 1; j <= i; j++)
        {
            int tmp = c[j] + s * (i - j);
            if (tmp < min_c)
            {
                min_c = tmp;
                flag = j;
            }
        }
        cost += y[i] * min_c;
    }
    cout << cost << endl;
    return 0;
}
