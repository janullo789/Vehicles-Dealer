//
// Created by Jan Skwarczenski on 27.02.2023.
//

#include <iostream>

#include "Factory.h"

using namespace std;

Factory::Factory(float budgetFactory) : budgetFactory(budgetFactory) {}

void Factory::order()
{
    char choiceType;
    char choiceModel;

    string model;
    string color = "White";
    float  capacity = 0;
    int mileage = 0;
    int tank;
    float fuel;
    float price;
    float power;
    float fuelUsage;
    int numberOfDoors;
    bool rack = false;

    do
    {
        cout << "Type of vehicle:" << endl <<
                "1. Car" << endl <<
                "2. Motorcycle" << endl <<
                "3. Bicycle" << endl;

        cin >> choiceType;

        switch (choiceType)
        {
            case '1':
                do
                {
                    cout << "Model of car:" << endl <<
                            "1. Passat" << endl <<
                            "2. Golf" << endl <<
                            "3. Polo" << endl <<
                            "4. Tiguan" << endl;

                    cin >> choiceModel;

                    switch (choiceModel)
                    {
                        case '1':
                            model = "Passat";
                            tank = 55;
                            price = 80000;
                            capacity = 565;
                            break;
                        case '2':
                            model = "Golf";
                            tank = 50;
                            price = 70000;
                            capacity = 380;
                            break;
                        case '3':
                            model = "Polo";
                            tank = 45;
                            price = 60000;
                            capacity = 320;
                            break;
                        case '4':
                            model = "Tiguan";
                            tank = 65;
                            price = 95000;
                            capacity = 655;
                            break;
                        default:
                            cout << "Enter value between 1 - 4" << endl;
                            break;
                    }
                }
        }
    }
}