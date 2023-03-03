//
// Created by Jan Skwarczenski on 27.02.2023.
//

#ifndef CAR_DEALER_FACTORY_H
#define CAR_DEALER_FACTORY_H

#include <memory>
#include <vector>

#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bicycle.h"

class Factory
{
public:
    Factory(float = 500000); //default budget of factory

    void order();
    float powerMenu(int);
    std::string colorMenu();
    void show();
    bool sell();
    void driveVehicle();
    void refuelVehicle();
    void toPainting();
    void fromPainting(std::unique_ptr<Vehicle>&);
    void save();
    void read();
    bool checkId(int);
    std::unique_ptr<Vehicle> VehicleDeparting ;
    unsigned int getSize();

private:
    float budgetFactory;
    std::vector<std::unique_ptr<Vehicle>> parkingFactory;
};


#endif //CAR_DEALER_FACTORY_H
