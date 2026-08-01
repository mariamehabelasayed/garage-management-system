#pragma once
#include <vector>
#include"car.h"

class garage {

    private:
        std::vector<car*> cars; 
    public:

        garage();
        void checkIn(car*car);
        void viewGarage();
        void searchCar(int car_number);
        void updateCar(int car_number);
        void retireCar(int car_number);
        void garageReport();
        void saveToFile();
        void loadFromFile();
        bool carExists(int car_number);
        
};
