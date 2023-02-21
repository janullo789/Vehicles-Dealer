//
// Created by Jan Skwarczenski on 21.02.2023.
//

#include "Bicycle.h"

using namespace std;

Bicycle::Bicycle(char type, string model, string color, float price, float capacity, int mileage, bool rack)
: Vehicle(type, model, color, price, capacity, mileage), rack(rack)
{
    if(rack)
        this->capacity = 10;
    else
        this->capacity = 0;
}

