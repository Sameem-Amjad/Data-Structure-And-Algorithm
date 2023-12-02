// Dijkstra's algorithm to find the shortest path
#include <iostream>
using namespace std;

int visited[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int distances[15] = {100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000};
int scv[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int matrixGraph[15][15];
string travel[15] = {"Lahore", "Karachi", "Peshawar", "Multan", "Islamabad/Faizabad", "Dera Ghazi Khan", "Quetta", "Sargodha", "Hyderabad", "Sahiwal", "Swat", "Hunza Valley", "Gwadar", "Larkana", "Sialkot"};

// Function to add an edge to the graph
void addTOGraph(int i, int j, int weight)
{
    matrixGraph[i][j] = weight;
    matrixGraph[j][i] = weight;
}

// Function to initialize the graph
void initialized(int matrixGraph[][15])
{
    for (int i = 0; i < (sizeof visited / sizeof visited[0]); i++)
    {
        for (int j = 0; j < (sizeof visited / sizeof visited[0]); j++)
        {
            matrixGraph[i][j] = 0;
        }
    }
}

// Function to check if there are unvisited nodes
bool isNotVisited()
{
    for (int i = 0; i < (sizeof visited / sizeof visited[0]); i++)
    {
        if (visited[i] == 0)
        {
            return true;
        }
    }
    return false;
}

// Function to find the minimum distance node
int mininmumDiistance()
{
    int min = 100000;
    int index;
    for (int i = 0; i < (sizeof visited / sizeof visited[0]); i++)
    {
        if (visited[i] == 0 && distances[i] < min)
        {
            min = distances[i];
            index = i;
        }
    }
    return index;
}

// Dijkstra's algorithm to find the shortest path
int dijkstraAlgo(int source, int dep)
{
    int src = source;
    distances[source] = 0;
    while (isNotVisited())
    {
        source = mininmumDiistance();
        visited[source] = 1;

        for (int j = 0; j < (sizeof visited / sizeof visited[0]); j++)
        {
            if (visited[j] == 0)
            {
                if (matrixGraph[source][j] != 0)
                {
                    if (distances[j] > matrixGraph[source][j] + distances[source])
                    {
                        distances[j] = matrixGraph[source][j] + distances[source];
                        scv[j] = source;
                    }
                }
            }
        }
    }

    // Printing the path
    cout << "Path from " << travel[src] << " to " << travel[dep] << ": ";
    int p = dep;
    while (p != src)
    {
        cout << travel[p] << " <- ";
        p = scv[p];
    }
    cout << travel[src] << endl;

    return distances[dep];
}

// Function to display the graph
void display()
{
    cout << "Graph (Adjacency Matrix):" << endl;
    for (int i = 0; i < (sizeof visited / sizeof visited[0]); i++)
    {
        for (int j = 0; j < (sizeof visited / sizeof visited[0]); j++)
        {
            cout << matrixGraph[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    initialized(matrixGraph);

   addTOGraph(0, 1, 1250);
    addTOGraph(0, 2, 450);
    addTOGraph(0, 3, 350);
    addTOGraph(0, 4, 250);
    addTOGraph(0, 5, 437);
    addTOGraph(0, 6, 550);
    addTOGraph(0, 7, 166);
    addTOGraph(0, 8, 950);
    addTOGraph(0, 9, 155);
    addTOGraph(0, 10, 440);
    addTOGraph(0, 11, 510);
    addTOGraph(0, 12, 1820);
    addTOGraph(0, 13, 800);
    addTOGraph(0, 14, 115);

    addTOGraph(1, 2, 1450);
    addTOGraph(1, 3, 650);
    addTOGraph(1, 4, 1300);
    addTOGraph(1, 5, 750);
    addTOGraph(1, 6, 620);
    addTOGraph(1, 7, 1140);
    addTOGraph(1, 8, 150);
    addTOGraph(1, 9, 1000);
    addTOGraph(1, 10, 1590);
    addTOGraph(1, 11, 1960);
    addTOGraph(1, 12, 630);
    addTOGraph(1, 13, 440);
    addTOGraph(1, 14, 1300);

    addTOGraph(2, 3, 580);
    addTOGraph(2, 4, 155);
    addTOGraph(2, 5, 270);
    addTOGraph(2, 6, 1500);
    addTOGraph(2, 7, 380);
    addTOGraph(2, 8, 1390);
    addTOGraph(2, 9, 550);
    addTOGraph(2, 10, 1300);
    addTOGraph(2, 11, 640);
    addTOGraph(2, 12, 1740);
    addTOGraph(2, 13, 1100);
    addTOGraph(2, 14, 590);

    addTOGraph(3, 4, 510);
    addTOGraph(3, 5, 85);
    addTOGraph(3, 6, 580);
    addTOGraph(3, 7, 320);
    addTOGraph(3, 8, 710);
    addTOGraph(3, 9, 170);
    addTOGraph(3, 10, 560);
    addTOGraph(3, 11, 1000);
    addTOGraph(3, 12, 1490);
    addTOGraph(3, 13, 512);
    addTOGraph(3, 14, 420);

    addTOGraph(4, 5, 320);
    addTOGraph(4, 6, 800);
    addTOGraph(4, 7, 250);
    addTOGraph(4, 8, 1250);
    addTOGraph(4, 9, 420);
    addTOGraph(4, 10, 240);
    addTOGraph(4, 11, 597);
    addTOGraph(4, 12, 1800);
    addTOGraph(4, 13, 1040);
    addTOGraph(4, 14, 213);

    addTOGraph(5, 6, 500);
    addTOGraph(5, 7, 440);
    addTOGraph(5, 8, 670);
    addTOGraph(5, 9, 270);
    addTOGraph(5, 10, 820);
    addTOGraph(5, 11, 1180);
    addTOGraph(5, 12, 1420);
    addTOGraph(5, 13, 460);
    addTOGraph(5, 14, 534);

    addTOGraph(5, 7, 440);
    addTOGraph(5, 8, 670);
    addTOGraph(5, 9, 270);
    addTOGraph(5, 10, 820);
    addTOGraph(5, 11, 1180);
    addTOGraph(5, 12, 1420);
    addTOGraph(5, 13, 460);
    addTOGraph(5, 14, 534);

    addTOGraph(6, 7, 770);
    addTOGraph(6, 8, 710);
    addTOGraph(6, 9, 800);
    addTOGraph(6, 10, 1020);
    addTOGraph(6, 11, 1420);
    addTOGraph(6, 12, 916);
    addTOGraph(6, 13, 390);
    addTOGraph(6, 14, 1060);

    addTOGraph(7, 8, 1710);
    addTOGraph(7, 9, 230);
    addTOGraph(7, 10, 440);
    addTOGraph(7, 11, 800);
    addTOGraph(7, 12, 1850);
    addTOGraph(7, 13, 840);
    addTOGraph(7, 14, 360);

    addTOGraph(8, 9, 890);
    addTOGraph(8, 10, 1430);
    addTOGraph(8, 11, 1800);
    addTOGraph(8, 12, 788);
    addTOGraph(8, 13, 310);
    addTOGraph(8, 14, 1140);

    addTOGraph(9, 10, 610);
    addTOGraph(9, 11, 974);
    addTOGraph(9, 12, 1697);
    addTOGraph(9, 13, 678);
    addTOGraph(9, 14, 300);

    addTOGraph(10, 11, 504);
    addTOGraph(10, 12, 1980);
    addTOGraph(10, 13, 1220);
    addTOGraph(10, 14, 440);

    addTOGraph(11, 12, 2340);
    addTOGraph(11, 13, 1590);
    addTOGraph(11, 14, 800);

    addTOGraph(12, 13, 1060);
    addTOGraph(12, 14, 1960);

    addTOGraph(13, 14, 920);

    display();
    cout << "\nDistance: " << dijkstraAlgo(3, 11) << endl;

    return 0;
}
