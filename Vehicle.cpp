//
// Created by Jan Skwarczenski on 19.02.2023.
//

#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(char type, std::string model, std::string color, float price, float capacity, int mileage)
: type(type), model(model), color(color), price(price), capacity(capacity), mileage(mileage) {}

void Vehicle::changePrice() { price *= 0.9; }

void Vehicle::changeMileage() { mileage /= 2; }

void Vehicle::repaint(COLOR newColor) { color = newColor; }

std::ostream& operator<< (ostream& o, Vehicle const& b)
{
    b.printOn(o);
    return o;
}

std::ostream& operator<< (ofstream& o, Vehicle const& b)
{
    b.saveOn(o);
    return o;
}

int Vehicle::controlTypeINT(string &k)
{
    try
    {
        size_t idx = 0;
        int x = stoi(k, &idx);
        return x;
    }
    catch(invalid_argument)
    {
        ErrorOfType sender;
        sender.message = "Insert value is not INT type";
        throw sender;
    }
    catch(invalid_argument)
    {
        ErrorOfType sender;
        sender.message = "Insert value is out of range";
        throw sender;
    }
}
