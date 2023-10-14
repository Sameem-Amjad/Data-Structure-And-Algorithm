#include <iostream>
using namespace std;

struct node
{
    int id;
    node *next;
};

node *first = NULL;
node *last = NULL;

// Function to insert a new node at the end of the linked list
void insert()
{
    node *current = new node();
    cout << "Enter a unique number: ";
    cin >> current->id;

    if (first == NULL)
    {
        first = last = current;
    }
    else
    {
        last->next = current;
        last = current;
    }
}

// Function to display the elements in the linked list
void display()
{
    if (first == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    cout << "Linked list elements:" << endl;
    node *p = first;
    while (p != NULL)
    {
        cout << p->id << " ";
        p = p->next;
    }
    cout << endl;
}

// Function to search for a node with a specific id
node *search(int a)
{
    node *ptr = first;
    while (ptr != NULL)
    {
        if (ptr->id == a)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

// Function to swap two nodes in the linked list
void swap(int x, int y)
{
    node *p = search(x);
    node *q = search(y);

    if (p == NULL || q == NULL)
    {
        cout << "One or both nodes not found." << endl;
        return;
    }

    if (p == q)
    {
        cout << "Nodes are the same; no need to swap." << endl;
        return;
    }

    int temp = p->id;
    p->id = q->id;
    q->id = temp;
}

int main()
{
    int option;
    cout << "0. Exit\n1. Insert number\n2. Swap nodes\n3. Display\nEnter your choice: ";
    cin >> option;

    while (option >= 1 && option < 4)
    {
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            int x, y;
            cout << "Enter the unique numbers of the nodes you want to swap:" << endl;
            cout << "Node 1: ";
            cin >> x;
            cout << "Node 2: ";
            cin >> y;
            swap(x, y);
            break;
        case 3:
            display();
            break;
        default:
            break;
        }

        cout << "\n0. Exit\n1. Insert number\n2. Swap nodes\n3. Display\nEnter your choice: ";
        cin >> option;
    }

    return 0;
}
