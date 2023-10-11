#include <iostream>
using namespace std;

// Structure to represent a ride
struct Ride
{
    string riderName;
    double kilometer;
    double charges;
    Ride *next;
};

// Structure to represent a careem car
struct CareemCar
{
    int rideEarning = 0;
    string DriverName;
    string CarName;
    string CarRegistrationNumber;
    double kilometer;
    int CarType;
    CareemCar *next;
    Ride *rideList = nullptr;
};

CareemCar *firstCar = nullptr;
CareemCar *lastCar = nullptr;

// Function to insert a new car at the end of the list
void insertCarAtEnd()
{
    CareemCar *currentCar = new CareemCar();

    cout << "\nEnter Car Name: ";
    cin >> currentCar->CarName;
    cout << "\nEnter Car Driver Name: ";
    cin >> currentCar->DriverName;
    cout << "\nEnter Car Type (1 or 2): ";
    cin >> currentCar->CarType;
    cout << "\nEnter Car Registration Number: ";
    cin >> currentCar->CarRegistrationNumber;

    if (firstCar == nullptr)
    {
        firstCar = lastCar = currentCar;
    }
    else
    {
        lastCar->next = currentCar;
        lastCar = currentCar;
    }
}

// Function to display the registration numbers of available cars
void registrationDisplay()
{
    CareemCar *currentCar = firstCar;

    if (currentCar == nullptr)
    {
        cout << "\nNo available cars right now.";
    }
    else
    {
        cout << "\nAvailable Car Registrations:" << endl;
        while (currentCar != nullptr)
        {
            cout << currentCar->CarRegistrationNumber << endl;
            currentCar = currentCar->next;
        }
    }
}

// Function to search for a car by its registration number and return a pointer to it
CareemCar *searchCar(string registrationNumber)
{
    CareemCar *currentCar = firstCar;

    while (currentCar != nullptr)
    {
        if (registrationNumber == currentCar->CarRegistrationNumber)
        {
            return currentCar;
        }
        currentCar = currentCar->next;
    }
    return nullptr;
}

// Function to insert a new ride at the start of a car's ride list
void insertAtStartRide(CareemCar *car)
{
    Ride *currentRide = new Ride();

    cout << "\nEnter Rider Name: ";
    cin >> currentRide->riderName;
    cout << "\nEnter Ride Distance (in kilometers): ";
    cin >> currentRide->kilometer;

    if (car->CarType == 1)
    {
        currentRide->charges = currentRide->kilometer * 200;
    }
    else
    {
        currentRide->charges = currentRide->kilometer * 100;
    }

    car->rideEarning += currentRide->charges;
    car->kilometer += currentRide->kilometer;

    if (car->rideList == nullptr)
    {
        car->rideList = currentRide;
    }
    else
    {
        currentRide->next = car->rideList;
        car->rideList = currentRide;
    }
}

// Function to book a car and add a new ride to it
void bookCar()
{
    registrationDisplay();
    string carRegistrationNumber;
    cout << "\nEnter the car registration number you want to ride: ";
    cin >> carRegistrationNumber;

    CareemCar *car = searchCar(carRegistrationNumber);

    if (car == nullptr)
    {
        cout << "\nCar not found.";
    }
    else
    {
        insertAtStartRide(car);
        cout << "\nRide booked successfully.";
    }
}

// Function to display the details of all registered cars
void displayRegisteredCarDetails()
{
    CareemCar *currentCar = firstCar;

    if (currentCar == nullptr)
    {
        cout << "\nNo cars to show.";
    }
    else
    {
        cout << "\nDetails of Registered Cars:" << endl;
        while (currentCar != nullptr)
        {
            cout << "\nCar Name: " << currentCar->CarName;
            cout << "\nRegistration Number: " << currentCar->CarRegistrationNumber;
            cout << "\nCar Type: " << currentCar->CarType;
            cout << "\nDriver Name: " << currentCar->DriverName;
            cout << "\nDistance Travelled: " << currentCar->kilometer << " kilometers";
            currentCar = currentCar->next;
        }
    }
}

