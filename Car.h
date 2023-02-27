//
// Created by Jan Skwarczenski on 27.02.2023.
//

#ifndef CAR_DEALER_CAR_H
#define CAR_DEALER_CAR_H

#include "MotorVehicle.h"

class Car : public MotorVehicle
{
public:
    Car(char, std::string, std::string, float, float, int, int, float, float, float, int);
    virtual void drive();
    virtual void refuel();

protected:
    virtual void printOn(std::ostream& o) const;
    virtual void saveOn(std::ofstream& o) const;

private:
    int numberOfDoors;

};


#endif //CAR_DEALER_CAR_H
