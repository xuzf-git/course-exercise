// 最大子段和 (MS) DP
/*
    输入: 实数序列(x1,x2,…,xn) 
    输出: 有最大和的子段 (xi, xi+1,…,xj) 
    样例输入: (1, −3, 4, −1, 2, 1, −5, 4) 
    样例输出: (4, -1, 2, 1)

*/
#include <iostream>
using namespace std;
int num[110];
// 枚举法
void MS_Enumeration(int* num, int n)
{
    int start = 0, end = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int temp = 0;
            for (int k = i; k <= j; k++)
                temp += num[k];

            if (temp > max)
            {
                max = temp;
                start = i;
                end = j;
            }
        }
    }
    for (int i = start; i < end; i++)
    {
        cout << num[i] << " ";
    }
    cout << num[end] << endl;
}
// DP
void MS_dp(int *num, int n)
{
    int sum = 0, tms = 0, start, end;
    for(int i = 0; i < n; i++)
    {
        tms += num[i];
        if (tms < 0)        
        {
            start = i + 1;  // 记录字子段开头
            tms = 0;        // 如果结果为 0.从下一个位置开始 
        }
        if (tms > sum)      
        {
            end = i;        // 记录子段结尾
            sum = tms;      // 更新最大值
        }
        for (int i = start; i < end; i++)
        {
            cout << num[i] << ' '; 
        }
        cout << num[end] << endl;
    }
}
int main(int argc, char const *argv[])
{
    int n, flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        if (num[i] > 0 && flag == 0)
            flag = 1;
    }
    if (flag == 0)
    {
        cout << endl;
    }
    else
    {
        MS_Enumeration(num, n);
    }
    return 0;
}
