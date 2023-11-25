#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
using namespace std;

const int INFINITY_DISTANCE = INT_MAX;
const int MAX_CUSTOMERS = 15;
const int MAX_PIZZA_TYPES = 12;

int i = 0;
int y = 0;

vector<int> visitedPizza(MAX_CUSTOMERS, 0);
vector<int> distancesPizza(MAX_CUSTOMERS, INFINITY_DISTANCE);
vector<vector<int>> matrixGraphPizza(MAX_CUSTOMERS, vector<int>(MAX_CUSTOMERS, 0));

string departure = "I-8";

string travelPizza[MAX_CUSTOMERS] = {"I-8", "I-1", "I-2", "I-3", "I-4", "I-5", "I-6", "I-7", "F-1", "F-3", "F-2", "F-3", "F-4", "F-5", "F-6"};

class Customer
{
public:
    string name;
    long long cnic;
    string travelTo;
    int numberOfOrder;
    string *pizzaList;
    int *pizzaPrices;
    string pizzaData;
    int pizzaPriceTotal;
    int distanceTravel;
    int deliveryCharges;
    int TotalPrice;
    Customer *next1;
    Customer *previous1;

    Customer()
    {
        next1 = nullptr;
        previous1 = nullptr;
    }
};

Customer *firstPizzaNode = nullptr;
Customer *lastPizzaNode = nullptr;

void addEdge(int i, int j, int weight)
{
    matrixGraphPizza[i][j] = weight;
    matrixGraphPizza[j][i] = weight;
}

void initializeGraph()
{
    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        for (int j = 0; j < MAX_CUSTOMERS; j++)
        {
            matrixGraphPizza[i][j] = 0;
        }
    }
}

bool isNotVisited()
{
    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        if (visitedPizza[i] == 0)
        {
            return true;
        }
    }
    return false;
}

int minimumDistance()
{
    int minDist = INFINITY_DISTANCE;
    int index;

    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        if (visitedPizza[i] == 0 && distancesPizza[i] < minDist)
        {
            minDist = distancesPizza[i];
            index = i;
        }
    }
    return index;
}

int dijkstraAlgorithm(int source, int destination)
{
    int src = source;
    distancesPizza[source] = 0;

    while (isNotVisited())
    {
        source = minimumDistance();
        visitedPizza[source] = 1;

        for (int j = 0; j < MAX_CUSTOMERS; j++)
        {
            if (visitedPizza[j] == 0 && matrixGraphPizza[source][j] != 0)
            {
                if (distancesPizza[j] > matrixGraphPizza[source][j] + distancesPizza[source])
                {
                    distancesPizza[j] = matrixGraphPizza[source][j] + distancesPizza[source];
                }
            }
        }
    }
    return distancesPizza[destination];
}

