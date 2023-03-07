//
// Created by Jan Skwarczenski on 07.03.2023.
//

#ifndef CAR_DEALER_PAINTER_H
#define CAR_DEALER_PAINTER_H

#include <iostream>
#include <memory>
#include "Vehicle.h"

class Painter
{
public:
    Painter();
    Painter(std::unique_ptr<Vehicle>&);
    void painting();
    std::unique_ptr<Vehicle> fromPainting;

private:
    std::unique_ptr<Vehicle> paintingVehicle;
};


#endif //CAR_DEALER_PAINTER_H
