//
// Created by Jan Skwarczenski on 21.02.2023.
//

#include "Bicycle.h"

#include <iostream>

using namespace std;

Bicycle::Bicycle(char type, string model, string color, float price, float capacity, int mileage, bool rack)
: Vehicle(type, model, color, price, capacity, mileage), rack(rack)
{
    if(rack)
        this->capacity = 10;
    else
        this->capacity = 0;
}

void Bicycle::drive()
{
    string km;
    cout << "How many kilometers do you want to ride? " << endl;
    cin >> km;

    try
    {
        int change = controlTypeINT(km);
        mileage += controlDriveB(change);
        cout << "You've reached your destination" << endl;
    }
    catch(ErrorOfType &m)
    {
        cerr << "Invalid value" << endl;
        cerr << m.message << endl;
    }
    catch(ErrorOfValue &m)
    {
        cerr << "Invalid value" << endl;
        cerr << m.message << endl;
    }

    cout << "End of the bicycle ride" << endl;
}

void Bicycle::refuel()
{
    cout << "I am a bicycle! You fuel me with your muscles, so you don't have to worry about refueling :)" << endl;
}

void Bicycle::printOn(ostream &o) const
{
    o << "Model: " << model << " Color: " << color << " Price: " << price << " Capacity: " << capacity << " Mileage: " <<
      mileage << " Rack: " << rack << endl;
}

void Bicycle::saveOn(ofstream &o) const
{
    o << type << " " << model << " " << color << " " << price << " " << capacity << " " << mileage << " " << rack << endl;
}

int Bicycle::controlDriveB(int &k)
{
    if(k >= 0)
        return k;
    else
    {
        ErrorOfType sender;
        sender.message = "You cannot drive a negative number of km";
        throw sender;
    }
}