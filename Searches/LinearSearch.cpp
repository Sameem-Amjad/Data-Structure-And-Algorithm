#include <iostream>
using namespace std;

// Function to perform linear search
int search(int array[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        // Check if the current element equals the target element (x)
        if (array[i] == x)
            return i; // Return the index where the element is found
    }
    return -1; // Return -1 if the element is not found in the array
}

int main()
{
    int array[] = {4, 32, 67, 23, 16};
    int x = 23;                               // Element to search for
    int n = sizeof(array) / sizeof(array[0]); // Calculate the size of the array
    int result = search(array, n, x);         // Call the search function to find the element

    if (result == -1)
    {
        cout << "Element not found"; // Print a message if the element is not found
    }
    else
    {
        cout << "Element found at index: " << result; // Print the index where the element is found
    }

    return 0;
}
