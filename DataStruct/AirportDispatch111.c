#include <stdio.h>
#define MAX_QUEUE_SIZE 5000 + 10
typedef struct queue
{
    int queue_list[MAX_QUEUE_SIZE];
    int head;
    int tail;
} queue;
typedef struct way
{
    int time;
    int plane_id;
    int total_time;
} way;
queue load_queue, fly_queue;
int num_runway, load_time, fly_time;
queue init_queue()
{
    queue q;
    q.head = 0;
    q.tail = 0;
    return q;
}
int queue_empty(queue *q)
{
    if (q->head == q->tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(queue *q, int num)
{
    q->queue_list[q->tail] = num;
    q->tail++;
}
int pop(queue *q)
{
    int temp = q->queue_list[q->head];
    q->head++;
    return temp;
}
int length(queue *q)
{
    if (queue_empty(q) == 0)
    {
        return (q->tail - q->head);
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &num_runway, &load_time, &fly_time);

    int cur_time = 0, fly_id = 0, load_id = 5000;
    way runway[num_runway];
    fly_queue = init_queue();
    load_queue = init_queue();
    int total_fly = 0, total_load = 0;
    int load_requ = 0, fly_requ = 0, j = 0, i = 0, len = 0;
    int flag1 = 0, flag2 = 0, flag3 = 0;

    do
    {
        j = 0;
        flag1 = 0;
        flag2 = 0;
        flag3 = 0;
        printf("Current Time: %4d\n", cur_time);
        cur_time++;
        int free[100] = {0};
        // 更新跑道状态
        for (i = 0; i < num_runway; i++)
        {
            if (runway[i].plane_id == 0)
            {
                free[j] = i;
                j++;
            }
            else if ((runway[i].plane_id > 5000 && runway[i].time == load_time) ||
                     (runway[i].plane_id < 5000 && runway[i].time == fly_time))
            {
                free[j] = i;
                j++;
                runway[i].plane_id = 0;
                printf("runway %02d is free\n", i + 1);
            }
            else
            {
                runway[i].total_time++;
                runway[i].time++;
            }
        }
        if (load_requ > -1 || fly_requ > -1)
        {
            // 输入新的请求
            scanf("%d %d", &load_requ, &fly_requ);
            // 存入飞机发出的请求
            for (i = 1; i <= load_requ; i++)
            {
                load_id++;
                push(&load_queue, load_id);
            }
            for (i = 1; i <= fly_requ; i++)
            {
                fly_id++;
                push(&fly_queue, fly_id);
            }
            flag1 = 1;
        }
        // 输出可以降落的飞机方案
        len = j;
        while (j > 0)
        {
            if (queue_empty(&load_queue) == 0)
            {
                int m = pop(&load_queue), n = free[len - j];
                runway[n].plane_id = m;
                runway[n].time = 1;
                printf("airplane %04d is ready to land on runway %02d\n", m, n + 1);
                j--;
            }
            else
            {
                flag2 = 1;
                break;
            }
            total_load += length(&load_queue);
        }
        // 输出可以起飞的飞机方案
        while (j > 0)
        {
            if (queue_empty(&fly_queue) == 0)
            {
                int m = pop(&fly_queue), n = free[len - j];
                runway[n].plane_id = m;
                runway[n].time = 1;
                printf("airplane %04d is ready to takeoff on runway %02d\n", m, n + 1);
                j--;
            }
            else
            {
                flag3 = 1;
                break;
            }
            total_fly += length(&fly_queue);
        }
    } while (flag1 == 1 || flag2 == 0 || flag3 == 0 || j != num_runway);
    printf("simulation finished\n");
    printf("simulation time:%4d\n", --cur_time);
    float ave_load, ave_fly, ave_way = 0;
    ave_load = (float)total_load / (load_id - 5000);
    ave_fly = (float)total_fly / (fly_id);
    printf("%d\n", total_load);
    printf("%d\n", total_fly);
    printf("average waiting time of landing:%4.1f\n", ave_load);
    printf("average waiting time of takeoff:%4.1f\n", ave_fly);
    for (i = 0; i < num_runway; i++)
    {
        printf("runway %02d busy time:%4d\n", runway[i].total_time);
        ave_way += runway[i].total_time;
    }
    //	ave_way =
    //	printf("runway average busy time percentage:%4.1f", )
    return 0;
}
