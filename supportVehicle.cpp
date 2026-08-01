#include "supportVehicle.h"
#include <iostream>
using namespace std;

supportVehicle::supportVehicle() {

}
 supportVehicle::supportVehicle(int car_number,
        std::string full_name,
        int age,
        std::string racing_team, 
        float speed,
        float capacity,
        int crewSize,
        float reliabilityRating) 

         :car(car_number,
            full_name,
            age,
            racing_team,
            speed, 
            capacity)
         {
            this->crewSize = crewSize;
            this->reliabilityRating = reliabilityRating;
        }

        int supportVehicle::getCrewSize() const {
            return crewSize;
        }
        float supportVehicle::getReliabilityRating() const {
            return reliabilityRating;
        }
        void supportVehicle::setCrewSize(int crewSize) {
            this->crewSize = crewSize;
        }
        void supportVehicle::setReliabilityRating(float reliabilityRating) {
            this->reliabilityRating = reliabilityRating;
        }

        float supportVehicle::calculatePerformance() const {
            return (speed * 5.0) + (capacity * 5.0);
        }

        void supportVehicle::displayInfo() const {
            cout <<"type:supportVehicle"<< endl;
            cout << "Car Number: " << car_number << endl;
            cout << "Full Name: " << full_name << endl;
            cout << "Age: " << age << endl;
            cout << "Racing Team: " << racing_team << endl;
            cout << "Speed: " << speed << endl;
            cout << "Capacity: " << capacity << endl;
            cout << "Crew Size: " << crewSize << endl;
            cout << "Reliability Rating: " << reliabilityRating << endl;
            cout << "Performance score: " << calculatePerformance() << endl;
        }