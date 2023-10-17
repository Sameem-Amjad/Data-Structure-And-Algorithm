#include <iostream>
using namespace std;

// Define pizza names and prices
string pizzaList[] = {"Chicken Tikka Pizza", "Chicken Fajita Pizza", "Cheesy Pizza", "Veggie Pizza", "Fajita Sicilian", "BBQ Pizza", "Pepperoni Pizza", "Peri-peri Pizza", "Malai Boti Pizza", "Chicken Supreme Pizza", "Hot & Spicy Pizza", "Afghani Pizza"};
int price[] = {900, 1030, 1100, 760, 880, 1200, 790, 930, 1250, 1600, 1500, 1240};

class PizzaHutChangePolicy
{
private:
     int front;
     int rear;
     int size;
     string *arr;
     int *priceCustomer;
     int ItemNumber;

public:
     PizzaHutChangePolicy(int a)
     {
          front = rear = -1;
          size = a;
          arr = new string[size];
          priceCustomer = new int[size];
          for (int i = 0; i < size; i++)
          {
               arr[i] = "";
               priceCustomer[i] = 0;
          }
          ItemNumber = 0; // Initialize the item counter
     }

     // Sorting function to arrange pizza orders by price
     void sort()
     {
          int temp = 0;
          string a = "";
          for (int i = 0; i < size; i++)
          {
               for (int j = 0; j < size; j++)
               {
                    if (priceCustomer[i] > priceCustomer[j])
                    {
                         temp = priceCustomer[i];
                         priceCustomer[i] = priceCustomer[j];
                         priceCustomer[j] = temp;
                         a = arr[i];
                         arr[i] = arr[j];
                         arr[j] = a;
                    }
                    // No need for the 'else' condition here
               }
          }
     }

     bool isEmpty()
     {
          return (front == -1 && rear == -1);
     }

     bool isFull()
     {
          return (rear + 1) % size == front;
     }

     void Enqueue(string a, int b)
     {
          if (isFull())
          {
               cout << "Order is full. Please wait for the order to be delivered and then order pizza.\n";
               return;
          }
          else if (isEmpty())
          {
               rear = 0;
               front = 0;
               arr[rear] = a;
               priceCustomer[rear] = b;
               ItemNumber++;
          }
          else
          {
               rear = (rear + 1) % size;
               arr[rear] = a;
               priceCustomer[rear] = b;
               ItemNumber++;
               sort(); // Sort after adding a new order
          }
     }

     string Dequeue()
     {
          string a;
          if (isEmpty())
          {
               cout << "No order has been placed. Please order first.\n";
               return "";
          }
          else if (front == rear)
          {
               a = arr[front];
               arr[front] = "";
               front = rear = -1;
               ItemNumber--;
               return a;
          }
          else
          {
               if (arr[front] == "")
               {
                    cout << "No pizza order is placed now." << endl;
                    return a;
               }
               a = arr[front];
               arr[front] = "";
               front = (front + 1) % size;
               ItemNumber--;
               return a;
          }
     }

     int count()
     {
          return ItemNumber;
     }

     void display()
     {
          cout << "------------------------- Pizza Orders -------------------------" << endl;
          cout << "Total Pizza Orders till now are: " << endl;
          for (int i = 0; i < size; i++)
          {
               if (arr[i] != "")
               {
                    cout << (i + 1) << ". " << arr[i] << "\tPrice: " << priceCustomer[i] << endl;
               }
          }
          cout << "----------------------------------------------------------------" << endl;
     }
};

void OrderingPizza()
{
     int option, value;
     int size = sizeof(pizzaList) / sizeof(pizzaList[0]);
     string a;
     PizzaHutChangePolicy s(size);
     int priceOfPizza;

     do
     {
          cout << "---------------------------------------------------------------" << endl;
          cout << "                  Welcome to PizzaExpress" << endl;
          cout << "---------------------------------------------------------------" << endl;
          cout << "1. Pizza Order" << endl;
          cout << "2. Deliver Pizza" << endl;
          cout << "3. Display All Pizza Orders till now" << endl;
          cout << "4. Number of Pizza Orders Till Now" << endl;
          cout << "5. Exit" << endl;
          cout << "Please choose an option: ";
          cin >> option;

          switch (option)
          {
          case 1:
               cout << "Please start ordering pizzas:" << endl;
               cout << "---------------------------------------------------------------" << endl;
               cout << "No. Pizza Name" << endl;
               for (int i = 0; i < size; i++)
               {
                    cout << (i + 1) << ". " << pizzaList[i] << "\tPrice: " << price[i] << endl;
               }
               cout << "Enter the number corresponding to the pizza you want to order: ";
               cin >> value;

               if (value >= 1 && value <= 12)
               {
                    cout << "Enter the price: ";
                    cin >> priceOfPizza;
                    s.Enqueue(pizzaList[value - 1], price[value - 1]);
                    cout << "Pizza added to the order!" << endl;
               }
               else
               {
                    cout << "\nInvalid pizza selection. Please choose a valid option." << endl;
               }
               break;

          case 2:
               a = s.Dequeue();
               if (!a.empty())
               {
                    cout << "Pizza delivered: " << a << endl;
               }
               break;

          case 3:
               s.display();
               break;

          case 4:
               cout << "Number of pizza orders till now: " << s.count() << endl;
               break;

          case 5:
               cout << "Thank you for choosing PizzaExpress. Have a great day!" << endl;
               exit(1);
               break;

          default:
               cout << "Invalid option. Please choose a valid option." << endl;
               break;
          }
     } while (option != 0);
}

int main()
{
     OrderingPizza();
     return 0;
}
