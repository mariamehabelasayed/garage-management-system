#include "garage.h"
#include "racer.h"
#include "supportVehicle.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;

garage::garage() {

}

void garage::checkIn(car* car) {
    cars.push_back(car);
    cout << "Car checked in successfully!" << endl;
};

void garage::viewGarage() {
    if (cars.empty()) {
        cout << "Garage is empty." << endl;
        return;
    }
    for (int i = 0; i < cars.size();i++){
        cars[i]->displayInfo();
        cout <<"           " <<endl;
    }
}

void garage::searchCar(int car_number) {
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i]->getcarNumber() == car_number) {
            cars[i]->displayInfo();
            return;
        }
    }
    cout << "Car not found." << endl;
};
void garage::updateCar(int car_number) {
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i]->getcarNumber() == car_number) {
            std::string full_name;
            int age;
            std::string racing_team;
            float speed;
            float capacity;

            std::cout << "Enter new full name: ";
            std::cin >> full_name;
            std::cout << "Enter new age: ";
            std::cin >> age;
            std::cout << "Enter new racing team: ";
            std::cin >> racing_team;
            std::cout << "Enter new speed: ";
            std::cin >> speed;
            std::cout << "Enter new capacity: ";
            std::cin >> capacity;

            cars[i]->setfullName(full_name);
            cars[i]->setAge(age);
            cars[i]->setracingTeam(racing_team);
            cars[i]->setSpeed(speed);
            cars[i]->setCapacity(capacity);
            cars[i]->getcarNumber();

            cout << "Car information updated successfully!" << endl;
            return;
        }
    }
    std::cout << "Car not found." << std::endl;
};

void garage::retireCar(int car_number) {
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i]->getcarNumber() == car_number) {
            delete cars[i]; 
            cars.erase(cars.begin() + i);
            cout << "Car retired successfully!" << endl;
            return;
        }
    }
    cout << "Car not found." << endl;
}
void garage::garageReport() {
    if (cars.empty()) {
        cout << "Garage is empty." << endl;
        return;
    }
    cout << "Garage Report:" << endl;
    cout<< "total number of cars: " << cars.size() << endl;
float totalPerformance = 0.0;
    for (int i = 0; i < cars.size(); i++) {
        totalPerformance += cars[i]->calculatePerformance();
    }
    cout << "averagePerformance: " << totalPerformance / cars.size() << endl;


}
void garage::saveToFile(){

    std::ofstream outFile("garage.txt");
    if (!outFile.is_open()){
        std::cout << "cannot open file" << std::endl;
        return;
        
}
for (int i = 0; i < cars.size(); i++) {
        racer* r= dynamic_cast<racer*>(cars[i]);
        if (r!= nullptr) {
            outFile << "racer" << std::endl;
            outFile << r->getcarNumber() << std::endl;
            outFile << r->getfullName() << std::endl;
            outFile << r->getAge() << std::endl;
            outFile << r->getracingTeam() << std::endl;
            outFile << r->getSpeed() << std::endl;
            outFile << r->getCapacity() << std::endl;
            outFile << r->getRacesCompleted() << std::endl;
            outFile << r->getLapsCompleted() << std::endl;
        }
        else {
            supportVehicle* s = dynamic_cast<supportVehicle*>(cars[i]);
            if (s != nullptr) {
                outFile << "supportVehicle" << std::endl;
                outFile << s->getcarNumber() << std::endl;
                outFile << s->getfullName() << std::endl;
                outFile << s->getAge() << std::endl;
                outFile << s->getracingTeam() << std::endl;
                outFile << s->getSpeed() << std::endl;
                outFile << s->getCapacity() << std::endl;
                outFile << s->getCrewSize() << std::endl;
                outFile << s->getReliabilityRating() << std::endl;
            }
        }
    }
    outFile.close();
    std::cout << "Garage data saved to file." << std::endl;
}

void garage::loadFromFile() {
    std::ifstream inFile("garage.txt");
    if (!inFile.is_open()) {
        std::cout << "Cannot open file." << std::endl;
        return;
    }
    std::string type;
    while (getline(inFile, type))
    {
        int car_number;
        std::string full_name;
        int age;
        std::string racing_team;
        float speed;
        float capacity;

        inFile >> car_number;
        inFile.ignore();

        getline(inFile, full_name);

        inFile >> age;
        inFile.ignore();

        getline(inFile, racing_team);

        inFile >> speed;
        inFile >> capacity;

        inFile.ignore();

        if (type=="racer")
        {
            int racesCompleted;
            int lapsCompleted;

            inFile >> racesCompleted;
            inFile >> lapsCompleted;
            inFile.ignore();

            racer* r = new racer(
                car_number,
                full_name,
                age,
                racing_team,
                speed,
                capacity,
                racesCompleted,
                lapsCompleted
            );

            cars.push_back(r);
        }
        else if (type=="supportVehicle")
        {
            int crewSize;
            float reliabilityRating;

            inFile >> crewSize;
            inFile >> reliabilityRating;
            inFile.ignore();

            supportVehicle* s = new supportVehicle(
                car_number,
                full_name,
                age,
                racing_team,
                speed,
                capacity,
                crewSize,
                reliabilityRating
            );

            cars.push_back(s);
        }
    }

    inFile.close();

    std::cout << "Garage data loaded successfully!" << std::endl;
}
bool garage::carExists(int car_number){
    for (const auto& car : cars) {
        if (car->getcarNumber() == car_number) {
            return true;
        }
    }
    return false;
}
