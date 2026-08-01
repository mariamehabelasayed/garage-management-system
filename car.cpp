#include "car.h"
car::car(){

}

car::car(int car_number,
        std::string full_name,
        int age,
        std::string racing_team, 
        float speed,
        float capacity) 
    
{
    this->car_number=car_number;
    this->full_name=full_name;
    this->age=age;
    this->racing_team=racing_team;
    this->speed=speed;
    this->capacity=capacity;
}

//getter
int car::getcarNumber() const {
    return car_number;
}
std::string car::getfullName() const {
    return full_name;
}
std::string car::getracingTeam() const {
    return racing_team;
}
float car::getSpeed() const {
    return speed;
}
int car::getAge() const {
    return age;
}
float car::getCapacity() const {
    return capacity;
}
//setter
void car::setcarNumber(int car_number) {
    this->car_number = car_number;
}
void car::setfullName(std::string full_name) {
    this->full_name = full_name;
}
void car::setAge(int age) {
    this->age = age;
}
void car::setracingTeam(std::string racing_team) {
    this->racing_team = racing_team;
}
void car::setSpeed(float speed) {
    this->speed = speed;
}
void car::setCapacity(float capacity) {
    this->capacity = capacity;
}
