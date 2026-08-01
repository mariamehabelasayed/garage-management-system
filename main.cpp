#include <iostream>
#include "garage.h"
#include "racer.h"
#include "supportVehicle.h"

using namespace std;

int main()
{
    garage G;

    G.loadFromFile();

    int choice;

    do
    {
        cout << "\n GARAGE MANAGEMENT SYSTEM \n";
        cout << "1. Check In Car\n";
        cout << "2. View Garage\n";
        cout << "3. Update Car\n";
        cout << "4. Retire Car\n";
        cout << "5. Search Car\n";
        cout << "6. Garage Report\n";
        cout << "7. Save Data\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        
            case 1:
{
    int carNumber;
    string fullName;
    int age;
    string team;
    float speed;
    float capacity;
    int type;

    cout << "Car Number: ";
    cin >> carNumber;

if (G.carExists(carNumber))
{
    cout << "Car Number already exists!" << endl;
    break;
}

    cin.ignore();

    cout << "Full Name: ";
    getline(cin, fullName);

    cout << "Age: ";
    cin >> age;

    cin.ignore();

    cout << "Racing Team: ";
    getline(cin, team);

    cout << "Speed: ";
    cin >> speed;

    cout << "Capacity: ";
    cin >> capacity;

    cout << "\nChoose Type\n";
    cout << "1. Racer\n";
    cout << "2. Support Vehicle\n";
    cin >> type;
    if (age <= 0)
{
    cout << "Invalid Age!" << endl;
    break;
}

if (speed <= 0)
{
    cout << "Invalid Speed!" << endl;
    break;
}

if (capacity <= 0)
{
    cout << "Invalid Capacity!" << endl;
    break;
}

    if (type == 1)
    {
        int racesCompleted;
        int lapsCompleted;

        cout << "Races Completed: ";
        cin >> racesCompleted;

        cout << "Laps Completed: ";
        cin >> lapsCompleted;

        racer* r = new racer(
            carNumber,
            fullName,
            age,
            team,
            speed,
            capacity,
            racesCompleted,
            lapsCompleted
        );

        G.checkIn(r);
    }
    else if (type == 2)
    {
        int crewSize;
        float reliabilityRating;

        cout << "Crew Size: ";
        cin >> crewSize;

        cout << "Reliability Rating: ";
        cin >> reliabilityRating;

        supportVehicle* s = new supportVehicle(
            carNumber,
            fullName,
            age,
            team,
            speed,
            capacity,
            crewSize,
            reliabilityRating
        );

        G.checkIn(s);
    }
    else
    {
        cout << "Invalid Type!" << endl;
    }

    G.saveToFile();

    break;
}

        case 2:
            G.viewGarage();
            break;

        case 3:
        {
            int number;
            cout << "Enter Car Number: ";
            cin >> number;
            G.updateCar(number);
            G.saveToFile();
            break;
        }

        case 4:
        {
            int number;
            cout << "Enter Car Number: ";
            cin >> number;
            G.retireCar(number);
            G.saveToFile();
            break;
        }

        case 5:
        {
            int number;
            cout << "Enter Car Number: ";
            cin >> number;
            G.searchCar(number);
            break;
        }

        case 6:
            G.garageReport();
            break;

        case 7:
            G.saveToFile();
            break;

        case 8:
            G.saveToFile();
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}