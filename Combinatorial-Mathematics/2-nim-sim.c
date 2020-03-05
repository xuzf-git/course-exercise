#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, num;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &num);
        printf("%d\n", (num - 1) % 3);
    }
    return 0;
}
