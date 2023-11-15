#include <iostream>
using namespace std;

struct Stack
{
    char data;
    Stack *next;
};

Stack *top = nullptr; // Initialize top of the stack as nullptr

bool isEmpty()
{
    return top == nullptr;
}

bool isFull()
{
    Stack *pointer = new Stack();
    if (pointer == nullptr)
    {
        return true;
    }
    else
    {
        delete pointer; // Free the allocated memory
        return false;
    }
}

char pop()
{
    char popValue;
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        popValue = top->data;
        Stack *temp = top;
        top = top->next;
        delete temp; // Free the memory of the popped element
    }
    return popValue;
}

void push(char a)
{
    Stack *current = new Stack();
    current->data = a;
    if (isFull())
    {
        cout << "Stack is Overflow" << endl;
    }
    else if (top == nullptr)
    {
        top = current;
    }
    else
    {
        if (a == ')')
        {
            if (pop() != '(')
            {
                cout << "Incorrect Value occurs" << endl;
                exit(1);
            }
            else
            {
                cout << "Popped Successfully" << endl;
            }
        }
        else if (a == '(')
        {
            current->next = top;
            top = current;
        }
        else
        {
            cout << "Incorrect input" << endl;
            exit(1);
        }
    }
}

void display()
{
    Stack *p = top;
    while (p != nullptr)
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
    return 0;
}
//((()))