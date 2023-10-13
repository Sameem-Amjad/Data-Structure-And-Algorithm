#include <iostream>
using namespace std;

// Define a struct for a node in the doubly linked list
struct node
{
    int id;
    node *next = NULL;
    node *previous = NULL;
};

node *first = NULL;
node *last = NULL;

// Function to insert a node with the given ID at the end of the list
void insertAtEnd(int id)
{
    node *current = new node();
    if (first == NULL)
    {
        first = last = current;
        last->id = id;
    }
    else
    {
        last->next = current;
        current->previous = last;
        last = current;
        last->id = id;
    }
}

// Function to print alternate nodes in the list
void alternatePrinting()
{
    node *p = first;
    while (p != NULL)
    {
        cout << p->id << " ";
        if (p->next != NULL)
        {
            p = p->next->next;
        }
        else
        {
            break;
        }
    }

    node *q = last;
    while (q != NULL)
    {
        cout << q->id << " ";
        if (q->previous != NULL)
        {
            q = q->previous->previous;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);

    alternatePrinting();

    return 0;
}
