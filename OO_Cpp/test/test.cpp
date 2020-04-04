#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000010;
int in[MAX], out[MAX];
bool cmp(const int& a, const int& b)
{
    return a < b;
}
int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i] >> out[i];
    }
    sort(in, in + n, cmp);
    sort(out, out + n, cmp);
    int i = 0, j = 0, current = 0, max = 0;
    while (i < n)
    {
        if (in[i] >= out[j])
        {
            current--;
            j++;
        }
        current++;
        i++;
        if (max < current)
        {
            max = current;
        }
    }
    cout << max << endl;
    return 0;
}
