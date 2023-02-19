//
// Created by Jan Skwarczenski on 19.02.2023.
//

#ifndef CAR_DEALER_MOTORVEHICLE_H
#define CAR_DEALER_MOTORVEHICLE_H

#include "Vehicle.h"

class MotorVehicle : public Vehicle
{
public:
    MotorVehicle(char, std::string, std::string, float, float, int, int, float, float, float);
    int controlDriveMV(int &k, float &m, float &f);
    int controlRefuel(int &l, int &c, float &m);

protected:
    int tank;
    float fuel, fuelUsage, power;
};

struct ErrorToMany { std::string message; };

struct ErrorToLittle { std::string message; };


#endif //CAR_DEALER_MOTORVEHICLE_H
