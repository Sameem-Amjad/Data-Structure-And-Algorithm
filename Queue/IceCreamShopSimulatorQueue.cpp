#include <iostream>
using namespace std;

class IceCreamShop
{
private:
    int front;
    int rear;
    int size;
    string *arr;

public:
    IceCreamShop(int a)
    {
        front = rear = -1;
        size = a;
        arr = new string[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = "";
        }
    }

    // Check if the ice cream shop is empty
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    // Check if the ice cream shop is full
    bool isFull()
    {
        return ((front == 0 && rear == (size - 1)) || (front == rear + 1));
    }

    // Order ice cream from the front of the shop
    void OrderIceCreamFromFront(string flavor)
    {
        if (isFull())
        {
            cout << "Ice cream shop is full. Please wait for your order to be delivered before ordering more.\n";
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
            arr[front] = flavor;
        }
        else if (front == 0)
        {
            front = size - 1;
            arr[front] = flavor;
        }
        else
        {
            front--;
            arr[front] = flavor;
        }
    }

    // Order ice cream from the rear of the shop
    void OrderIceCreamFromRear(string flavor)
    {
        if (isFull())
        {
            cout << "Ice cream shop is full. Please wait for your order to be delivered before ordering more.\n";
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = flavor;
        }
        else if (rear == size - 1)
        {
            rear = 0;
            arr[rear] = flavor;
        }
        else
        {
            rear++;
            arr[rear] = flavor;
        }
    }

    // Serve ice cream from the front of the shop
    string ServeIceCreamFromFront()
    {
        string flavor;
        if (isEmpty())
        {
            cout << "No orders have been placed yet. Please place an order first.\n";
            return "";
        }
        else if (front == rear)
        {
            flavor = arr[front];
            arr[front] = "";
            front = rear = -1;
            return flavor;
        }
        else if (front == size - 1)
        {
            flavor = arr[front];
            front = 0;
            return flavor;
        }
        else
        {
            flavor = arr[front];
            arr[front] = "";
            front++;
            return flavor;
        }
    }

    // Serve ice cream from the rear of the shop
    string ServeIceCreamFromRear()
    {
        string flavor;
        if (isEmpty())
        {
            cout << "No orders have been placed yet. Please place an order first.\n";
            return "";
        }
        else if (front == rear)
        {
            flavor = arr[rear];
            arr[rear] = "";
            front = rear = -1;
            return flavor;
        }
        else if (rear == 0)
        {
            flavor = arr[rear];
            rear = size - 1;
            return flavor;
        }
        else
        {
            flavor = arr[rear];
            arr[rear] = "";
            rear--;
            return flavor;
        }
    }

    // Display all ice cream orders
    void DisplayOrders()
    {
        cout << "Total ice cream orders placed till now:\n";
        int i = front;
        while (i != rear)
        {
            cout << (i + 1) << ". " << arr[i] << endl;
            i = (i + 1) % size;
        }
        cout << (i + 1) << ". " << arr[rear] << endl;
    }
};

void OrderingIceCream()
{
    int option, flavorChoice;
    string flavors[] = {
        "Vanilla", "Chocolate", "Strawberry", "Mint Chocolate Chip",
        "Cookie Dough", "Rocky Road", "Butter Pecan", "Caramel Swirl",
        "Pistachio", "Coffee", "Raspberry Ripple", "Neapolitan"};
    int size = sizeof(flavors) / sizeof(flavors[0]);
    string flavor;
    IceCreamShop shop(size);

    do
    {
        cout << "\nIce Cream Shop Menu:\n";
        cout << "1. Order Ice Cream From Front\n";
        cout << "2. Order Ice Cream From Rear\n";
        cout << "3. Serve Ice Cream From Front to Customer\n";
        cout << "4. Serve Ice Cream From Rear to Customer\n";
        cout << "5. Display All Ice Cream Orders\n";
        cout << "6. Exit\n";
        cout << "Please select an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Available Ice Cream Flavors:\n";
            for (int i = 0; i < size; i++)
            {
                cout << (i + 1) << ". " << flavors[i] << endl;
            }
            cout << "Enter the number of the flavor you want to order: ";
            cin >> flavorChoice;
            if (flavorChoice >= 1 && flavorChoice <= size)
            {
                shop.OrderIceCreamFromFront(flavors[flavorChoice - 1]);
            }
            else
            {
                cout << "Invalid flavor choice. Please choose a valid flavor.\n";
            }
            break;

        case 2:
            cout << "Available Ice Cream Flavors:\n";
            for (int i = 0; i < size; i++)
            {
                cout << (i + 1) << ". " << flavors[i] << endl;
            }
            cout << "Enter the number of the flavor you want to order: ";
            cin >> flavorChoice;
            if (flavorChoice >= 1 && flavorChoice <= size)
            {
                shop.OrderIceCreamFromRear(flavors[flavorChoice - 1]);
            }
            else
            {
                cout << "Invalid flavor choice. Please choose a valid flavor.\n";
            }
            break;

        case 3:
            flavor = shop.ServeIceCreamFromFront();
            if (!flavor.empty())
            {
                cout << "Served Ice Cream Flavor: " << flavor << endl;
            }
            break;

        case 4:
            flavor = shop.ServeIceCreamFromRear();
            if (!flavor.empty())
            {
                cout << "Served Ice Cream Flavor: " << flavor << endl;
            }
            break;

        case 5:
            shop.DisplayOrders();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "Invalid option. Please choose a valid option.\n";
            break;
        }
    } while (option != 0);
}

int main()
{
    OrderingIceCream();
    return 0;
}
