#pragma once
#include <string>

class car{
      protected:
      int car_number;
      std::string full_name;
      int age;
      std::string racing_team;
      float speed;
      float capacity;
      
      
      public:
      car();//decleration of the constructor
      car(int car_number,
        std::string full_name,
        int age,
        std::string racing_team, 
        float speed,
        float capacity); //parameterized constructor


//getter
        int getcarNumber() const;
        std::string getfullName() const;
        int getAge() const;
        std::string getracingTeam() const;
        float getSpeed() const;
        float getCapacity() const;
        
//setter 
            void setcarNumber(int car_number);
            void setfullName(std::string full_name);
            void setAge(int age);
            void setracingTeam(std::string racing_team);
            void setSpeed(float speed);
            void setCapacity(float capacity);
            
//polymorphism
            virtual float calculatePerformance() const = 0; 
            virtual void displayInfo() const = 0;


};