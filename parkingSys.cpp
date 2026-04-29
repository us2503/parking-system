class ParkingSystem
{
private:
    Vehicle vehicles[50];
    int capacity;
    int count;

public:
    ParkingSystem(int cap)
    {
        if (cap > 50) cap = 50;
        if (cap <= 0) cap = 10;
        capacity = cap;
        count = 0;
    }

    void parkVehicle()
    {
        if (count >= capacity)
        {
            cout << "Parking Full!" << endl;
            return;
        }

        vehicles[count].inputVehicle();
        count++;

        cout << "Vehicle Parked Successfully!" << endl;
    }

    void removeVehicle()
    {
        string number;
        cout << "Enter Vehicle Number to Remove: ";
        cin >> number;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i].getVehicleNumber() == number)
            {
                Billing* billPtr;
                string type = vehicles[i].getVehicleType();

                if (type == "car")
                    billPtr = new CarBilling();
                else if (type == "bike")
                    billPtr = new BikeBilling();
                else if (type == "truck")
                    billPtr = new TruckBilling();
                else
                    billPtr = new Billing();

                int bill = billPtr->calculateBill(vehicles[i].getHours());
                delete billPtr;

                for (int j = i; j < count - 1; j++)
                {
                    vehicles[j] = vehicles[j + 1];
                }

                count--;

                cout << "Vehicle Removed Successfully!" << endl;
                cout << "Parking Bill: " << bill << endl;
                return;
            }
        }

        cout << "Vehicle Not Found!" << endl;
    }

    void searchVehicle()
    {
        string number;
        cout << "Enter Vehicle Number to Search: ";
        cin >> number;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i].getVehicleNumber() == number)
            {
                vehicles[i].displayVehicle();
                return;
            }
        }

        cout << "Vehicle Not Found!" << endl;
    }

    void displayAllVehicles()
    {
        if (count == 0)
        {
            cout << "Parking Empty!" << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "\nSlot " << i + 1 << endl;
            vehicles[i].displayVehicle();
        }
    }

    void displayStatus()
    {
        cout << "Total Capacity: " << capacity << endl;
        cout << "Parked Vehicles: " << count << endl;
        cout << "Available Slots: " << capacity - count << endl;
    }
};

int main()
{
    int size, choice;

    cout << "Enter Parking Capacity (Max 50): ";
    cin >> size;

    ParkingSystem parking(size);

    do
    {
        cout << "\n===== SMART PARKING MENU =====" << endl;
        cout << "1. Park Vehicle" << endl;
        cout << "2. Remove Vehicle" << endl;
        cout << "3. Search Vehicle" << endl;
        cout << "4. Display All Vehicles" << endl;
        cout << "5. Display Parking Status" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: parking.parkVehicle(); break;
        case 2: parking.removeVehicle(); break;
        case 3: parking.searchVehicle(); break;
        case 4: parking.displayAllVehicles(); break;
        case 5: parking.displayStatus(); break;
        case 6: cout << "Thank You!" << endl; break;
        default: cout << "Invalid Choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}