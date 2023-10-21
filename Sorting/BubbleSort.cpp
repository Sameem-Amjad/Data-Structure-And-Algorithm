#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int array[], int size)
{
    for (int steps = 0; steps < (size - 1); ++steps)
    {
        int swap = 0;
        for (int i = 0; i < (size - steps - 1); ++i)
        {
            // Compare adjacent elements and swap if they are in the wrong order
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                swap = 1; // Set swap flag to indicate a swap occurred
            }
        }
        // If no swaps occurred in this pass, the array is already sorted, so break
        if (swap == 0)
            break;
    }
}

// Function to print the sorted array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << " " << array[i];
    }
    cout << "\n";
}

int main()
{
    int data[] = {5, 2, 57, 3, -9};
    int size = sizeof(data) / sizeof(data[0]);

    // Sort the array using Bubble Sort
    bubbleSort(data, size);

    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size); // Print the sorted array
}
