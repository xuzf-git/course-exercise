// 最长递增子序列 （LIS） DP
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100;
int main(int argc, char const *argv[])
{
    int n, len;
    int l[MAX], num[MAX];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        getchar();
    }
    memset(l, 0, sizeof(l));
    // 最小的尾巴是第一个元素
    l[1] = 1;
    len = 1;
    for (int i = 2; i <= n; i++)
    {
        if (num[i] < num[l[1]]) // 新添加的元素比最小的尾巴小
        {
            l[1] = i; // 最小的尾巴的位置修改为 i
        }
        else if (num[i] > num[l[len]]) // 新添加的元素比最大的尾巴大
        {
            len++; // 修改子序列长度
            l[len] = i; // 添加最大的尾巴
        }
        else
        {
            // 二分查找num[i]的大小区间
            int le = 1, re = len;
            int mid;
            while (true)
            {
                mid = (le + re) >> 1;
                if (le + 1 >= re)
                    break;
                else
                {
                    if (num[l[mid]] > num[i])
                        re = mid;
                    else if (num[l[mid]] == num[i])
                    {
                        le = re = mid;
                        break;
                    }
                    else 
                        le = mid;
                }
            }
            l[le + 1] = i;
        }
    }
    cout << len << endl;
    return 0;
}
