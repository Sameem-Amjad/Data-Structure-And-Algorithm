#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> // Include the header for INT_MAX
using namespace std;

const int NUM_VERTICES = 6;

// Structure to represent an edge
struct Edge
{
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Function to add an edge to the adjacency list
void addEdge(vector<vector<Edge>> &adjList, int i, int j, int w)
{
    adjList[i].emplace_back(j, w);
    adjList[j].emplace_back(i, w); // For undirected graph
}

// Function to implement Prim's algorithm to find the MST
void primMST(vector<vector<Edge>> &adjList)
{
    vector<bool> inMST(NUM_VERTICES, false);      // To track if a vertex is in MST
    vector<int> minWeight(NUM_VERTICES, INT_MAX); // To store the minimum weight to connect to MST
    vector<int> parent(NUM_VERTICES, -1);         // To store the parent of each vertex in MST

    int startVertex = 0; // Start from vertex 0 or any other valid starting point

    minWeight[startVertex] = 0; // Initialize the weight of the start vertex to 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startVertex}); // Push the start vertex with weight 0 into the priority queue

    while (!pq.empty())
    {
        int u = pq.top().second; // Get the vertex with the minimum weight
        pq.pop();

        if (inMST[u])
            continue; // Skip if already included in MST

        inMST[u] = true; // Mark u as included in MST

        for (const Edge &edge : adjList[u])
        {
            int v = edge.to;
            int weight = edge.weight;

            if (!inMST[v] && weight < minWeight[v])
            {
                minWeight[v] = weight;
                parent[v] = u;
                pq.push({minWeight[v], v});
            }
        }
    }

    // Print the MST edges and their weights
    cout << "Unique Minimum Spanning Tree (MST) Output:" << endl;
    for (int i = 1; i < NUM_VERTICES; i++)
    {
        cout << "Edge " << parent[i] << " - " << i << " with weight " << minWeight[i] << endl;
    }
}

int main()
{
    vector<vector<Edge>> adjList(NUM_VERTICES);

    addEdge(adjList, 1, 4, 40);
    addEdge(adjList, 1, 2, 34);
    addEdge(adjList, 0, 2, 22);
    addEdge(adjList, 2, 4, 35);
    addEdge(adjList, 5, 4, 11);
    addEdge(adjList, 0, 5, 13);
    addEdge(adjList, 3, 5, 23);
    addEdge(adjList, 1, 3, 70);

    primMST(adjList);

    return 0;
}
