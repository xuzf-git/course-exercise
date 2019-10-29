#include <stdio.h>
#include <stdlib.h>
#define MAX_STOCK 100
typedef struct Node
{
    int num;
    int op_id;
    int stock_id;
    float price;
    struct Node *next;
} NODE;

int items_num;
NODE *buy, *sell;
// 进行交易
void judgeSale(NODE *p, char b_or_s)
{
    NODE *pbuy = buy;
    NODE *psell = sell;
    if (b_or_s == 'b')
    {
        int flag = 0;
        while (psell->next != NULL)
        {
            if (psell->next->stock_id != p->stock_id)
            {
                if (flag == 1) // 买家想买的股票已经卖完了
                {
                    return;
                }
                psell = psell->next;
                continue;
            }
            else
            {
                flag = 1;
                if (psell->next->price > p->price) // 售价已经大于该卖家的出价
                {
                    return;
                }
                else
                {
                    float sale_price = (psell->next->price + p->price) / 2.0;
                    if (p->num < psell->next->num || p->num == psell->next->num) // 买家要的数量比卖家少
                    {
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",
                               sale_price, p->num, p->op_id, psell->next->op_id);
                        psell->next->num = psell->next->num - p->num;
                        p->num = 0;
                        if (psell->next->num == 0)
                        {
                            NODE *temp = psell->next;
                            psell->next = psell->next->next;
                            free(temp);
                        }
                        return;
                    }
                    else
                    {
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",
                               sale_price, psell->next->num, p->op_id, psell->next->op_id);
                        p->num = p->num - psell->next->num;
                        NODE *temp = psell->next;
                        psell->next = psell->next->next;
                        free(temp);
                    }
                }
            }
        }
    }
    else if (b_or_s == 's')
    {
        int flag = 0;
        while (pbuy->next != NULL && p->num > 0)
        {
            if (pbuy->next->stock_id != p->stock_id)
            {
                if (flag == 1) // 没人再要买卖家的股票了
                {
                    return;
                }
                pbuy = pbuy->next;
                continue;
            }
            else
            {
                flag = 1;
                if (pbuy->next->price < p->price)
                {
                    return ;
                }
                else
                {
                    float sale_price = (pbuy->next->price + p->price) / 2;
                    if (pbuy->next->num > p->num || pbuy->next->num == p->num)
                    {
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",
                               sale_price, p->num, p->op_id, pbuy->next->op_id);
                        pbuy->next->num = pbuy->next->num - p->num;
                        p->num = 0;
                        if (pbuy->next->num == 0)
                        {
                            NODE *temp = pbuy->next;
                            pbuy->next = pbuy->next->next;
                            free(temp);
                        }
                        return;
                    }
                    else
                    {
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",
                               sale_price, pbuy->next->num, p->op_id, pbuy->next->op_id);
                        p->num = p->num - pbuy->next->num;
                        NODE *temp = pbuy->next;
                        pbuy->next = pbuy->next->next;
                        free(temp);
                    }
                }
            }
        }
    }
}
// 委托申请
void addRequest(int op_id, int stock_id, double price, int num, char b_or_s)
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->op_id = op_id;
    p->stock_id = stock_id;
    p->price = price;
    p->num = num;
    p->next = NULL;
    printf("orderid: %04d\n", op_id);
    judgeSale(p, b_or_s);
    if (p->num == 0)
    {
        return;
    }
    if (b_or_s == 'b')
    {
        NODE *pbuy = buy;
        if (pbuy->next == NULL) // 队列为空的情况
        {
            pbuy->next = p;
        }
        else
        {
            int flag = 0;
            while (pbuy->next != NULL)
            {
                if (pbuy->next->stock_id != stock_id)
                {
                    if (flag == 1) // 这次插入的买委托是目前为止出价最低的
                    {
                        p->next = pbuy->next;
                        pbuy->next = p;
                        flag = 2;
                        break;
                    }
                    else
                    {
                        pbuy = pbuy->next;
                        continue;
                    }
                }
                else
                {
                    flag = 1; // 出现过股票相同的情况
                    if (pbuy->next->price > price || pbuy->next->price == price)
                    {
                        pbuy = pbuy->next;
                        continue;
                    }
                    else
                    {
                        p->next = pbuy->next;
                        pbuy->next = p;
                        flag = 2; // 已经将新的委托存储到队列中,且此次插入的不是出价最低的
                        break;
                    }
                }
            }
            if (flag == 0 || flag == 1) // 这种股票是第一次出现在买队列中
            {
                pbuy->next = p;
            }
        }
    }
    else if (b_or_s == 's')
    {
        NODE *psell = sell;
        if (psell->next == NULL) // 队列为空的情况
        {
            psell->next = p;
        }
        else
        {
            int flag = 0;
            while (psell->next != NULL)
            {
                if (psell->next->stock_id != stock_id)
                {
                    if (flag == 1) // 这次插入的卖委托是目前为止要价最高的
                    {
                        p->next = psell->next;
                        psell->next = p;
                        flag = 2;
                        break;
                    }
                    else
                    {
                        psell = psell->next;
                        continue;
                    }
                }
                else
                {
                    flag = 1; // 出现过股票相同的情况
                    if (psell->next->price < price || psell->next->price == price)
                    {
                        psell = psell->next;
                        continue;
                    }
                    else
                    {
                        p->next = psell->next;
                        psell->next = p;
                        flag = 2; // 已经将新的委托存储到队列中,且此次插入的不是要价最高的
                        break;
                    }
                }
            }
            if (flag == 0 || flag == 1) // 这种股票是第一次出现在卖队列中
            {
                psell->next = p;
            }
        }
    }
}
// 查询股票
void inquireStock(int stock_id)
{
    NODE *pbuy = buy, *psell = sell;
    int flag = 0;
    printf("buy orders:\n");
    while (pbuy->next != NULL)
    {
        if (pbuy->next->stock_id != stock_id && flag == 1)
        {
            break;
        }
        else if (pbuy->next->stock_id == stock_id)
        {
            flag = 1;
            printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: b\n",
                   pbuy->next->op_id, pbuy->next->stock_id, pbuy->next->price, pbuy->next->num);
        }
        pbuy = pbuy->next;
    }
    flag = 0;
    printf("sell orders:\n");
    while (psell->next != NULL)
    {
        if (psell->next->stock_id != stock_id && flag == 1)
        {
            break;
        }
        else if (psell->next->stock_id == stock_id)
        {
            flag = 1;
            printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: s\n",
                   psell->next->op_id, psell->next->stock_id, psell->next->price, psell->next->num);
        }
        psell = psell->next;
    }
}
// 委托撤销
void delRequest(int op_id)
{
    NODE *pbuy = buy, *psell = sell;
    int flag = 0;
    // op_id 对应的是buy服务
    while (pbuy->next != NULL)
    {
        if (pbuy->next->op_id == op_id)
        {
            NODE *temp = pbuy->next;
            pbuy->next = temp->next;
            printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: b\n",
                   op_id, temp->stock_id, temp->price, temp->num);
            free(temp);
            flag = 1;
            break;
        }
        pbuy = pbuy->next;
    }
    if (flag == 0)
    {
        while (psell->next != NULL)
        {
            if (psell->next->op_id == op_id)
            {
                NODE *temp = psell->next;
                psell->next = temp->next;
                printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: s\n",
                       op_id, temp->stock_id, temp->price, temp->num);
                free(temp);
                flag = 1;
                break;
            }
            psell = psell->next;
        }
    }
    if (flag == 0)
    {
        printf("not found\n");
    }
}
int main(int argc, char const *argv[])
{
    int op, stock_id, op_id, num;
    float price;
    char b_or_s;
    buy = (NODE *)malloc(sizeof(NODE));
    buy->next = NULL;
    sell = (NODE *)malloc(sizeof(NODE));
    sell->next = NULL;
    do
    {
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            break;
        case 1:
            scanf("%4d %f %d %c", &stock_id, &price, &num, &b_or_s);
            items_num++;
            op_id = items_num;
            addRequest(op_id, stock_id, price, num, b_or_s);
            break;
        case 2:
            scanf("%d", &stock_id);
            inquireStock(stock_id);
            break;
        case 3:
            scanf("%d", &op_id);
            delRequest(op_id);
        default:
            break;
        }
    } while (op != 0);
    return 0;
}
