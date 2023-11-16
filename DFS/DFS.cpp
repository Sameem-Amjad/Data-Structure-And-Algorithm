#include <iostream>
using namespace std;

// Adjacency matrix representing the graph
int a[7][7] = {
    {0, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

// Depth-First Search (DFS) function
void dfs(int i)
{
    cout << i << " "; // Print the current node with a space
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1)
        {
            a[i][j] = a[j][i] = 0; // Mark the edge as visited to avoid revisiting it
            dfs(j);                // Recursively visit adjacent nodes
        }
    }
}

int main()
{
    cout << "Depth-First Search (DFS) Output:" << endl;
    dfs(0);       // Start DFS from node 0
    cout << endl; // Print a newline after DFS traversal
    return 0;
}
