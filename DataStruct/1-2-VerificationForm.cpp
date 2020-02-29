#include <stdio.h>
#include <string.h>
struct stu
{
    int num;
    char name[15];
};
int main(int argc, char const *argv[])
{
    int len1 = 0, len2 = 0;
    scanf("%d", &len1);
    struct stu list1[len1];
    for (int i = 0; i < len1; i++)
    {
        scanf("%d", &list1[i].num);
        scanf("%s", list1[i].name);
    }
    scanf("%d", &len2);
    if (len2 == 0)
    {
        printf("the LIST2 is NULL.\n");
    }
    else
    {
        int flag1 = 0, num;
        char name[15] = {'\0'};
        for (int i = 0; i < len2; i++)
        {
            scanf("%d", &num);
            scanf("%s", name);
            int flag2 = 0;
            for (int j = 0; j < len1; j++)
            {
                if (strcmp(name, list1[j].name) == 0 && num == list1[j].num)
                {
                    flag2 = 1;
                    break;
                }
            }
            if (flag2 == 0)
            {
                printf("%8d %s is not in LIST1.\n", num, name);
                flag1 = 1;
            }
        }
        if (flag1 == 0)
        {
            printf("the records of LIST2 are all in the LIST1.\n");
        }
    }
    return 0;
}
