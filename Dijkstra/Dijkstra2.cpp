#include <iostream>
#include <limits.h>
using namespace std;

const int NUM_VERTICES = 6;
const int INFINITY = INT_MAX;
const int UNDEFINED = -1;

// Function to add an edge to the adjacency matrix
void addEdge(int matrix[][NUM_VERTICES], int i, int j, int w)
{
    matrix[i][j] = w;
    matrix[j][i] = w;
}

// Function to initialize the adjacency matrix with zeros
void initializeMatrix(int matrix[][NUM_VERTICES])
{
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        for (int j = 0; j < NUM_VERTICES; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

// Function to display the adjacency matrix
void displayMatrix(int matrix[][NUM_VERTICES])
{
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        for (int j = 0; j < NUM_VERTICES; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to implement Dijkstra's algorithm to find the shortest path
void dijkstra(int src, int matrix[][NUM_VERTICES])
{
    int distances[NUM_VERTICES];
    int sources[NUM_VERTICES];
    int visited[NUM_VERTICES] = {0};

    for (int i = 0; i < NUM_VERTICES; i++)
    {
        distances[i] = INFINITY;
        sources[i] = UNDEFINED;
    }

    distances[src] = 0;

    while (true)
    {
        int minDistance = INFINITY;
        int u = -1;

        // Find the vertex with the minimum distance among unvisited vertices
        for (int i = 0; i < NUM_VERTICES; i++)
        {
            if (!visited[i] && distances[i] < minDistance)
            {
                minDistance = distances[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < NUM_VERTICES; v++)
        {
            if (!visited[v] && matrix[u][v] != 0)
            {
                if (distances[u] + matrix[u][v] < distances[v])
                {
                    distances[v] = distances[u] + matrix[u][v];
                    sources[v] = u;
                }
            }
        }
    }

    cout << "\nShortest Distances from Node " << src << ":\n";
    cout << "Node\tShortest Distance\tShortest Path" << endl;

    for (int i = 0; i < NUM_VERTICES; i++)
    {
        cout << src << " -> " << i << "\t";
        if (distances[i] == INFINITY)
        {
            cout << "Infinity\t\t";
        }
        else
        {
            cout << distances[i] << "\t\t";
        }

        int current = i;
        while (current != UNDEFINED)
        {
            cout << current;
            if (current != src)
            {
                cout << " <- ";
            }
            current = sources[current];
        }
        cout << endl;
    }
}

int main()
{
    int myMatrix[NUM_VERTICES][NUM_VERTICES];
    initializeMatrix(myMatrix);
    addEdge(myMatrix, 1, 4, 40);
    addEdge(myMatrix, 1, 2, 34);
    addEdge(myMatrix, 0, 2, 22);
    addEdge(myMatrix, 2, 4, 35);
    addEdge(myMatrix, 5, 4, 11);
    addEdge(myMatrix, 0, 5, 13);
    addEdge(myMatrix, 3, 5, 23);
    addEdge(myMatrix, 1, 3, 70);

    displayMatrix(myMatrix);

    int sourceNode = 1;
    dijkstra(sourceNode, myMatrix);

    return 0;
}
