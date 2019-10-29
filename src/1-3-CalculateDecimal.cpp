/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void output(NODE *);
void change(int, int, NODE *);

void output(NODE *head)
{
    int k = 0;

    printf("0.");
    while (head->next != NULL && k < 50)
    {
        printf("%d", head->next->data);
        head = head->next;
        k++;
    }
    printf("\n");
}

int main()
{
    int n, m;
    NODE *head;

    scanf("%d%d", &n, &m);
    head = (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;
    change(n, m, head);
    output(head);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void change(int n, int m, NODE *head)
{
    NODE *point = head;
    int num[55] = {0};
    int item = n, begin = 0, end = 0, flag = 0;
    for (int i = 0; i < 55; i++)
    {
        item *= 10;
        num[i] = item / m;
        item = item % m;
        if (item == 0)
        {
            flag = 1;
            end = i + 1;
            break;
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (num[j] == num[i])
                {
                    begin = j;
                    end = i;
                    break;
                }
            }
        }
    }
    NODE *p = head;
    for (int i = 0; i < end; i++)
    {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = num[i];
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
    if (flag == 0)
    {
        NODE *p_circle = head;
        for (int i = 0; i < begin; i++)
        {
            p_circle = p_circle->next;
        }
        p->next = p_circle;
    }
}