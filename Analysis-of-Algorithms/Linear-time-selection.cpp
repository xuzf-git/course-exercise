// 线性时间选择问题 (分治)
#include <stdio.h>
#define MAX 100000
int num[MAX];
// 选择排序
void slsort(int p, int q)
{
    for (int i = p + 1; i <= q; i++)
    {
        int temp = num[i], j = i - 1;
        while (j >= p)
        {
            if (num[j] > temp)
            {
                num[j + 1] = num[j];
                j--;
            }
            else
                break;
        }
        num[j + 1] = temp;
    }
}
// 分解函数
int Partition(int p, int q, int mid)
{
    int i = p, j = q;
    while (i <= q && j >= p)
    {
        while (num[i] < mid)
        {
            i++;
        }
        while (num[j] > mid)
        {
            j--;
        }
        if (i >= j)
            break;
        else
        {
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
            i++, j--;
        }
    }
    return j;
}
// 选择函数
int Select(int p, int q, int k)
{
    if (q - p < 75)
    {
        slsort(p, q);
        return num[p + k - 1];
    }
    // 选出 n/5 组中每个组的中位数
    for (int i = 0; i <= (q - p - 4) / 5; i++)
    {
        slsort(p + 5 * i, p + 5 * i + 4);
        int temp = num[p + 5 * i + 2];
        num[p + 5 * i + 2] = num[p + i];
        num[p + i] = temp;
    }
    // 选出各种中位数的中位数 mid
    int mid = Select(p, p + (q - p - 4) / 5, ((q - p - 4) / 5 + 1) / 2);
    // 以 mid 为基准进行分解
    int mid_id = Partition(p, q, mid);
    int mid_rank = mid_id - p + 1;
    // 递归条件判断
    if (k == mid_rank)
    {
        return num[mid_id];
    }
    else if (k < mid_rank)
    {
        return Select(p, mid_id, k);
    }
    else
    {
        return Select(mid_id + 1, q, k - mid_rank);
    }
}
int main(int argc, char const *argv[])
{
    int i = 0, k;
    while (scanf("%d", &num[i]) != EOF)
    {
        i++;
    }
    scanf("%d", &k); // 选择第几小的元素
    if (k > i)
        printf("error!\n");
    else
        printf("%d\n", Select(0, i, k));
    return 0;
}
