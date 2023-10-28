#include <iostream>
#include <queue>
using namespace std;

// Array to track visited vertices (0: Not visited, 1: Visited)
int visited[5] = {0, 0, 0, 0, 0};

// Adjacency matrix to represent the graph
int myMatrix[5][5];

// Function to add an edge between vertices i and j in the graph
void addEdge(int i, int j) {
    myMatrix[i][j] = 1;
    myMatrix[j][i] = 1; // Since the graph is undirected, we set both directions.
}

// Function to initialize the adjacency matrix with zeros
void initialized() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            myMatrix[i][j] = 0;
        }
    }
}

int main() {
    initialized(); // Initialize the adjacency matrix
    addEdge(0, 1); // Add edges to the graph
    addEdge(1, 4);
    addEdge(3, 1);
    addEdge(2, 3);

    queue<int> q; // Create a queue for BFS traversal

    int i = 0; // Starting vertex
    visited[i] = 1; // Mark the starting vertex as visited
    cout << "BFS Traversal: " << i << " "; // Print the starting vertex
    q.push(i); // Enqueue the starting vertex

    // Perform BFS traversal
    while (!q.empty()) {
        int node = q.front(); // Dequeue a vertex from the queue
        q.pop();
        
        // Visit adjacent vertices
        for (int j = 0; j < 5; j++) {
            if (myMatrix[node][j] == 1 && visited[j] == 0) {
                cout << j << " "; // Print the visited vertex
                visited[j] = 1; // Mark it as visited
                q.push(j); // Enqueue the visited vertex
            }
        }
    }

    return 0;
}
