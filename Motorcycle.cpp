//
// Created by Jan Skwarczenski on 26.02.2023.
//

#include <iostream>

#include "Motorcycle.h"

using namespace std;

Motorcycle::Motorcycle(char type, std::string model, std::string color, float price, float capacity, int mileage,
                       int tank, float fuel, float fuelUsage, float power)
                       : MotorVehicle(type, model, color, price, capacity, mileage, tank, fuel, fuelUsage, power) {}

void Motorcycle::drive()
{
    string km;
    float s = fuelUsage / 100;
    cout << "How many kilometers do you want to ride? " << endl;

    cin >> km;

    try
    {
        int change = controlTypeINT(km);
        int value = controlDriveMV(change, s, fuel);
        cout << "You have reached your destination, fuel usage: " << value * s << " l" << endl;
        mileage += value;
        fuel -= s * value;
    }
    catch(ErrorToLittle &m)
    {
        cerr << "Invalid value" << endl;
        cerr << m.message << endl;
    }
    catch(ErrorToMany &m)
    {
        cerr << "No fuel, you have driven " << fuel / s << " km." << endl;
        cerr << m.message << endl;
        mileage += fuel / s;
        fuel = 0;
    }
    catch(ErrorOfType &m)
    {
        cerr << "Invalid value" << endl;
        cerr << m.message << endl;
    }

    cout << "End of drive motorcycle" << endl;
}

void Motorcycle::refuel()
{
    string l;
    cout << "How many liters do you want to refuel? " << endl;
    cin >> l;

    try
    {
        int change = controlTypeINT(l);
        int value = controlRefuel(change, tank, fuel);
        fuel += value;
        cout << "You have refueled  " << value << " l" << endl;
    }
    catch(ErrorToMany &m)
    {
        cerr << "Tank is full. You have refueled  " << tank-fuel << " l" << endl;
        cerr << m.message << endl;
        fuel = tank;
    }
    catch(ErrorToLittle &m)
    {
        cerr << "Invalid value" << endl;
        cerr << m.message << endl;
        fuel = tank;
    }
    catch(ErrorOfType &m)
    {
        cerr << "Invalid value" << endl;
        cerr << m.message << endl;
    }

    cout << "End of refuel motorcycle" << endl;
}

void Motorcycle::printOn(ostream &o) const
{
    o << "Model: " << model << " Color: " << color << " Price: " << price << " Capacity: " << capacity << " Mileage: " <<
      mileage << " Tank size: " << tank << " Fuel: " << fuel << " Fuel usage: " << fuelUsage << " Power: " << power << endl;
}

void Motorcycle::saveOn(ofstream &o) const
{
    o << type << " " << model << " " << color << " " << price << " " << capacity << " " << mileage << " " << tank <<
      " " << fuel << " " << fuelUsage << " " << power << endl;
}


