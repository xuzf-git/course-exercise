#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 30;
int n, h;
int f[MAX], d[MAX], t[MAX];
int main(int argc, char const *argv[])
{
    int flag = 0;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        if (flag == 1)
        {
            cout << "\n";
        }
        flag = 1;
        int maxnum = 0;
        int plan[MAX] = {0};
        cin >> h;
        h = (h * 60) / 5;
        for (int i = 0; i < n; i++)
            cin >> f[i];
        for (int i = 0; i < n; i++)
            cin >> d[i];
        for (int i = 0; i < n - 1; i++)
            cin >> t[i];

        // 假设最终停留在第 last 个点
        for (int last = 0; last < n; last++)
        {
            int remain = h; // 剩余的时间
            int best = 0, best_id, num = 0;
            int times[MAX] = {0}; // 每个池塘钓鱼的次数
            int fish[MAX];  // 每个池塘这次能钓多少鱼
            // 除去转移用的时间
            for (int i = 0; i < last; i++)
            {
                remain -= t[i];
            }
            // 钓鱼
            while (remain > 0)
            {
                best = 0;
                // 找出本次最好的选择（贪心选择）
                for (int i = 0; i <= last; i++)
                {
                    int tmp = f[i] - d[i] * times[i];
                    if (tmp > 0)
                        fish[i] = tmp;
                    else
                        fish[i] = 0;
                    if (fish[i] > best)
                    {
                        best = fish[i];
                        best_id = i;
                    }
                }
                if (best == 0)
                    break;
                else
                {
                    remain--;
                    num += best;
                    times[best_id]++;
                }
            }
            if (num > maxnum)
            {
                maxnum = num;
                for (int i = 0; i < n; i++)
                {
                    plan[i] = times[i];
                }
                plan[0] += remain;
            }
            
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << plan[i] * 5 << ", ";
        }
        cout << plan[n - 1]  * 5 << endl;
        cout << "Number of fish expected: " << maxnum <<endl;
        
    }
    return 0;
}