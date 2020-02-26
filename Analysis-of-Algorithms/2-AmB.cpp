#include <stdio.h>
#include <string.h>
int a[40100], b[40100], ans[40100];
int main(int argc, char const *argv[])
{
    char stra[20020] = {'\0'}, strb[20020] = {'\0'};
    scanf("%s", stra);
    scanf("%s", strb);
    int lena, lenb;
    lena = strlen(stra);
    lenb = strlen(strb);
    // 转化为数组
    for (int i = 0; i < lena; i++)
    {
        a[i] = stra[lena - i - 1] - '0';
    }
    for (int i = 0; i < lenb; i++)
    {
        b[i] = strb[lenb - i - 1] - '0';
    }
    // 相乘
    for (int i = 0; i < lena; i++)
    {
        for (int j = 0; j < lenb; j++)
        {
            ans[j + i] += a[i] * b[j];
        }
    }
    // 进位
    for (int i = 0; i < lena + lenb - 1; i++)
    {
        if (ans[i] > 10)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    if (ans[lena + lenb - 1] > 0)
    {
        for (int i = 0; i < lena + lenb; i++)
        {
            printf("%d", ans[lena + lenb - 1 - i]);
        }
    }
    else
    {
        for (int i = 0; i < lena + lenb - 1; i++)
        {
            printf("%d", ans[lena + lenb - 2 - i]);
        }
    }
    printf("\n");
    return 0;
}
