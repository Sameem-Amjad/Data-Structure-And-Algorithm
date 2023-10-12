#include <iostream>
using namespace std;

// Define the structure for a linked list node
struct Node
{
    int id;
    Node *next;
};

Node *first = NULL; // Pointer to the first node in the linked list
Node *last = NULL;  // Pointer to the last node in the linked list

// Function to insert a new node at the end of the linked list
void insert()
{
    Node *current = new Node();
    cout << "Enter number: ";
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

// Function to display the linked list in list-like format
void display()
{
    Node *p = first;
    cout << "Linked List:" << endl;
    cout << "- ";
    while (p->next != NULL)
    {
        cout << p->id << " -> ";
        p = p->next;
    }
    cout << p->id << " -" << endl;
    last = p;
}

// Function to print pairs of elements with the same value in the linked list
void printing()
{
    Node *p = first;
    Node *q = p->next;
    Node *k = first;

    while (k != NULL)
    {
        while (q->next != last->next)
        {
            p = p->next;
            q = q->next;
        }
        if (k->id != q->id)
        {
            cout  << k->id<< "- " ;
            cout  << q->id<< "- " ;
            if (k->id == p->id)
            {
                k = NULL;
            }
        }
        else if (q->id == k->id)
        {
            cout << "- " << q->id << endl;
            k = NULL;
        }
        if (k != NULL)
        {
            last = p;
            q = first->next;
            p = first;
            k = k->next;
        }
    }
}

int main()
{
    int option;
    cout << "\n1. Insert a number\n2. Check pairs\n3. Display linked list\n4. Exit\nEnter your choice: ";
    cin >> option;

    while (option >= 1 && option <= 3)
    {
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            printing();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
        cout << "\n1. Insert a number\n2. Check pairs\n3. Display linked list\n4. Exit\nEnter your choice: ";
        cin >> option;
    }

    return 0;
}
