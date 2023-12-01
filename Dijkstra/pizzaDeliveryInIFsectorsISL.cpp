#include<iostream>
using namespace std;

// Arrays to store visited status, distances, and city names
int visitedPizza[15] = {0};
int distancesPizza[15] = {100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000};
string travelPizza[15] = {"I-8", "I-1", "I-2", "I-3", "I-4", "I-5", "I-6", "I-7", "F-1", "F-3", "F-2", "F-3", "F-4", "F-5", "F-6"};
int matrixGraphPizza[15][15];

// Function to add edges to the graph
void addTOGraph(int i, int j, int weight)
{
    matrixGraphPizza[i][j] = weight;
    matrixGraphPizza[j][i] = weight;
}

// Function to initialize the graph
void initialized(int matrixGraphPizza[][15])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            matrixGraphPizza[i][j] = 0;
        }
    }
}

// Function to check if there are unvisited Sectors
bool isNotVisited()
{
    for (int i = 0; i < 15; i++)
    {
        if (visitedPizza[i] == 0)
        {
            return true;
        }
    }
    return false;
}

// Function to find the city with the minimum distance
int mininmumDiistance()
{
    int min = 100000;
    int index;
    for (int i = 0; i < 15; i++)
    {
        if (visitedPizza[i] == 0 && distancesPizza[i] < min)
        {
            min = distancesPizza[i];
            index = i;
        }
    }
    return index;
}

// Dijkstra's algorithm to find the shortest distance
int dijkstraAlgo(int source, int dep)
{
    int src = source;
    distancesPizza[source] = 0;
    while (isNotVisited())
    {
        source = mininmumDiistance();

        visitedPizza[source] = 1;
        for (int j = 0; j < 15; j++)
        {
            if (visitedPizza[j] == 0)
            {
                if (matrixGraphPizza[source][j] != 0)
                {
                    if (distancesPizza[j] > matrixGraphPizza[source][j] + distancesPizza[source])
                    {
                        distancesPizza[j] = matrixGraphPizza[source][j] + distancesPizza[source];
                    }
                }
            }
        }
    }
    return distancesPizza[dep];
}

// Function to set up the graph with distances
void graphDistancePizza()
{
    initialized(matrixGraphPizza);
   
    // I-1 Distance to all Sectors
    addTOGraph(0, 1, 3);
    addTOGraph(0, 2, 4);
    addTOGraph(0, 3, 9);
    addTOGraph(0, 4, 11);
    addTOGraph(0, 5, 2);
    addTOGraph(0, 6, 15);
    addTOGraph(0, 7, 1);
    addTOGraph(0, 8, 8);
    addTOGraph(0, 9, 7);
    addTOGraph(0, 10, 6);
    addTOGraph(0, 11, 10);
    addTOGraph(0, 12, 5);
    addTOGraph(0, 13, 30);
    addTOGraph(0, 14, 40);
    // I-2 Distance to all Sectors
    addTOGraph(1, 2, 1);
    addTOGraph(1, 3, 2);
    addTOGraph(1, 4, 6);
    addTOGraph(1, 5, 2);
    addTOGraph(1, 9, 4);
    addTOGraph(1, 10, 7);
    addTOGraph(1, 11, 9);
    addTOGraph(1, 13, 10);
    addTOGraph(1, 14, 13);
    // I-3 Distance to all Sectors
    addTOGraph(2, 3, 5);
    addTOGraph(2, 4, 1);
    addTOGraph(2, 5, 2);
    addTOGraph(2, 8, 9);
    addTOGraph(2, 9, 7);
    addTOGraph(2, 11, 6);
    addTOGraph(2, 12, 18);
    addTOGraph(2, 13, 11);
    // I-4 Distance to all Sectors
    addTOGraph(3, 4, 10);
    addTOGraph(3, 5, 8);
    addTOGraph(3, 6, 5);
    addTOGraph(3, 7, 6);
    addTOGraph(3, 9, 17);
    addTOGraph(3, 10, 16);
    addTOGraph(3, 12, 14);
    addTOGraph(3, 14, 4);
    // I-5 Distance to all Sectors
    addTOGraph(4, 5, 10);
    addTOGraph(4, 7, 15);
    addTOGraph(4, 8, 16);
    addTOGraph(4, 9, 20);
    addTOGraph(4, 11, 21);
    addTOGraph(4, 13, 14);
    addTOGraph(4, 14, 11);
    // I-6 Distance to all Sectors
    addTOGraph(5, 6, 10);
    addTOGraph(5, 7, 14);
    addTOGraph(5, 9, 17);
    addTOGraph(5, 10, 19);
    addTOGraph(5, 11, 25);
    addTOGraph(5, 12, 20);
    addTOGraph(5, 13, 16);
    // I-7 Distance to all Sectors
    addTOGraph(6, 7, 10);
    addTOGraph(6, 8, 15);
    addTOGraph(6, 9, 19);
    addTOGraph(6, 10, 26);
    addTOGraph(6, 11, 20);
    addTOGraph(6, 12, 30);
    addTOGraph(6, 13, 29);
    // F-1 Distance to all Sectors
    addTOGraph(7, 8, 17);
    addTOGraph(7, 9, 29);
    addTOGraph(7, 10, 14);
    addTOGraph(7, 11, 10);
    addTOGraph(7, 12, 18);
    addTOGraph(7, 13, 32);
    addTOGraph(7, 14, 36);
    // F-2 Distance to all Sectors
    addTOGraph(8, 10, 30);
    addTOGraph(8, 11, 38);
    addTOGraph(8, 12, 28);
    addTOGraph(8, 13, 21);
    addTOGraph(8, 14, 32);
    // F-3 Distance to all Sectors
    addTOGraph(9, 10, 26);
    addTOGraph(9, 11, 17);
    addTOGraph(9, 12, 29);
    addTOGraph(9, 13, 36);
    addTOGraph(9, 14, 33);
    // F-4 Valley Distance to all Sectors
    addTOGraph(10, 11, 14);
    addTOGraph(10, 13, 22);
    addTOGraph(10, 14, 34);
    // F-5 Distance to all Sectors
    addTOGraph(11, 12, 23);
    addTOGraph(11, 13, 15);
    addTOGraph(11, 14, 28);
    // F-6 Distance to all Sectors
    addTOGraph(12, 13, 10);
    addTOGraph(12, 14, 19);
    // F-7 Distance to all Sectors
    addTOGraph(13, 14, 21);
}

int main()
{
    graphDistancePizza();

    // Find and print the shortest distance between two Sectors
    int shortestDistance = dijkstraAlgo(3, 10);
    cout << "Shortest distance between " << travelPizza[0] << " and " << travelPizza[13] << " is: " << shortestDistance << " units." << endl;

    return 0;
}
