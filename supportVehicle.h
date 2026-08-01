#pragma once
#include "car.h"

class supportVehicle : public car {
    private:
        int crewSize;
        float reliabilityRating;
    
    public:

    supportVehicle();

    supportVehicle(int car_number,
        std::string full_name,
        int age,
        std::string racing_team, 
        float speed,
        float capacity,
        int crewSize,
        float reliabilityRating);
         
//getter
        int getCrewSize() const;
        float getReliabilityRating() const;
//setter
        void setCrewSize(int crewSize);
        void setReliabilityRating(float reliabilityRating);

        float calculatePerformance() const override;
        void displayInfo() const override;
        
    };