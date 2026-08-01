#include "racer.h"
#include <iostream>
using namespace std;

racer::racer() {

}
 racer::racer(int car_number,
        std::string full_name,
        int age,
        std::string racing_team, 
        float speed,
        float capacity,
        int racesCompleted,
        int lapsCompleted) 

         :car(car_number,
            full_name,
            age,
            racing_team,
            speed, 
            capacity)
         {
            this->racesCompleted = racesCompleted;
            this->lapsCompleted = lapsCompleted;
        }

        int racer::getRacesCompleted() const {
            return racesCompleted;
        }
        int racer::getLapsCompleted() const {
            return lapsCompleted;
        }
        void racer::setRacesCompleted(int racesCompleted) {
            this->racesCompleted = racesCompleted;
        }
        void racer::setLapsCompleted(int lapsCompleted) {
            this->lapsCompleted = lapsCompleted;
        }

        float racer::calculatePerformance() const {
            return (speed * 10.0) + capacity;
        }

        void racer::displayInfo() const {
            cout <<"type:racer"<< endl;
            cout << "Car Number: " << car_number << endl;
            cout << "Full Name: " << full_name << endl;
            cout << "Age: " << age << endl;
            cout << "Racing Team: " << racing_team << endl;
            cout << "Speed: " << speed << endl;
            cout << "Capacity: " << capacity << endl;
            cout << "Races Completed: " << racesCompleted << endl;
            cout << "Laps Completed: " << lapsCompleted << endl;
            cout << "Performance score: " << calculatePerformance() << endl;
        }
        
