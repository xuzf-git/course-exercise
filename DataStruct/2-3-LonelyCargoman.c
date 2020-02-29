#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100 + 5
#define MAX_Q 100 + 5
#define MAX_S 100 + 5
// 定义节点
int set, n, s, q, total_time;
typedef struct Node
{
    int data;
    struct Node *next;
} node;
// 定义队列
typedef struct Queue
{
    node *front;
    node *tail;
    int length;
} queue;
// 定义栈
typedef struct Stack
{
    node *top;
    int length;
} stack;
// 初始化队列
queue *initQueue()
{
    queue *p = (queue *)malloc(sizeof(queue));
    p->length = 0;
    p->front = NULL;
    p->tail = NULL;
    return p;
}
// 队列插入
void pushQueue(queue *p, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
        return;
    temp->data = data;
    temp->next = NULL;
    if (p->tail == NULL)
    {
        p->front = temp;
        p->tail = temp;
    }
    else
    {
        p->tail->next = temp;
        p->tail = temp;
    }
    p->length++;
}
// 队列删除
void popQueue(queue *p)
{
    node *temp = p->front;
    if (p->front == NULL)
        return;
    else if (p->front == p->tail)
    {
        p->front = NULL;
        p->tail = NULL;
    }
    else
    {
        p->front = p->front->next;
    }
    free(temp);
    p->length--;
}
// 判断队列是否为空
int isEmptyQueue(queue *p)
{
    return p->front == NULL;
}
// 初始化栈
stack *initStack()
{
    stack *p = (stack *)malloc(sizeof(stack));
    p->top = NULL;
    p->length = 0;
    return p;
}
// 栈插入
void pushStack(stack *p, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
        return;
    temp->data = data;
    if (p->top == NULL)
    {
        temp->next = NULL;
        p->top = temp;
    }
    else
    {
        temp->next = p->top;
        p->top = temp;
    }
    p->length++;
}
// 栈删除
void popStack(stack *p)
{
    node *temp = p->top;
    if (p->top == NULL)
        return;
    else
    {
        p->top = p->top->next;
        free(temp);
    }
    p->length--;
}
// 判断栈是否为空
int isEmptyStack(stack *p)
{
    return p->top == NULL;
}
void pack(queue *que, stack *truck)
{
    while (truck->length < s)
    {
        if (isEmptyQueue(que))
        {
            break;
        }
        else
        {
            // printf("#####\n");
            total_time++;
            pushStack(truck, que->front->data);
            popQueue(que);
        }
    }
}
void unpack(queue *que, stack *truck, int station_id)
{
    if (isEmptyStack(truck))
    {
        return;
    }
    while (truck->top->data == station_id + 1)
    {
        total_time++;
        popStack(truck);
        if (isEmptyStack(truck))
        {
            break;
        }
    }
    while (que->length < q)
    {
        if (isEmptyStack(truck))
        {
            break;
        }
        else
        {
            total_time++;
            int temp = truck->top->data;
            if (temp == (station_id + 1))
            {
                popStack(truck);
            }
            else
            {
                pushQueue(que, temp);
                popStack(truck);
            }
        }
    }
    if (isEmptyStack(truck))
    {
        return;
    }
    while (truck->top->data == station_id + 1)
    {
        total_time++;
        popStack(truck);
        if (isEmptyStack(truck))
        {
            break;
        }
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &set);
    while (set--)
    {
        int i, j, num, data, flag1 = 0, flag2 = 0;
        queue *station[MAX_N];
        stack *truck = initStack();
        total_time = 0;
        scanf("%d %d %d", &n, &s, &q);
        for (i = 0; i < n; i++)
        {
            station[i] = initQueue();
            scanf("%d", &num);
            for (j = 0; j < num; j++)
            {
                scanf("%d", &data);
                pushQueue(station[i], data);
            }
            // printf("%d\n", station[i]->length);
        }
        i = 0;
        while (flag1 != n || flag2 != 1)
        {
            unpack(station[i], truck, i);
            pack(station[i], truck);
            total_time += 2;
            flag1 = 0;
            flag2 = isEmptyStack(truck);
            for (j = 0; j < n; j++)
            {
                flag1 += isEmptyQueue(station[j]);
            }
            // printf("%d %d\n", total_time, station[i]->length);
            i++;
            i %= n;
        }
        for (i = 0; i < n; i++)
        {
            while (isEmptyQueue(station[i]) == 0)
            {
                popQueue(station[i]);
            }
            free(station[i]);
        }
        while (isEmptyStack(truck) == 0)
        {
            popStack(truck);
        }
        free(truck);

        printf("%d\n", total_time - 2);
    }

    return 0;
}