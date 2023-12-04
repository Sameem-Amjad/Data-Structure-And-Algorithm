#include <iostream>
using namespace std;

class Heap
{
public:
	int hSize;
	int *arr;
	int front, rear;

	// Constructor for initializing the heap
	Heap()
	{
		hSize = 0;
		arr = new int[hSize];
		front = rear = -1;
	}

	// Constructor with size parameter
	Heap(int s)
	{
		hSize = s;
		arr = new int[hSize];
		front = rear = -1;
	}

	// Check if the heap is empty
	bool isEmpty()
	{
		if (front == -1)
			return true;
		else
			return false;
	}

	// Check if the heap is full
	bool isFull()
	{
		if (rear == hSize - 1)
			return true;
		else
			return false;
	}

	// Insert a value into the Max Heap
	void insertMaxHeap(int x)
	{
		if (isFull())
		{
			cout << "Heap is full!\n";
		}
		else if (isEmpty())
		{
			arr[++front] = x;
			rear++;
		}
		else
		{
			arr[++rear] = x;
			int newValInd = rear;
			int pNode = (newValInd - 1) / 2;

			// Bubble up the newly inserted element
			while (newValInd != 0 && arr[pNode] < arr[newValInd])
			{
				int temp = arr[newValInd];
				arr[newValInd] = arr[pNode];
				arr[pNode] = temp;

				newValInd = pNode;
				pNode = (newValInd - 1) / 2;
			}
			cout << "***Value inserted!***\n";
		}
	}

	// Swap two elements in the array
	void swap(int front, int rear)
	{
		int temp = arr[front];
		arr[front] = arr[rear];
		arr[rear] = temp;
	}

	// Delete the maximum element (root) from the Max Heap
	void delMax()
	{
		if (isEmpty())
		{
			cout << "Heap empty!\n";
		}
		else
		{
			// Replace root with the last element
			arr[front] = arr[rear];
			if (front == rear)
			{
				front = rear = -1;
			}
			else
			{
				--rear;
			}

			int newValInd = front;
			int lc = 2 * (newValInd) + 1, rc = 2 * (newValInd) + 2;

			// Reorganize the heap by sinking down the root
			while ((lc <= rear || rc <= rear) && newValInd >= 0)
			{
				if ((lc > rear && rc <= rear && arr[rc] > arr[newValInd]))
				{
					swap(rc, newValInd);
					newValInd = rc;
				}
				else if ((lc <= rear && rc > rear && arr[lc] > arr[newValInd]))
				{
					swap(lc, newValInd);
					newValInd = lc;
				}
				else if (lc <= rear && rc <= rear)
				{
					int maxInd = (arr[lc] > arr[rc]) ? lc : rc;
					swap(maxInd, newValInd);
					newValInd = maxInd;
				}
				else
				{
					newValInd = -1;
				}
				lc = 2 * (newValInd) + 1, rc = 2 * (newValInd) + 2;
			}
		}
	}

	// Display the elements in the heap
	void display()
	{
		if (isEmpty())
		{
			cout << "Empty heap!\n";
		}
		else
		{
			int i = 0;
			while (i <= rear)
			{
				cout << arr[i] << ", ";
				i++;
			}
			cout << "\nFront: " << front << ", Rear: " << rear << endl;
		}
	}
};

int main()
{
	int x;
	cout << "Enter number of integers: ";
	cin >> x;

	Heap maxH(x);
	maxH.insertMaxHeap(5);
	maxH.display();
	maxH.insertMaxHeap(13);
	maxH.display();
	maxH.insertMaxHeap(2);
	maxH.display();
	maxH.insertMaxHeap(23);
	maxH.display();
	maxH.insertMaxHeap(7);
	maxH.display();
	maxH.insertMaxHeap(30);
	maxH.display();
	maxH.insertMaxHeap(21);
	maxH.display();
	maxH.insertMaxHeap(18);
	maxH.display();

	maxH.delMax();
	maxH.display();
	maxH.delMax();
	maxH.display();
	return 0;
}
