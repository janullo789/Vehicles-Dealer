//
// Created by Jan Skwarczenski on 19.02.2023.
//

#include "MotorVehicle.h"

using namespace std;

MotorVehicle::MotorVehicle(char type, std::string model, std::string color, float price, float capacity, int mileage,
                           int tank, float fuel, float fuelUsage, float power)
                           : Vehicle(type, model, color, price, capacity, mileage), tank(tank), fuel(fuel),
                           fuelUsage(fuelUsage), power(power) {}

int MotorVehicle::controlDriveMV(int &k, float &m, float &f)
{
    if(k >= 0)
    {
        if((f - m * k) < 0)
        {
            ErrorToMany sender;
            sender.message = "You have not enough fuel";
            throw sender;
        }
        else
        {
            return k;
        }
    }
    else
    {
        ErrorToLittle sender;
        sender.message = "You cannot drive negative value of km";
        throw sender;
    }
}

int MotorVehicle::controlRefuel(int &l, int &c, float &m)
{
    if(l >= 0)
    {
        if ((c - m) < l)
        {
            ErrorToMany sender;
            sender.message = "You cannot refuel that much fuel";
            throw sender;
        } else
        {
            m += l;
            return m;
        }
    }
    else
    {
        ErrorToLittle sender;
        sender.message = "You cannot refuel negative value of l";
        throw sender;
    }
}