//
// Created by Jan Skwarczenski on 19.02.2023.
//

#ifndef CAR_DEALER_VEHICLE_H
#define CAR_DEALER_VEHICLE_H

#include <cassert>
#include <string>
#include <fstream>

class Vehicle
{
public:
    Vehicle(char, std::string, std::string, float, float, int = 0);
    virtual void drive() = 0;
    virtual void refuel() = 0;
    void changePrice();
    void repaint(std::string);
    friend std::ostream& operator<< (std::ostream& o, Vehicle const& b);
    friend std::ostream& operator<< (std::ofstream& o, Vehicle const& b);
    int controlTypeINT(std::string &k);

    template<typename T>
    T getter(char info);

protected:
    virtual void printOn(std::ostream& o) const = 0;
    virtual void saveOn(std::ofstream& o) const = 0;
    char type;
    std::string model, color;
    float price, capacity; //[PLN], [l]
    int mileage;
};

template <>
inline int Vehicle::getter(char info)
{
    assert(info=='a');
    return mileage;
}

template <>
inline char Vehicle::getter(char info)
{
    assert(info=='t');
    return type;
}

template <>
inline float Vehicle::getter(char info)
{
    assert(info=='p');
    return price;
}

template <>
inline std::string Vehicle::getter(char info)
{
    assert(info=='m');
    return model;
}

struct ErrorOfType { std::string message; };

#endif //CAR_DEALER_VEHICLE_H
