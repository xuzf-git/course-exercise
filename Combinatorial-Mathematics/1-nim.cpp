#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    int num[1010];
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        int c = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            c ^= num[i];
        }
        if (c == 0)
        {
            printf("0\n");
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if ((c ^ num[i]) < num[i])
                {
                    res++;
                }
            }
            printf("%d\n", res);
        }
    }
    return 0; 
}
// 03178126181 \3740016