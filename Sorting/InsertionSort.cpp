#include <iostream>
using namespace std;

// Function to print an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Insertion sort algorithm
void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        // Select the key element to be inserted
        int key = array[step];
        int j = step - 1;

        // Move elements of the array that are greater than the key
        // to one position ahead of their current position
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        // Place the key element at its correct position
        array[j + 1] = key;
    }
}

int main()
{
    int data[] = {12, 19, 3, 6, 1};
    int size = sizeof(data) / sizeof(data[0]);

    // Call the insertionSort function to sort the array
    insertionSort(data, size);

    cout << "Sorted array in ascending order: ";
    printArray(data, size);

    return 0;
}
