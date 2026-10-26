#include <iostream>
using namespace std;

int graph[10][10], visited[10];
int n;


void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    int queue[10], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int vertex = queue[front++];
        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int edges, u, v, start;

    cout << "Enter number of vertices (max 10): ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nDFS Traversal: ";
    DFS(start);

    cout << "\nBFS Traversal: ";
    BFS(start);

    cout << endl;
    return 0;
}