// Function to display the details of type 2 cars
void displayType2Cars()
{
    CareemCar *currentCar = firstCar;

    if (currentCar == nullptr)
    {
        cout << "\nNo cars to show.";
    }
    else
    {
        cout << "\nDetails of Type 2 Cars:" << endl;
        while (currentCar != nullptr)
        {
            if (currentCar->CarType == 2)
            {
                cout << "\nCar Name: " << currentCar->CarName;
                cout << "\nRegistration Number: " << currentCar->CarRegistrationNumber;
                cout << "\nCar Type: " << currentCar->CarType;
                cout << "\nDriver Name: " << currentCar->DriverName;
                cout << "\nDistance Travelled: " << currentCar->kilometer << " kilometers";
            }
            currentCar = currentCar->next;
        }
    }
}

// Function to display the details of rides
void displayRideDetails()
{
    CareemCar *currentCar = firstCar;

    if (currentCar == nullptr)
    {
        cout << "\nNo cars to show.";
    }
    else
    {
        cout << "\nDetails of Rides:" << endl;
        while (currentCar != nullptr)
        {
            Ride *currentRide = currentCar->rideList;
            while (currentRide != nullptr)
            {
                cout << "\nCar Registration Number: " << currentCar->CarRegistrationNumber;
                cout << "\nRide Charges: " << currentRide->charges;
                cout << "\nRide Distance: " << currentRide->kilometer << " kilometers";
                cout << "\nRider Name: " << currentRide->riderName << endl;
                currentRide = currentRide->next;
            }
            currentCar = currentCar->next;
        }
    }
}

// Function to display the total earning of a specific car
void displayEarningOfSpecificCar()
{
    registrationDisplay();
    string carRegistrationNumber;
    cout << "\nEnter the car registration number you want to check earnings for: ";
    cin >> carRegistrationNumber;

    CareemCar *car = searchCar(carRegistrationNumber);

    if (car == nullptr)
    {
        cout << "\nCar not found.";
    }
    else
    {
        cout << "\nTotal Earnings for Car with Registration Number " << car->CarRegistrationNumber << ": " << car->rideEarning << endl;
    }
}

// Function to display the total earnings of all cars
void displayEarningsOfAllCars()
{
    CareemCar *currentCar = firstCar;

    if (currentCar == nullptr)
    {
        cout << "\nNo cars to show.";
    }
    else
    {
        cout << "\nTotal Earnings for All Cars:" << endl;
        while (currentCar != nullptr)
        {
            cout << "\nCar Registration Number: " << currentCar->CarRegistrationNumber;
            cout << "\nTotal Earnings: " << currentCar->rideEarning << endl;
            currentCar = currentCar->next;
        }
    }
}

int main()
{
    int option;
    cout << "\nCareem Ride Management System" << endl;

    do
    {
        cout << "\nChoose an option:";
        cout << "\n1. Register New Car";
        cout << "\n2. Display Details of All Cars";
        cout << "\n3. Display Type 2 Cars";
        cout << "\n4. Book a Car";
        cout << "\n5. Display Ride Details";
        cout << "\n6. Display Total Earnings of a Specific Car";
        cout << "\n7. Display Total Earnings of All Cars";
        cout << "\n0. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            insertCarAtEnd();
            cout << "Car registered successfully." << endl;
            break;
        case 2:
            displayRegisteredCarDetails();
            break;
        case 3:
            displayType2Cars();
            break;
        case 4:
            bookCar();
            cout << "Ride booked successfully." << endl;
            break;
        case 5:
            displayRideDetails();
            break;
        case 6:
            displayEarningOfSpecificCar();
            break;
        case 7:
            displayEarningsOfAllCars();
            break;
        case 0:
            cout << "Exiting the Careem Ride Management System." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (option != 0);

    return 0;
}
