/*
Create a vehicle management system that allows users to add, remove, and search for vehicles in a fleet.
The program should use a base class Vehicle to represent each vehicle, with private member variables make, model, year, price,
and public member functions setMake, setModel, setYear, setPrice, getMake, getModel, getYear, getPrice, and displayDetails.

The setMake, setModel, setYear, and setPrice functions should take a string or integer argument and set the corresponding member variable.
The getMake, getModel, getYear, and getPrice functions should return the corresponding member variable.
The displayDetails function should print the make, model, year, and price of the vehicle.

The Vehicle class should also have a virtual member function calculateTax that takes no arguments and returns a float,
which represents the tax payable on the vehicle.

The Vehicle class should have two derived classes: Car and Truck. The Car class should have a private member variable numDoors,
and the Truck class should have private member variables payload and towingCapacity, as well as public member functions setNumDoors,
getNumDoors, setPayload, getPayload, setTowingCapacity, and getTowingCapacity.
The Car class should also override the calculateTax function to calculate the tax payable on a car, and the Truck class should
override the calculateTax function to calculate the tax payable on a truck.

The program should use a dynamic array of Vehicle pointers to represent the fleet, with a maximum capacity of 100 vehicles.
The program should prompt the user to add, remove, or search for vehicles, and then perform the corresponding operation.
The program should also validate the user's input and ensure that the fleet does not exceed its maximum capacity.

Example output:

Welcome to the vehicle management system!

Menu:
1. Add vehicle
2. Remove vehicle
3. Search for vehicle
4. Exit

Enter your choice: 1
Enter vehicle type (car/truck): car
Enter vehicle make: Honda
Enter vehicle model: Civic
Enter vehicle year: 2020
Enter vehicle price: 25000
Enter number of doors: 4
Car added to fleet.

Menu:
1. Add vehicle
2. Remove vehicle
3. Search for vehicle
4. Exit

Enter your choice: 2
Enter vehicle make: Honda
Enter vehicle model: Civic
Vehicle removed from fleet.

Menu:
1. Add vehicle
2. Remove vehicle
3. Search for vehicle
4. Exit

Enter your choice: 1
Enter vehicle type (car/truck): truck
Enter vehicle make: Ford
Enter vehicle model: F-150
Enter vehicle year: 2019
Enter vehicle price: 35000
Enter payload in pounds: 2000
Enter towing capacity in pounds: 10000
Truck added to fleet.

Menu:
1. Add vehicle
2. Remove vehicle
3. Search for vehicle
4. Exit

Enter your choice: 3
Enter vehicle make: Ford
Enter vehicle model: F-150

Vehicle Information:
Make: Ford
Model: F-150
Year: 2019
Price: $35,000
Payload: 2000 lbs
Towing Capacity: 10000 lbs
Tax Payable: $2,100

Menu:
1. Add vehicle
2. Remove vehicle
3. Search for vehicle
4. Exit

Enter your choice: 4
Exiting program.
Note: The tax payable on a car is calculated as 10% of the vehicle price, and the tax payable on a truck is calculated as 12% of the vehicle price.
The payload and towing capacity should be displayed in pounds with the "lbs" suffix.
The tax payable should be displayed as a dollar amount with the "$" prefix.
*/

#include <iostream>

const int MAX_FLEET_SIZE = 100;

class Vehicle
{
protected:
    std::string make;
    std::string model;
    int year;
    int price;

public:
    // constructor
    Vehicle() : make(""), model(""), year(0), price(0.0) {}

    void setMake(const std::string &vehicleMake)
    {
        make = vehicleMake;
    }
    void setModel(const std::string &vehicleModel)
    {
        model = vehicleModel;
    }
    void setYear(const uint8_t &vehicleYear)
    {
        year = vehicleYear;
    }
    void setPrice(const int &vehiclePrice)
    {
        price = vehiclePrice;
    }
    std::string getMake() const
    {
        return make;
    }
    std::string getModel() const
    {
        return model;
    }
    int getYear() const
    {
        return year;
    }
    int getPrice() const
    {
        return price;
    }
    virtual float calculateTax() const
    {
        return 0.0; // Default tax calculation
    }
    virtual void displayDetails() const
    {
        std::cout << "\nVehicle Information" << std::endl;
        std::cout << "Make: " << this->getMake() << std::endl;
        std::cout << "Model: " << this->getModel() << std::endl;
        std::cout << "Year: " << this->getYear() << std::endl;
        std::cout << "Price: " << this->getPrice() << std::endl;
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car() : numDoors(0) {}

    void setNumDoors(int doors)
    {
        numDoors = doors;
    }

    int getNumDoors() const
    {
        return numDoors;
    }

    float calculateTax() const override
    {
        return 0.10 * price; // Car tax is 10% of the price
    }

    void displayDetails() const override
    {
        Vehicle::displayDetails();
        std::cout << "Number of Doors: " << numDoors << "\n";
    }
};

class Truck : public Vehicle
{
private:
    int payload;
    int towingCapacity;

public:
    Truck() : payload(0), towingCapacity(0) {}

