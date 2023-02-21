//
// Created by Jan Skwarczenski on 21.02.2023.
//

#ifndef CAR_DEALER_BICYCLE_H
#define CAR_DEALER_BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle
{
public:
    Bicycle(char, std::string, std::string, float, float, int, bool);
    virtual void drive();
    virtual void refuel();
    int controlDriveB(int &k);

protected:
    virtual void printOn(std::ostream& o) const;
    virtual void saveOn(std::ofstream& o) const;

private:
    bool rack;
};

struct ErrorOfValue { std::string message; };


#endif //CAR_DEALER_BICYCLE_H
