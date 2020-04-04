#include <iostream>
#define MAX 32
using namespace std;
int pnum[MAX];
int CalcuNum(const int n)
{
    if (n % 2 == 1)
        return 0;
    if (pnum[n] != 0)
        return pnum[n];
    else
    {
        pnum[n - 2] = CalcuNum(n - 2);
        pnum[n - 4] = CalcuNum(n - 4);
        pnum[n] = 4 * pnum[n - 2] - pnum[n - 4];
        return pnum[n];
    }
}
int main(int argc, char const *argv[])
{
    int n;
    pnum[0] = 1;
    pnum[2] = 3;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        cout << CalcuNum(n) << endl;
    }
    return 0;
}