    void setPayload(int pounds)
    {
        payload = pounds;
    }

    int getPayload() const
    {
        return payload;
    }

    void setTowingCapacity(int pounds)
    {
        towingCapacity = pounds;
    }

    int getTowingCapacity() const
    {
        return towingCapacity;
    }

    float calculateTax() const override
    {
        return 0.12 * price; // Truck tax is 12% of the price
    }

    void displayDetails() const override
    {
        Vehicle::displayDetails();
        std::cout << "Payload: " << payload << " lbs\n";
        std::cout << "Towing Capacity: " << towingCapacity << " lbs\n";
    }
};

int main()
{
    Vehicle *fleet[MAX_FLEET_SIZE];
    int fleetSize = 0;

    std::cout << "Welcome to the vehicle management system!\n\n";

    while (true)
    {
        std::cout << "Menu:\n";
        std::cout << "1. Add vehicle\n";
        std::cout << "2. Remove vehicle\n";
        std::cout << "3. Search for vehicle\n";
        std::cout << "4. Exit\n\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (fleetSize >= MAX_FLEET_SIZE)
            {
                std::cout << "Fleet is full. Cannot add more vehicles.\n";
                break;
            }

            std::string vehicleType;
            std::cout << "Enter vehicle type (car/truck): ";
            std::cin >> vehicleType;

            if (vehicleType == "car")
            {
                Car *car = new Car;
                std::string make, model;
                int year;
                float price;
                int numDoors;

                std::cout << "Enter vehicle make: ";
                std::cin >> make;
                car->setMake(make);

                std::cout << "Enter vehicle model: ";
                std::cin >> model;
                car->setModel(model);

                std::cout << "Enter vehicle year: ";
                std::cin >> year;
                car->setYear(year);

                std::cout << "Enter vehicle price: ";
                std::cin >> price;
                car->setPrice(price);

                std::cout << "Enter number of doors: ";
                std::cin >> numDoors;
                car->setNumDoors(numDoors);

                fleet[fleetSize++] = car;
                std::cout << "Car added to fleet.\n";
            }
            else if (vehicleType == "truck")
            {
                Truck *truck = new Truck;
                std::string make, model;
                int year;
                float price;
                int payload, towingCapacity;

                std::cout << "Enter vehicle make: ";
                std::cin >> make;
                truck->setMake(make);

                std::cout << "Enter vehicle model: ";
                std::cin >> model;
                truck->setModel(model);

                std::cout << "Enter vehicle year: ";
                std::cin >> year;
                truck->setYear(year);

                std::cout << "Enter vehicle price: ";
                std::cin >> price;
                truck->setPrice(price);

                std::cout << "Enter payload in pounds: ";
                std::cin >> payload;
                truck->setPayload(payload);

                std::cout << "Enter towing capacity in pounds: ";
                std::cin >> towingCapacity;
                truck->setTowingCapacity(towingCapacity);

                fleet[fleetSize++] = truck;
                std::cout << "Truck added to fleet.\n";
            }
            else
            {
                std::cout << "Invalid vehicle type. Please enter 'car' or 'truck'.\n";
            }
            break;
        }

        case 2:
        {
            std::string make, model;
            std::cout << "Enter vehicle make: ";
            std::cin >> make;
            std::cout << "Enter vehicle model: ";
            std::cin >> model;

            bool found = false;
            for (int i = 0; i < fleetSize; ++i)
            {
                if (fleet[i]->getMake() == make && fleet[i]->getModel() == model)
                {
                    delete fleet[i]; // Free memory
                    for (int j = i; j < fleetSize - 1; ++j)
                    {
                        fleet[j] = fleet[j + 1];
                    }
                    --fleetSize;
                    std::cout << "Vehicle removed from fleet.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Vehicle not found in the fleet.\n";
            }
            break;
        }

        case 3:
        {
            std::string make, model;
            std::cout << "Enter vehicle make: ";
            std::cin >> make;
            std::cout << "Enter vehicle model: ";
            std::cin >> model;

            bool found = false;
            for (int i = 0; i < fleetSize; ++i)
            {
                if (fleet[i]->getMake() == make && fleet[i]->getModel() == model)
                {
                    // Display vehicle details and tax payable
                    fleet[i]->displayDetails();
                    std::cout << "Tax Payable: $" << fleet[i]->calculateTax() << "\n";
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Vehicle not found in the fleet.\n";
            }
            break;
        }
        case 4:
            std::cout << "Exiting program.\n";
            // Free allocated memory for vehicles
            for (int i = 0; i < fleetSize; ++i)
            {
                delete fleet[i];
            }
            return 0;

        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}