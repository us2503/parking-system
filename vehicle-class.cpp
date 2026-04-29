#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Vehicle
{
private:
    string vehicleNumber;
    string ownerName;
    string vehicleType;
    int hours;

public:
    Vehicle()
    {
        vehicleNumber = "";
        ownerName = "";
        vehicleType = "";
        hours = 0;
    }

    void inputVehicle()
    {
        cout << "Enter Vehicle Number: ";
        cin >> vehicleNumber;

        cout << "Enter Owner Name: ";
        cin.ignore();
        getline(cin, ownerName);

        cout << "Enter Vehicle Type (Car/Bike/Truck): ";
        cin >> vehicleType;

        transform(vehicleType.begin(), vehicleType.end(), vehicleType.begin(), ::tolower);

        cout << "Enter Parking Hours: ";
        cin >> hours;

        if (hours < 0) hours = 0;
    }

    string getVehicleNumber() { return vehicleNumber; }
    int getHours() { return hours; }
    string getVehicleType() { return vehicleType; }

    void displayVehicle()
    {
        cout << "Vehicle No: " << vehicleNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Hours Parked: " << hours << endl;
    }
};
