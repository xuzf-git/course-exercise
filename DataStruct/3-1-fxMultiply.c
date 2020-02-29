/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coef, exp;
    struct node *next;
} NODE;

void multiplication(NODE *, NODE *, NODE *);
void input(NODE *);
void output(NODE *);

void input(NODE *head)
{
    int flag, sign, sum, x;
    char c;

    NODE *p = head;

    while ((c = getchar()) != '\n')
    {
        if (c == '<')
        {
            sum = 0;
            sign = 1;
            flag = 1;
        }
        else if (c == '-')
            sign = -1;
        else if (c >= '0' && c <= '9')
        {
            sum = sum * 10 + c - '0';
        }
        else if (c == ',')
        {
            if (flag == 1)
            {
                x = sign * sum;
                sum = 0;
                flag = 2;
                sign = 1;
            }
        }
        else if (c == '>')
        {
            p->next = (NODE *)malloc(sizeof(NODE));
            p->next->coef = x;
            p->next->exp = sign * sum;
            p = p->next;
            p->next = NULL;
            flag = 0;
        }
    }
}

void output(NODE *head)
{
    while (head->next != NULL)
    {
        head = head->next;
        printf("<%d,%d>,", head->coef, head->exp);
    }
    printf("\n");
}

void multiplication(NODE *h1, NODE *h2, NODE *h3)
{
    NODE *i, *j, *k;
    for (i = h1->next; i != NULL; i = i->next)
    {
        k = h3;
        for (j = h2->next; j != NULL; j = j->next)
        {
            int sum_coef = 0, sum_exp = 0;
            sum_coef = (i->coef) * (j->coef);
            sum_exp = i->exp + j->exp;
            if (sum_coef == 0)
            {
                continue;
            }
            while (k != NULL)
            {
                if (k->next == NULL)
                {
                    NODE *p = (NODE *)malloc(sizeof(NODE));
                    p->exp = sum_exp;
                    p->coef = sum_coef;
                    p->next = NULL;
                    k->next = p;
                    k = p;
                    break;
                }
                else if (sum_exp < k->next->exp)
                {
                    NODE *p = (NODE *)malloc(sizeof(NODE));
                    p->exp = sum_exp;
                    p->coef = sum_coef;
                    p->next = k->next;
                    k->next = p;
                    k = p;
                    break;
                }
                else if (sum_exp == k->next->exp)
                {
                    k->next->coef += sum_coef;
                    if (k->next->coef == 0)
                    {
                        NODE *temp = k->next;
                        k->next = k->next->next;
                        free(temp);
                    }
                    break;
                }
                else
                {
                    k = k->next;
                }
            }
        }
    }
    if (h3->next == NULL)
    {
        NODE *p = (NODE *)malloc(sizeof(NODE));
        p->coef = 0;
        p->exp = 0;
        p->next = NULL;
        h3->next = p;
    }
}

int main()
{
    NODE *head1, *head2, *head3;

    head1 = (NODE *)malloc(sizeof(NODE));
    input(head1);

    head2 = (NODE *)malloc(sizeof(NODE));
    input(head2);

    head3 = (NODE *)malloc(sizeof(NODE));
    head3->next = NULL;
    multiplication(head1, head2, head3);

    output(head3);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

// <1,0>,<-1,1>,<-1,2>,
// <1,0>,<-1,1>,
