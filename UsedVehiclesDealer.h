//
// Created by Jan Skwarczenski on 03.03.2023.
//

#ifndef CAR_DEALER_USEDVEHICLESDEALER_H
#define CAR_DEALER_USEDVEHICLESDEALER_H

#include <vector>
#include <memory>
#include <iostream>

#include "Vehicle.h"

class UsedVehiclesDealer
{
public:
    UsedVehiclesDealer(float = 200000);
    void buy(std::vector<std::unique_ptr<Vehicle>>& listOfVehicle);
    void sell();
    void show();
    void driveVehicle();
    void refuelVehicle();
    void save();
    void read();
    bool checkId(int no, std::vector<std::unique_ptr<Vehicle>>& checkedVector);
    std::unique_ptr<Vehicle> vehicleForSell;
    unsigned int getSize();

private:
    float budgetDealer;
    std::vector<std::unique_ptr<Vehicle>> parkingDealer;

};


#endif //CAR_DEALER_USEDVEHICLESDEALER_H
