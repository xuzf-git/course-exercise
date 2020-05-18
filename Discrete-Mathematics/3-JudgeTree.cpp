#include <cstdio>
#include <cstring>
using namespace std;
int graph[100][100];
bool visited[100];
int nonum;
int ednum = 0;
int visited_num;
void DFS(int current)
{
    visited[current] = true;
    visited_num++;
    if (visited_num == nonum)
    {
        return;
    }
    else
    {
        for (int i = 0; i < nonum; i++)
        {
            if (graph[current][i] == 1 && visited[i] == false)
            {
                DFS(i);
            }
        }
        return;
    }
}
int main(int argc, char const *argv[])
{
    memset(visited, false, sizeof(visited));
    scanf("%d", &nonum);
    for (int i = 0; i < nonum; i++)
    {
        for (int j = 0; j < nonum; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1)
                ednum++;
        }
    }
    if (ednum != 2 * (nonum - 1))
    {
        printf("no\n");
    }
    else
    {
        DFS(0);
        if (visited_num == nonum)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
