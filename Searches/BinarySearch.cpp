#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int array[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (array[mid] == x)
            return mid; // If the middle element is equal to the target 'x', return its index

        if (array[mid] < x)
            low = mid + 1; // If the middle element is less than 'x', search in the right half
        else
            high = mid - 1; // If the middle element is greater than 'x', search in the left half
    }
    return -1; // Return -1 if 'x' is not found in the array
}

int main(void)
{
    int array[] = {4, 32, 67, 23, 16};
    int x = 4;
    int n = sizeof(array) / sizeof(array[0]);

    // Perform binary search to find 'x' in the array
    int result = binarySearch(array, x, 0, n - 1);

    if (result == -1)
        cout << "Element not found"; // If result is -1, 'x' was not found
    else
        cout << "Element is found at index: " << result; // Otherwise, print the index where 'x' was found
}
