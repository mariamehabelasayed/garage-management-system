#pragma once
#include "car.h"

class racer : public car {
       private:
       int racesCompleted;
       int lapsCompleted;

       public:

       racer();

       racer(int car_number,
        std::string full_name,
        int age,
        std::string racing_team, 
        float speed,
        float capacity,
        int racesCompleted,
        int lapsCompleted);
//getter
        int getRacesCompleted() const;
        int getLapsCompleted() const;
//setter
        void setRacesCompleted(int racesCompleted);
        void setLapsCompleted(int lapsCompleted);
//polymorphism
        float calculatePerformance() const override;
        void displayInfo() const override;
       };
