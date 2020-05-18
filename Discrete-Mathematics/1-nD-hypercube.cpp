#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
int dic[95];
int adjmatrix[128];
vector<vector<int>> adjlist(128);
int main(int argc, char const* argv[])
{
    char ch, start = ' ';
    // 存储邻接表
    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ')
        {
            continue;
        }
        else if (ch == '\n')
        {
            start = ' ';
            continue;
        }
        else if (start == ' ')
        {
            dic[ch] = 1;
            start = ch;
        }
        else
        {
            dic[ch] = 1;
            adjlist[start].push_back(ch);
        }
    }
    // 统计出现的节点数
    int nodes = 0;
    for (int i = 0; i < 128; i++)
    {
        if (dic[i] == 1)
        {
            nodes++;
            dic[i] = nodes;
        }
    }
    // 转换成邻接矩阵
    for (int i = 0; i < 128; i++)
    {
        if (dic[i] == 0)
        {
            continue;
        }
        else
        {
            int tail;
            memset(adjmatrix, 0, sizeof(adjmatrix));
            while (adjlist[i].empty() == false)
            {
                // head = dic[i] - 1;
                tail = dic[adjlist[i].back()] - 1;
                adjmatrix[tail] += 1;
                adjlist[i].pop_back();
            }
            for (int j = 0; j < nodes - 1; j++)
            {
                printf("%d ", adjmatrix[j]);
            }
            printf("%d\n", adjmatrix[nodes - 1]);
        }
    }
    return 0;
}