int graphDistancePizza(string location)
{
    int dep = 0;
    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        if (location == travelPizza[i])
        {
            dep = i;
        }
    }

    initializeGraph();
    addEdge(0, 1, 3);
    addEdge(0, 2, 4);
    addEdge(0, 3, 9);
    addEdge(0, 4, 11);  
    addEdge(0, 5, 2);
    addEdge(0, 6, 15);
    addEdge(0, 7, 1);
    addEdge(0, 8, 8);
    addEdge(0, 9, 7);
    addEdge(0, 10, 6);
    addEdge(0, 11, 10);
    addEdge(0, 12, 5);
    addEdge(0, 13, 30);
    addEdge(0, 14, 40);
    // I-1 Distance to all sectors
    addEdge(1, 2, 1);
    addEdge(1, 3, 2);
    addEdge(1, 4, 6);
    addEdge(1, 5, 2);
    addEdge(1, 9, 4);
    addEdge(1, 10, 7);
    addEdge(1, 11, 9);
    addEdge(1, 13, 10);
    addEdge(1, 14, 13);
    // I-2 Distance to all sectors
    addEdge(2, 3, 5);
    addEdge(2, 4, 1);
    addEdge(2, 5, 2);
    addEdge(2, 8, 9);
    addEdge(2, 9, 7);
    addEdge(2, 11, 6);
    addEdge(2, 12, 18);
    addEdge(2, 13, 11);
    // I-3 Distance to all sectors
    addEdge(3, 4, 10);
    addEdge(3, 5, 8);
    addEdge(3, 6, 5);
    addEdge(3, 7, 6);
    addEdge(3, 9, 17);
    addEdge(3, 10, 16);
    addEdge(3, 12, 14);
    addEdge(3, 14, 4);
    // I-4 Distance to all sectors
    addEdge(4, 5, 10);
    addEdge(4, 7, 15);
    addEdge(4, 8, 16);
    addEdge(4, 9, 20);
    addEdge(4, 11, 21);
    addEdge(4, 13, 14);
    addEdge(4, 14, 11);
    // I-5 Distance to all sectors
    addEdge(5, 6, 10);
    addEdge(5, 7, 14);
    addEdge(5, 9, 17);
    addEdge(5, 10, 19);
    addEdge(5, 11, 25);
    addEdge(5, 12, 20);
    addEdge(5, 13, 16);
    // I-6 Distance to all sectors
    addEdge(6, 7, 10);
    addEdge(6, 8, 15);
    addEdge(6, 9, 19);
    addEdge(6, 10, 26);
    addEdge(6, 11, 20);
    addEdge(6, 12, 30);
    addEdge(6, 13, 29);
    // I-7 Distance to all sectors
    addEdge(7, 8, 17);
    addEdge(7, 9, 29);
    addEdge(7, 10, 14);
    addEdge(7, 11, 10);
    addEdge(7, 12, 18);
    addEdge(7, 13, 32);
    addEdge(7, 14, 36);
    // F-1 Distance to all sectors
    addEdge(8, 10, 30);
    addEdge(8, 11, 38);
    addEdge(8, 12, 28);
    addEdge(8, 13, 21);
    addEdge(8, 14, 32);
    // F-2 Distance to all sectors
    addEdge(9, 10, 26);
    addEdge(9, 11, 17);
    addEdge(9, 12, 29);
    addEdge(9, 13, 36);
    addEdge(9, 14, 33);
    // F-3 Distance to all sectors
    addEdge(10, 11, 14);
    addEdge(10, 13, 22);
    addEdge(10, 14, 34);
    // F-4 Distance to all sectors
    addEdge(11, 12, 23);
    addEdge(11, 13, 15);
    addEdge(11, 14, 28);
    // F-5 Distance to all sectors
    addEdge(12, 13, 10);
    addEdge(12, 14, 19);
    // F-6 Distance to all sectors
    addEdge(13, 14, 21);

    return dijkstraAlgorithm(0, dep);
}

Customer *createCustomer()
{
    string pizzaMenu[MAX_PIZZA_TYPES] = {"Chicken Tikka Pizza", "Chicken Fajita Pizza", "Cheesy Pizza", "Veggie Pizza", "Fajita Sicilian", "BBQ Pizza", "Pepperoni Pizaa", "Peri-peri Pizza", "Malai Boti Pizza", "Chicken Supreme Pizza", "Hot & Spicy Pizza", "Afghani Pizza"};
    int pricesOfPizza[MAX_PIZZA_TYPES] = {900, 1030, 1100, 760, 880, 1200, 790, 930, 1250, 1600, 1500, 1240};

    Customer *current = new Customer();

    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, current->name);

    cout << "Enter Customer Cnic Number: ";
    cin >> current->cnic;
    i++;

    cout << "Available locations: " << endl;
    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        cout << (i + 1) << ". " << travelPizza[i] << endl;
    }

    int selectedLocation;
    cout << "Enter Your Location: ";
    cin >> selectedLocation;
    current->travelTo = travelPizza[selectedLocation - 1];

    cout << "Pizza Menu: " << endl;
    for (int i = 0; i < MAX_PIZZA_TYPES; i++)
    {
        cout << (i + 1) << ". " << pizzaMenu[i] << endl;
    }
    cout << "Enter Your Number of Orders: ";
    cin >> current->numberOfOrder;
    current->pizzaList = new string[current->numberOfOrder];
    current->pizzaPrices = new int[current->numberOfOrder];

    for (int i = 0; i < current->numberOfOrder; i++)
    {
        int selectedPizza;
        cout << "Order Pizza Number " << (i + 1) << ": ";
        cin >> selectedPizza;

        current->pizzaList[i] = pizzaMenu[selectedPizza - 1];
        current->pizzaPrices[i] = pricesOfPizza[selectedPizza - 1];
    }

    current->pizzaPriceTotal = 0;
    current->pizzaData = "\nPizza Orders:\n";
    for (int i = 0; i < current->numberOfOrder; i++)
    {
        current->pizzaPriceTotal += current->pizzaPrices[i];
        current->pizzaData += to_string(i + 1) + ". " + current->pizzaList[i] + " Price: " + to_string(current->pizzaPrices[i]) + "\n";
    }
    return current;
}

