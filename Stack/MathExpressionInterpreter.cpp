#include <iostream>
#include <math.h>
using namespace std;

// Define a struct for the stack
struct Stack
{
    int data;
    Stack *next;
};

Stack *top = NULL;

// Check if the stack is empty
bool isEmpty()
{
    return (top == NULL);
}

// Check if the stack is full
bool isFull()
{
    Stack *pointer = new Stack();
    return (pointer == NULL);
}

// Push an integer onto the stack
void push(int a)
{
    Stack *current = new Stack();
    if (isFull())
    {
        cout << "Stack is overflow" << endl;
    }
    else if (top == NULL)
    {
        top = current;
        top->data = a;
    }
    else
    {
        current->next = top;
        top = current;
        top->data = a;
    }
}

// Pop and return the top element from the stack
int pop()
{
    int popValue;
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        popValue = top->data;
        Stack *p = top;
        top = top->next;
        delete p;
    }
    return popValue;
}

// Evaluate a postfix expression and return the result
int postFixEvaluation(string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0'); // Convert character digit to integer
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
            switch (postfix[i])
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '^':
                push(pow(op1, op2)); // Calculate power using math library
                break;
            }
        }
    }
    return top->data; // The final result is the top element of the stack
}

int main()
{
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = postFixEvaluation(postfix);

    cout << "Result of the postfix expression: " << result << endl;

    return 0;
}
// 46+2/5*7+
//  231*+9-