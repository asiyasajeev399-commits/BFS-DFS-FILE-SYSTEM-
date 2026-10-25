#include <stdio.h>
#define MAX 20
int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start, int target, char files[MAX][30])
{
    int queue[MAX], front = 0, rear = 0;
    int i, found = 0;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];

        printf("%s ", files[current]);

        if (current == target)
            found = 1;

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.\n");
    else
        printf("\nFile not found using BFS.\n");
}

void DFS(int current, int target, char files[MAX][30],
         int *found)
{
    int i;

    visited[current] = 1;
    printf("%s ", files[current]);

    if (current == target)
        *found = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 && !visited[i])
            DFS(i, target, files, found);
    }
}

int main()
{
    char files[MAX][30];
    int i, j, start, target, found;

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter file/directory names:\n");
    for (i = 0; i < n; i++)
    {
        printf("Node %d: ", i);
        scanf("%29s", files[i]);
    }

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node number: ");
    scanf("%d", &start);

    printf("Enter target file node number: ");
    scanf("%d", &target);

    if (start < 0 || start >= n ||
        target < 0 || target >= n)
    {
        printf("Invalid node number.\n");
        return 1;
    }

    BFS(start, target, files);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    found = 0;
    printf("\nDFS Traversal: ");
    DFS(start, target, files, &found);

    if (found)
        printf("\nFile found using DFS.\n");
    else
        printf("\nFile not found using DFS.\n");

    return 0;
}