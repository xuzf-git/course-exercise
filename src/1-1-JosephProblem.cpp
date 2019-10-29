#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *make_list(int n)
{
    struct node *head = NULL, *new_one = NULL, *tail = NULL;
    for (int i = 1; i <= n; i++)
    {
        new_one = (struct node *)malloc(sizeof(struct node));
        new_one->data = i;
        if (head == NULL)
        {
            head = new_one;
            tail = new_one;
        }
        else
        {
            tail->next = new_one;
            // new_one -> next = NULL;
            tail = new_one;
        }
    }
    tail->next = head;
    return head;
}
void free_node(int k, int m, struct node *head)
{
    struct node *p1 = head, *p2 = head, *temp = head;
    int count = 0;
    k--;
    p1 = p1->next;
    while (--k)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1->next != p1)
    {
        for (int i = 1; i < m; i++)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (count < 9)
        {
            printf("%d ", p1->data);
            count++;
        }
        else if (count == 9)
        {
            printf("%d\n", p1->data);
            count++;
        }
        else
        {
            printf("%d ", p1->data);
            count -= 10;
            count++;
        }
        temp = p1;
        p1 = p1->next;
        p2->next = p1;
        free(temp);
    }
    if (count < 10)
    {
        printf("%d", p1->data);
        count++;
    }
    else
    {
        printf("\n%d ", p1->data);
        count -= 10;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int n, k, m;
    scanf("%d,%d,%d", &n, &k, &m);
    if (n < 1 || k < 1 || m < 1)
    {
        printf("n,m,k must bigger than 0.\n");
    }
    else if (k > n)
    {
        printf("k should not bigger than n.\n");
    }
    else
    {
        struct node *head = NULL;
        head = make_list(n);
        free_node(k, m, head);
    }
    return 0;
}
