#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, num;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &num);
        if (num % 2 == 0)
        {
            printf("%d\n", (num / 2) * (num / 2 - 1));
        }
        else
        {
            printf("%d\n", (num / 2) * (num / 2 - 1) / 2 + (num / 2 + 1) * (num / 2) / 2);
        }
    }

    return 0;
}
