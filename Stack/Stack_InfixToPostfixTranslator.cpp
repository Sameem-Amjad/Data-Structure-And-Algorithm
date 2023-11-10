#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    char *arr;

public:
    Stack()
    {
        top = -1;
        arr = new char[200];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == 199);
    }

    void push(char value)
    {
        if (isFull())
        {
            cout << "Stack is Full\n";
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return '\0'; // Return null character for empty stack
        }
        else
        {
            char popValue = arr[top];
            top--;
            return popValue;
        }
    }

    char topElement(int a)
    {
        return arr[a];
    }

    bool isOperator(char a)
    {
        return (a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == '(' || a == ')');
    }

    int precedence(char a)
    {
        if (a == '^')
        {
            return 3;
        }
        else if (a == '*' || a == '/')
        {
            return 2;
        }
        else if (a == '+' || a == '-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    void infixToPostfix(string infix)
    {
        string postfix = "";
        for (int i = 0; i < infix.length(); i++)
        {
            if (infix[i] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (topElement(top) != '(' && !isEmpty())
                {
                    char temp = pop();
                    postfix += temp;
                }
                // Pop the '('
                if (!isEmpty())
                {
                    pop();
                }
            }
            else if (isOperator(infix[i]))
            {
                if (isEmpty() || precedence(infix[i]) > precedence(arr[top]) || (precedence(infix[i]) == precedence(arr[top]) && infix[i] == '^'))
                {
                    push(infix[i]);
                }
                else
                {
                    while (!isEmpty() && precedence(infix[i]) <= precedence(arr[top]))
                    {
                        char temp = pop();
                        postfix += temp;
                    }
                    push(infix[i]);
                }
            }
            else
            {
                postfix += infix[i];
            }
        }
        while (!isEmpty())
        {
            char temp = pop();
            postfix += temp;
        }
        cout << "Postfix Expression: " << postfix << endl;
    }
};
int main()
{
    string infix;
    cout << "Enter an Expression: ";
    cin >> infix;
    Stack s;
    s.infixToPostfix(infix);
    return 0;
}

// K+L-M*N+(O^P)*W/U/V*T+Q