#include <iostream>
using namespace std;

// Define a structure for the linked list node
struct stu
{
    int id;
    struct stu *next;
};

// Define pointers for the first and last nodes of the linked list
struct stu *first = NULL;
struct stu *Last = NULL;

// Function to insert a new node at the beginning of the linked list
void insertStart()
{
    stu *current = new stu();
    if (first == NULL)
    {
        first = current;
        Last = current;
    }
    else
    {
        current->next = first;
        first = current;
    }
    cout << "Enter Id: ";
    cin >> current->id;
}

// Function to insert a new node at the end of the linked list
void insertEnd()
{
    stu *current = new stu();
    if (first == NULL)
    {
        first = current;
        Last = current;
    }
    else
    {
        Last->next = current;
        Last = current;
    }
    cout << "Enter Id: ";
    cin >> current->id;
}

// Function to insert a new node after a specific index in the linked list
void insertAfterIndex(int index)
{
    struct stu *current = new stu();
    stu *p = first;
    int i = 1;
    while (p != NULL)
    {
        if (index == i)
        {
            current->next = p->next;
            cout << "Enter Id: ";
            cin >> current->id;
            p->next = current;
            p = current;
            break;
        }
        i++;
        p = p->next;
    }
}

// Function to insert a new node before a specific index in the linked list
void insertBeforeIndex(int index)
{
    struct stu *current = new stu();
    stu *p = first;
    int i = 1;
    while (p != NULL)
    {
        if ((index - 1) == i)
        {
            current->next = p->next;
            cout << "Enter Id: ";
            cin >> current->id;
            p->next = current;
            p = current;
            break;
        }
        i++;
        p = p->next;
    }
}

// Function to display the linked list
void display()
{
    struct stu *p = first;
    while (p->next != NULL)
    {
        cout << p->id << " ";
        p = p->next;
    }
    cout << p->id;
    Last = p;
}

// Function to traverse and print the linked list in reverse using recursion
void traverse(struct stu *ptr)
{
    if (!ptr)
    {
        return;
    }
    traverse(ptr->next);
    cout << ptr->id << " ";
}

// Function to print the linked list in reverse using iterative method
void reverseIterative()
{
    stu *p = first;
    stu *q = first;
    stu *k = Last;
    if (first == NULL)
    {
        cout << "\nNo id in Linked List \n";
    }
    do
    {
        p = first;
        while (p != k)
        {
            q = p;
            p = p->next;
        }
        cout << " " << k->id;
        k = q;
    } while (k != first);
    if (k == first)
    {
        cout << " " << k->id;
    }
}

// Function to check if the linked list is a palindrome
void pallindrome()
{
    stu *p = first;
    stu *q = p->next;
    stu *k = first;
    stu *j = Last;
    int temp1, temp2;
    bool flag = true;
    while (k != NULL && j->next != p)
    {
        while (q != j)
        {
            p = p->next;
            q = q->next;
        }
        if (k->id == q->id)
        {
            flag = true;
        }
        else
        {
            flag = false;
            k = NULL;
        }

        if (k != NULL)
        {
            j = p;
            k = k->next;
            p = k;
            q = k->next;
        }
        if (k == j)
        {
            flag = true;
            k = NULL;
        }
    }
    if (flag == false)
    {
        cout << "no palindrome";
    }
    else
    {
        cout << "yes, Palindrome.";
    }
}

// Function to print the first and last elements of the linked list and the ones in between
void printing1STANDLASTANDSoOn()
{
    stu *p = first;
    stu *q = p->next;
    stu *k = first;

    while (k != NULL)
    {
        while (q->next != Last->next)
        {
            p = p->next;
            q = q->next;
        }
        if (k->id != q->id)
        {
            cout << k->id << endl;
            cout << q->id << endl;
            if (k->id == p->id)
            {
                k = NULL;
            }
        }
        else if (q->id == k->id)
        {
            cout << q->id << endl;
            k = NULL;
        }
        if (k != NULL)
        {
            Last = p;
            q = first->next;
            p = first;
            k = k->next;
        }
    }
}

int main()
{
    struct stu *p;
    struct stu *mid;
    int option;

    cout << "Linked List Operations:";
    cout << "\n1. Insert At Start";
    cout << "\n2. Insert At End";
    cout << "\n3. Insert After Index";
    cout << "\n4. Insert Before Index";
    cout << "\n5. Display";
    cout << "\n6. Print List in Reverse through Recursion";
    cout << "\n7. Print Reverse List through Looping";
    cout << "\n8. Check Palindrome";

    cout << "\nEnter Option: ";
    cin >> option;
    while (option != 0)
    {
        switch (option)
        {
        case 1:
            insertStart();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertAfterIndex(2);
            break;
        case 4:
            insertBeforeIndex(2);
            break;
        case 5:
            cout << "Linked List: ";
            display();
            break;
        case 6:
            cout << "Reverse List (Recursion): ";
            p = first;
            traverse(p);
            break;
        case 7:
            cout << "Reverse List (Looping): ";
            reverseIterative();
            break;
        case 8:
            pallindrome();
            break;
        default:
            break;
        }
        cout << "\nLinked List Operations:";
        cout << "\n1. Insert At Start";
        cout << "\n2. Insert At End";
        cout << "\n3. Insert After Index";
        cout << "\n4. Insert Before Index";
        cout << "\n5. Display";
        cout << "\n6. Print List in Reverse through Recursion";
        cout << "\n7. Print Reverse List through Looping";
        cout << "\n8. Check Palindrome";
        cout << "\nEnter Option: ";
        cin >> option;
    }
    return 0;
}
