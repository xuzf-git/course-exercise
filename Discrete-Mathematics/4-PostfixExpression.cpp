#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
int calcu(int &a, int &b, char &op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return b - a;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if (a == 0)
        {
            printf("DIV0!\n");
            exit(0);
        }
        return b / a;
        break;
    default:
        return 0;
    }
}
int main(int argc, char const *argv[])
{
    stack<int> num;
    char ch;
    while ((ch = getchar()) && ch != '\n')
    {
        if (ch >= '0' && ch <= '9')
        {
            num.push(ch - '0');
        }
        else
        {
            if (num.empty())
            {
                printf("ERROR!\n");
                exit(0);
            }
            int a = num.top();
            num.pop();
            if (num.empty())
            {
                printf("ERROR!\n");
                exit(0);
            }
            int b = num.top();
            num.pop();
            num.push(calcu(a, b, ch));
        }
    }
    int result = num.top();
    num.pop();
    if (num.empty())
    {
        printf("%d\n", result);
    }
    else
    {
        printf("ERROR!\n");
    }
    return 0;
}
