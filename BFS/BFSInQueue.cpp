#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *arr;

public:
    // Constructor with default size 20
    Queue()
    {
        size = 20;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    // Constructor with a specified size
    Queue(int s)
    {
        size = s;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == -1 || front >= size);
    }

    // Check if the queue is full (linear)
    bool isFull()
    {
        return (front == 0 && rear == size - 1);
    }

    // Check if the queue is full (circular)
    bool isFullCircular()
    {
        return ((rear + 1) % size == front);
    }

    // Left shift elements to make space for new elements
    void leftShift()
    {
        for (int i = front; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        front--;
    }

    // Enqueue (add) an element to the queue (linear)
    void enqueue(int num)
    {
        if (isEmpty())
        {
            front++;
            rear++;
            arr[rear] = num;
        }
        else
        {
            if (isFull())
            {
                cout << "Queue is already full!" << endl;
            }
            else
            {
                if (front != 0 && (rear == size - 1))
                {
                    leftShift();
                    cout << "Shifted" << endl;
                    arr[rear] = num;
                }
                else
                {
                    arr[++rear] = num;
                }
            }
        }
    }

    // Dequeue (remove) an element from the queue (linear)
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Dequeue: Queue is already empty!" << endl;
            return -1;
        }
        return arr[front++];
    }

    // Display the elements in the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Display: Queue is already empty!" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // Enqueue (add) an element to the queue (circular)
    void enq(int x)
    {
        if (isFullCircular())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % size;
            }

            arr[rear] = x;
        }
    }

    // Dequeue (remove) an element from the queue (circular)
    int deq()
    {
        if (isEmpty())
        {
            cout << "Underflow: Queue is empty" << endl;
            return -1;
        }
        else
        {
            int retValue = arr[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            return retValue;
        }
    }
};

int main()
{
    Queue q;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    cout << "--------------------------------------------------" << endl;
    cout << "          Breadth-First Search (BFS) Output" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Starting from node 0: ";

    visited[i] = 1;   // Mark the starting node as visited
    cout << i << " "; // Output the starting node
    q.enqueue(i);     // Enqueue the starting node

    while (!q.isEmpty())
    {
        int node = q.dequeue();
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;   // Mark the node as visited before enqueueing
                cout << j << " "; // Output the visited node
                q.enqueue(j);
            }
        }
    }

    cout << endl;
    cout << "--------------------------------------------------" << endl;

    return 0;
}