void addCustomerData(Customer *customer)
{
    if (firstPizzaNode == nullptr)
    {
        firstPizzaNode = lastPizzaNode = customer;
    }
    else
    {
        customer->previous1 = lastPizzaNode;
        lastPizzaNode->next1 = customer;
        lastPizzaNode = customer;
    }

    customer->distanceTravel = graphDistancePizza(customer->travelTo);
    customer->deliveryCharges = customer->distanceTravel * 4;
    customer->TotalPrice = customer->pizzaPriceTotal + customer->deliveryCharges;
}

void displayServedCustomers()
{
    Customer *current = firstPizzaNode;
    int count = 1;

    cout << "------------ All Customers Served Till Now ------------" << endl;

    while (current != nullptr)
    {
        cout << "Customer " << count << " Details: " << endl;
        cout << "Customer Name: " << current->name << endl;
        cout << "Customer CNIC: " << current->cnic << endl;
        cout << "Location: " << current->travelTo << endl;
        cout << "Total Orders: " << current->numberOfOrder << endl;
        cout << "Distance Travel: " << current->distanceTravel << " km" << endl;
        cout << "Delivery Charges: PKR " << current->deliveryCharges << endl;
        cout << current->pizzaData;
        cout << "Total Price: PKR " << current->TotalPrice << endl;
        cout << "-----------------------------------------------------" << endl;

        current = current->next1;
        count++;
    }
}

void displayPendingCustomers()
{
    Customer *current = firstPizzaNode;
    int count = 1;

    cout << "------------ Pending Customers ------------" << endl;

    while (current != nullptr)
    {
        cout << "Customer " << count << " Details: " << endl;
        cout << "Customer Name: " << current->name << endl;
        cout << "Customer CNIC: " << current->cnic << endl;
        cout << "Location: " << current->travelTo << endl;
        cout << "Total Orders: " << current->numberOfOrder << endl;
        cout << "Distance Travel: " << current->distanceTravel << " km" << endl;
        cout << "Delivery Charges: PKR " << current->deliveryCharges << endl;
        cout << current->pizzaData;
        cout << "Total Price: PKR " << current->TotalPrice << endl;
        cout << "-----------------------------------------------------" << endl;

        current = current->next1;
        count++;
    }
}

void orderPizza()
{
    Customer *current = createCustomer();
    addCustomerData(current);

    cout << "-----------------------------------------------------" << endl;
    cout << "Your order has been placed successfully!" << endl;
    cout << "Delivery Details:" << endl;
    cout << "Estimated Delivery Time: " << current->distanceTravel * 2 << " minutes" << endl;
    cout << "Total Price: PKR " << current->TotalPrice << endl;
    cout << "-----------------------------------------------------" << endl;
}

void deliverPizza()
{
    if (firstPizzaNode == nullptr)
    {
        cout << "No pending orders to deliver." << endl;
    }
    else
    {
        Customer *current = firstPizzaNode;

        cout << "Delivering Pizza to " << current->name << " at " << current->travelTo << endl;
        cout << "Estimated Delivery Time: " << current->distanceTravel * 2 << " minutes" << endl;

        // Remove the delivered customer from the list
        firstPizzaNode = firstPizzaNode->next1;
        if (firstPizzaNode != nullptr)
        {
            firstPizzaNode->previous1 = nullptr;
        }

        delete current;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "------------------------------------" << endl;
        cout << "Pizza Delivery Management System" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Order Pizza" << endl;
        cout << "2. Display Served Customers" << endl;
        cout << "3. Display Pending Customers" << endl;
        cout << "4. Deliver Pizza" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            orderPizza();
            break;

        case 2:
            displayServedCustomers();
            break;

        case 3:
            displayPendingCustomers();
            break;

        case 4:
            deliverPizza();
            break;

        case 5:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);

    // Clean up dynamically allocated memory
    Customer *current = firstPizzaNode;
    while (current != nullptr)
    {
        Customer *temp = current;
        current = current->next1;
        delete temp;
    }

    return 0;
}
