#include <iostream>
using namespace std;
int num[110];
int main(int argc, char const *argv[])
{
    int n, flag = 0, start = 0, end = 0, max = 0;
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
    return 0;
}
