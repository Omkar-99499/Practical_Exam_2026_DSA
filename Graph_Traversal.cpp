#include <iostream>
using namespace std;

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int vertices;


void BFS(int start)
{
    int queue[MAX];
    int front = -1, rear = -1;

    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[++rear] = start;
	cout << "BFS Traversal: ";

    while (front != rear)
    {
        int current = queue[++front];
		cout << current << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    cout << endl;
}


void DFS(int v)
{
    visited[v] = 1;
	cout << v << " ";

    for (int i = 0; i < vertices; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int start;

    cout << "Enter number of vertices: ";
    cin >> vertices;
	cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    cin >> start;
    BFS(start);

    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    cout << "DFS Traversal: ";
    DFS(start);

    cout << endl;

    return 0;
}
