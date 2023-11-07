#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    char *array;
    int size;

public:
    // Constructor to initialize the stack with a given size
    Stack(int a) : top(-1), size(a)
    {
        array = new char[size];
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull()
    {
        return top >= size - 1;
    }

    // Push a character onto the stack
    void push(char value)
    {
        if (isFull())
        {
            cout << "Stack is Full" << endl;
        }
        else
        {
            top++;
            array[top] = value;
        }
    }

    // Pop a character from the stack
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        else
        {
            char popValue = array[top];
            array[top] = 0; // Clear the element
            top--;
            return popValue;
        }
    }

    // Display the contents of the stack
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Check if the stack is a palindrome by comparing with another stack
    bool isPalindrome(Stack &s2)
    {
        for (int i = 0; i <= top; i++)
        {
            if (array[i] != s2.pop())
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    int size = str.length();

    Stack stack1(size);
    Stack stack2(size);

    // Push characters from the string onto both stacks
    for (int i = 0; i < size; i++)
    {
        stack1.push(str[i]);
    }

    // Push characters in reverse order onto the second stack
    for (int i = size - 1; i >= 0; i--)
    {
        stack2.push(str[i]);
    }

    cout << "Stack 1: ";
    stack1.display();
    cout << "Stack 2: ";
    stack2.display();

    // Check if the string is a palindrome
    if (stack1.isPalindrome(stack2))
    {
        cout << "It's a palindrome." << endl;
    }
    else
    {
        cout << "It's not a palindrome." << endl;
    }

    return 0;
}
