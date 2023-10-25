#include <iostream>
using namespace std;

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to perform selection sort
void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;

        // Find the index of the minimum element in the unsorted part of the array
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // Swap the found minimum element with the first element
        swap(&array[min_idx], &array[step]);
    }
}

int main()
{
    int data[] = {40, 16, 20, 25, 12};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Original array:\n";
    printArray(data, size);

    // Sort the array using selection sort
    selectionSort(data, size);

    cout << "Sorted array in Ascending Order:\n";
    printArray(data, size);

    return 0;
}
