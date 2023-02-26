//
// Created by Jan Skwarczenski on 26.02.2023.
//

#ifndef CAR_DEALER_MOTORCYCLE_H
#define CAR_DEALER_MOTORCYCLE_H

#include "MotorVehicle.h"

class Motorcycle : public MotorVehicle
{
public:
    Motorcycle(char, std::string, std::string, float, float, int, int, float, float, float);
    virtual void drive();
    virtual void refuel();

protected:
    virtual void printOn(std::ostream& o) const;
    virtual void saveOn(std::ofstream& o) const;
};


#endif //CAR_DEALER_MOTORCYCLE_H
