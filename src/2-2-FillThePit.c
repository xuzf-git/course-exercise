#include <stdio.h>
#include<stdlib.h>
#define MAX_N 100000 + 5
#define Max_H 1000000 + 5
#define MAX_W 1000
typedef struct hole
{
    int h, w, number;
    struct hole *next;
    struct hole *pre;
} shole, *phole;

long long time[MAX_N];

int main(int argc, char const *argv[])
{
    int n, w, h;
    long long sum_time = 0;
    phole ledge, redge, p1, p2, min;
    // 初始化一个双向链表
    ledge = (phole)malloc(sizeof(shole));
    ledge->h = Max_H;
    ledge->w = 0;
    ledge->next = NULL;
    ledge->pre = NULL;
    p2 = ledge;
    min = ledge;
    scanf("%d", &n);
    // 存储数据并得到最低点的位置
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w, &h);
        p1 = (phole)malloc(sizeof(shole));
        p1->h = h;
        p1->w = w;
        p1->number = i;
        p1->pre = p2;
        p2->next = p1;
        p1->next = NULL;
        p2 = p1;
        if (p1->h < min->h)
        {
            min = p1;
        }
    }
    redge = (phole)malloc(sizeof(shole));
    redge->h = Max_H;
    redge->w = 0;
    redge->next = NULL;
    p1->next = redge;
    redge->pre = p1;
    // 计算每个平面地用时
    p1 = min;
    while (p1->next->h != p1->pre->h)
    {
        time[p1->number] = sum_time + p1->w;
        if (p1->pre->h > p1->next->h)
        {
            sum_time += (p1->w) * (p1->next->h - p1->h);
            p1->next->w += p1->w;
            p1->next->pre = p1->pre;
            p1->pre->next = p1->next;
            p2 = p1;
            p1 = p1->next;
            free(p2);
        }
        else
        {
            sum_time += (p1->w) * (p1->pre->h - p1->h);
            p1->pre->w += p1->w;
            p1->next->pre = p1->pre;
            p1->pre->next = p1->next;
            p2 = p1;
            p1 = p1->pre;
            free(p2);
        }
        // 找到下一个存水的位置
        while(p1->pre->h < p1->h || p1->pre->h == p1->h)
        {
            p1 = p1->pre;
        }
        while(p1->next->h < p1->h || p1->next->h == p1->h)
        {
            p1 = p1->next;
        }
    }
    time[p1->number] = sum_time + p1->w;
    for (int i = 0; i < n; i++)
    {
        printf("%lld\n", time[i]);
    }
    return 0;
}
