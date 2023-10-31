#include <iostream>
using namespace std;

// Define a structure for a stack node
struct Stack
{
    char data;
    Stack *next;     // Pointer to the next node
    Stack *previous; // Pointer to the previous node (for doubly linked list)
};

Stack *top = NULL; // Initialize the top of the stack as NULL

// Function to check if the stack is empty
bool isEmpty()
{
    return (top == NULL);
}

// Function to check if the stack is full (based on available memory)
bool isFull()
{
    Stack *pointer = new Stack();
    return (pointer == NULL);
}

// Function to push a character onto the stack
void push(char value)
{
    Stack *current = new Stack();
    current->data = value;

    if (isFull())
    {
        cout << "Stack is overflow" << endl;
    }
    else
    {
        if (isEmpty())
        {
            top = current;
            top->next = NULL;
            top->previous = NULL;
        }
        else
        {
            current->next = top;
            top->previous = current;
            top = current;
            top->previous = NULL;
        }
    }
}

// Function to pop (remove and return) a character from the stack
char pop()
{
    Stack *p = top;
    char value;

    if (isEmpty())
    {
        cout << "Stack is empty";
    }
    else
    {
        if (top->next == NULL)
        {
            value = top->data;
            top = top->next;
            return value;
        }
        else
        {
            value = top->data;
            top = top->next;
            p->next = NULL;
            p->previous = NULL;
            delete (p);
            return value;
        }
    }
}

// Function to check if a given string is a palindrome
bool isPalindrome(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (pop() != str[i])
        {
            return false;
        }
    }
    return true;
}

// Function to display the stack elements
void display()
{
    Stack *p = top;
    Stack *s = top;

    while (s->next != NULL)
    {
        s = s->next;
    }

    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != NULL);

    cout << endl;

    while (s != NULL)
    {
        cout << s->data << " ";
        s = s->previous;
    }
}

int main()
{
    string str;
    cout << "Enter String: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        push(str[i]);
    }

    bool palindrome = isPalindrome(str);

    if (palindrome)
    {
        cout << "The entered string is a palindrome." << endl;
    }
    else
    {
        cout << "The entered string is not a palindrome." << endl;
    }

    return 0;
}
