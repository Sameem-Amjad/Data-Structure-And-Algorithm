#include <iostream>
using namespace std;

// Merge two subarrays of arr[]
// First subarray is arr[p..q]
// Second subarray is arr[q+1..r]
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create temporary arrays to hold the two subarrays
    int left[n1], right[n2];

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[q + 1 + j];

    // Merge the two subarrays back into arr[p..r]
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if any
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if any
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Main merge sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

// Utility function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {23, 15, 8, 2, 5, 35};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Call mergeSort function to sort the array
    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: \n";
    printArray(arr, size);

    return 0;
}
