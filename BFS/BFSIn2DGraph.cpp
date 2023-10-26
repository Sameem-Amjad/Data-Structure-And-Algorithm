#include <iostream>
using namespace std;

// Graph representation using a 2D array
int array[7][7];
int visited[7];

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int s)
    {
        size = s;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool is_empty()
    {
        return front == -1 && rear == -1;
    }

    bool is_full()
    {
        return rear == size - 1;
    }

    void enqueue(int num)
    {
        if (is_full())
        {
            cout << "Queue is already full!" << endl;
        }
        else
        {
            if (is_empty())
            {
                front++;
            }
            arr[++rear] = num;
        }
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "Dequeue: Queue is already empty!" << endl;
            return -1;
        }
        int item = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        return item;
    }
};

void add_to_graph(int i, int j, int connected)
{
    array[i][j] = connected;
}

void initialize_graph()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            array[i][j] = 0;
        }
    }
}

void display_graph()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    initialize_graph();
    add_to_graph(0, 3, 1);
    add_to_graph(0, 6, 1);
    add_to_graph(1, 2, 1);
    add_to_graph(1, 5, 1);
    add_to_graph(1, 6, 1);
    add_to_graph(2, 5, 1);
    add_to_graph(2, 2, 1);
    add_to_graph(2, 6, 1);
    add_to_graph(3, 1, 1);
    add_to_graph(3, 5, 1);
    add_to_graph(4, 2, 1);
    add_to_graph(5, 6, 1);
    add_to_graph(5, 3, 1);
    add_to_graph(6, 2, 1);
    add_to_graph(6, 1, 1);
    add_to_graph(6, 6, 1);

    display_graph();

    Queue q(100);
    int i = 0;
    visited[i] = 1;
    q.enqueue(i);

    cout << "Breadth-First Search (BFS) Output:" << endl;

    while (!q.is_empty())
    {
        int node = q.dequeue();
        cout << node << " ";

        for (int j = 0; j < 7; j++)
        {
            if (array[node][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                q.enqueue(j);
            }
        }
    }

    return 0;
}
