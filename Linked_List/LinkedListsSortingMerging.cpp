#include <iostream>
using namespace std;

// Define a struct for a linked list node
struct list
{
    int number;
    struct list *next;
};

// Define pointers for the last node in two separate linked lists
struct list *last = NULL;
struct list *last2 = NULL;

// Function to insert a node at the end of the first linked list
void insertAtEndList1(int a)
{
    list *current = new list();
    current->number = a;
    if (last == NULL)
    {
        last = current;
        last->next = last;
    }
    else
    {
        current->next = last->next;
        last->next = current;
        last = current;
    }
}

// Function to insert a node at the end of the second linked list
void insert2ndList(int b)
{
    list *current = new list();
    current->number = b;
    if (last2 == NULL)
    {
        last2 = current;
        last2->next = last2;
    }
    else
    {
        current->next = last2->next;
        last2->next = current;
        last2 = current;
    }
}

// Function to display the elements in both linked lists
void display()
{
    list *p = last->next;
    if (p == NULL)
    {
        cout << "\nNo elements in the first list" << endl;
    }
    else
    {
        cout << "\n\nElements in the first list:" << endl;
        while (p != last)
        {
            cout << p->number <<" ";
            p = p->next;
        }
        cout << p->number <<" ";
    }

    list *q = last2->next;
    if (q == NULL)
    {
        cout << "\nNo elements in the second list" << endl;
    }
    else
    {
        cout << "\n\nElements in the second list:" << endl;

        while (q != last2)
        {
            cout << q->number << " ";
            q = q->next;
        }
        cout << q->number << " ";
    }
}

// Function to find the maximum value in both linked lists
void findMaximum()
{
    list *p = last->next;
    list *k = last->next;
    list *q = last->next;

    do
    {
        do
        {
            if (p->number > q->number)
            {
                int temp = p->number;
                p->number = q->number;
                q->number = temp;
                q = q->next;
            }
            else
            {
                q = q->next;
            }
        } while (q != k);

        q = last->next;
        p = p->next;
    } while (p != k);

    list *a = last2->next;
    list *c = last2->next;
    list *b = last2->next;

    do
    {
        do
        {
            if (a->number > b->number)
            {
                int temp = a->number;
                a->number = b->number;
                b->number = temp;
                b = b->next;
            }
            else
            {
                b = b->next;
            }
        } while (b != c);

        b = last2->next;
        a = a->next;
    } while (a != c);
}

// Function to delete a node from the second list and return the pointer to the deleted node
struct list *deletePointer()
{
    list *ptr = last2->next;
    last2->next = ptr->next;
    ptr->next = NULL;
    return ptr;
}

// Function to merge the two linked lists
void mergingList()
{
    list *ptr;
    list *p = last->next;
    list *q = p->next;

    while (p != last)
    {
        ptr = deletePointer();
        ptr->next = q;
        p->next = ptr;
        p = ptr;
        q = q->next;
        p = p->next;
    }
}

int main()
{
    insertAtEndList1(10);
    insertAtEndList1(12);
    insertAtEndList1(28);
    insertAtEndList1(18);
    insertAtEndList1(25);
    insertAtEndList1(19);

    insert2ndList(5);
    insert2ndList(24);
    insert2ndList(12);
    insert2ndList(6);
    insert2ndList(15);

    cout << "Initial Linked Lists:";
    display();

    cout << "\n\nAfter Sorting:";
    findMaximum();
    display();

    cout << "\n\nAfter Merging:" << endl;
    mergingList();
    display();

    return 0;
}
