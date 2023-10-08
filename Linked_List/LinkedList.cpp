#include <iostream>
using namespace std;

// Define a structure for a singly linked list node
struct node
{
    int id;
    node *next;
};

node *last;
node *first;

int size = 5;
int array[5];
int top = -1;

// Function to check if the linked list is empty
bool isEmpty()
{
    if (first == NULL && last == NULL)
    {
        return true;
    }
    return false;
}

// Function to insert a node with an 'id' into the linked list
void insertList(int id)
{
    if (isEmpty())
    {
        node *current = new node();
        first = last = current;
        first->id = id;
    }
    else
    {
        node *current = new node();
        last->next = current;
        last = current;
        last->id = id;
    }
}

// Function to display the linked list
void display()
{
    node *p = first;
    while (p != NULL)
    {
        cout << p->id << " ";
        p = p->next;
    }
}

// Function to pop an element from the stack
int pop()
{
    int value;
    if (top == -1)
    {
        cout << "Empty stack";
    }
    else
    {
        value = array[top];
        top--;
    }
    return value;
}

int value;

// Function to push an element onto the stack while maintaining descending order
void push(int key)
{
    if (top == size)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        if (top == -1)
        {
            top++;
            array[top];
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                if (key > array[i])
                {
                    value = pop();
                }
            }
            array[top] = key;
        }
    }
}

int main()
{
    // Insert elements into the linked list
    insertList(1);
    insertList(3);
    insertList(3);
    insertList(5);
    insertList(5);
    insertList(7);
    insertList(7);
    insertList(7);
    insertList(9);

    // Display the linked list
    cout << "Linked List is ";
    display();
    cout << endl;
    return 0;
}
