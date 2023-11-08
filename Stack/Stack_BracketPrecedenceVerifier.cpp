#include <iostream>
using namespace std;

struct Stack
{
    char data;
    Stack *next;
};

Stack *top = NULL;

bool isEmpty()
{
    return (top == NULL);
}

bool isFull()
{
    Stack *pointer = new Stack();
    return (pointer == NULL);
}

char pop()
{
    char popValue = '\0'; // Initialize with null character
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        popValue = top->data;
        Stack *temp = top;
        top = top->next;
        delete temp;
    }
    return popValue;
}

void push(char a)
{
    Stack *current = new Stack();
    if (isFull())
    {
        cout << "Stack is Overflow" << endl;
    }
    else if (top == NULL)
    {
        top = current;
        current->data = a;
    }
    else
    {
        if ((top->data == '{' && (a == '[' || a == ']')) ||
            (top->data == '(' && (a == '[' || a == ']' || a == '{' || a == '}')))
        {
            cout << "Incorrect precedence" << endl;
            exit(1);
        }

        if (top->data == '[' || a == ']')
        {
            if (a == ']')
            {
                if (pop() != '[')
                {
                    cout << "Incorrect" << endl;
                    exit(1);
                }
            }
            else
            {
                current->data = a;
                current->next = top;
                top = current;
            }
        }
        else if (top->data == '{' || a == '}')
        {
            if (a == '}')
            {
                if (pop() != '{')
                {
                    cout << "Incorrect" << endl;
                    exit(1);
                }
            }
            else
            {
                current->data = a;
                current->next = top;
                top = current;
            }
        }
        else if (top->data == '(' || a == ')')
        {
            if (a == ')')
            {
                if (pop() != '(')
                {
                    cout << "Incorrect" << endl;
                    exit(1);
                }
            }
            else
            {
                current->data = a;
                current->next = top;
                top = current;
            }
        }
    }
}

void display()
{
    Stack *p = top;
    while (p != NULL)
    {
        cout << p->data;
        p = p->next;
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

    if (isEmpty())
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Unbalanced" << endl;
        display();
    }

    return 0;
}   
// [{()}]