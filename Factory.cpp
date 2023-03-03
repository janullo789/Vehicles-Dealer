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

    char type;
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

                    fuel = 10;
                } while (choiceModel != '1' && choiceModel != '2' && choiceModel != '3' && choiceModel != '4');

                power = powerMenu(choiceType);

                fuelUsage = (power / 100) * 6;
                price += (power / 10);
                budgetFactory -= price * 0.7; //because the factory has to make money

                color = colorMenu();

                do
                {
                    cout << "Insert number of doors (3/5): " << endl;
                    cin >> numberOfDoors;
                } while (numberOfDoors != '3' && numberOfDoors != '5');

                type = 'C';

                if ((budgetFactory - price) > 0)
                {
                    parkingFactory.push_back(
                            make_unique<Car>(type, model, color, price, capacity, mileage, tank, fuel, fuelUsage, power,
                                             numberOfDoors));
                } else
                    cout << "Your factory budget does not allow you to produce the selected vehicle." << endl <<
                         "Sell your current vehicles!" << endl;
                break;

            case 2:
                do
                {
                    cout << "Model of motorcycle:" << endl <<
                         "1. Simson" << endl <<
                         "2. Junak" << endl <<
                         "3. Yamaha" << endl <<
                         "4. Harley Davidson" << endl;

                    cin >> choiceModel;

                    switch (choiceModel)
                    {
                        case '1':
                            model = "Simson";
                            tank = 7;
                            price = 5000;
                            capacity = 10;
                            break;
                        case '2':
                            model = "Junak";
                            tank = 10;
                            price = 9000;
                            capacity = 20;
                            break;
                        case '3':
                            model = "Yamaha";
                            tank = 12;
                            price = 16000;
                            capacity = 25;
                            break;
                        case '4':
                            model = "Harley Davidson";
                            tank = 15;
                            price = 23000;
                            capacity = 40;
                            break;
                        default:
                            cout << "Enter value between 1 - 4" << endl;
                            break;
                    }

                    fuel = 4;

                } while (choiceModel != '1' && choiceModel != '2' && choiceModel != '3' && choiceModel != '4');

                power = powerMenu(choiceType);

                fuelUsage = (power / 100) * 6;
                price += (power / 10);
                budgetFactory -= price * 0.7; //because the factory has to make money

                color = colorMenu();

                type = 'M';

                if ((budgetFactory - price) > 0)
                {
                    parkingFactory.push_back(
                            make_unique<Motorcycle>(type, model, color, price, capacity, mileage, tank, fuel, fuelUsage,
                                                    power));
                } else
                    cout << "Your factory budget does not allow you to produce the selected vehicle." << endl <<
                         "Sell your current vehicles!" << endl;
                break;

            case 3:
                do
                {
                    cout << "Model of bicycle:" << endl <<
                         "1. Kross" << endl <<
                         "2. Trek" << endl <<
                         "3. Cannondale " << endl <<
                         "4. Scott" << endl;

                    cin >> choiceModel;

                    switch (choiceModel)
                    {
                        case '1':
                            model = "Kross";
                            price = 2000;
                            break;
                        case '2':
                            model = "Trek";
                            price = 4000;
                            break;
                        case '3':
                            model = "Cannondale";
                            price = 6000;
                            break;
                        case '4':
                            model = "Scott";
                            price = 8000;
                            break;
                        default:
                            cout << "Enter value between 1 - 4" << endl;
                            break;
                    }
                } while (choiceModel != '1' && choiceModel != '2' && choiceModel != '3' && choiceModel != '4');

                color = colorMenu();

                type = 'B';

                if ((budgetFactory - price) > 0)
                {
                    parkingFactory.push_back(make_unique<Bicycle>(type, model, color, price, capacity, mileage, rack));
                } else
                    cout << "Your factory budget does not allow you to produce the selected vehicle." << endl <<
                         "Sell your current vehicles!" << endl;
                break;
            default:
                cout << "Enter value between 1 - 3" << endl;
                break;

        }
    } while (choiceType != '1' && choiceType != '2' && choiceType != '3');
}

float Factory::powerMenu(int fType)
{
    float fPower;
    do
    {
        cout << "Our company produce power engine between ";
        switch (fType)
        {
            case 1:
                cout << "90 - 250 [HP]" << endl;
                break;
            case 2:
                cout << "10 - 50 [HP]" << endl;
                break;
        }
        cout << "Select power engine" << endl;
        cin >> fPower;
    } while (((fPower < 90 || fPower > 250) && fType == 1) || ((fPower < 10 || fPower > 50) && fType == 2));
    return fPower;
}

string Factory::colorMenu()
{
    int FChoiceColor;
    string fColor;
    cout << "Select number of color of vehicle" << endl;
    cout << "1. White" << endl <<
            "2. Black" << endl <<
            "3. Silver" << endl <<
            "4. Red" << endl;
    cin >> FChoiceColor;

    switch (FChoiceColor)
    {
        case 1:
            fColor = "White";
            break;
        case 2:
            fColor = "Black";
            break;
        case 3:
            fColor = "Silver";
            break;
        case 4:
            fColor = "Red";
        default:
            cout << "Wrong number, set default value (white)";
            break;
    }
    return fColor;
}

void Factory::show()
{
    unsigned int size = parkingFactory.size();   //size of vector

    if (size == 0)
        cout << "Your factory is empty" << endl;
    else
        for(unsigned int i = 0; i < size; i++)
            cout << i+1 << ". " <<*(parkingFactory[i]);

    cout << "Budget of factory " << budgetFactory << "PLN" << endl;
}

bool Factory::sell()
{
    bool check = false;

    if(!parkingFactory.empty())
    {
        int nr;
        do
        {
            cout << "Enter number of car park for sale (1 - " << parkingFactory.size() << "):" << endl;
            cin >> nr;
        } while (!checkId(nr));

        budgetFactory += parkingFactory[(nr - 1)]->getter<float>('c');
        char checkType = parkingFactory[(nr - 1)]->getter<char>('r');

        auto it = next(begin(parkingFactory), (nr - 1));

        if(checkType == 'M' || checkType == 'S')    //we only care about uploading the motor vehicle to the parkingCity vector
        {                                                   //because the car dealership can't buy a bike anyway
            VehicleDeparting = move(*it);
            check = true;     //the program, after calling the method, knows whether it sold a motor vehicle or a bicycle
        }

        parkingFactory.erase(it);
    }
    else
        cout << "Your factory is empty" << endl;

    return check;
}

bool Factory::checkId(int nr)
{
    if((nr >= 1) && (nr <= parkingFactory.size()))
        return true;
    return false;
}

void Factory::driveVehicle()
{
    if(!parkingFactory.empty())
    {
        int nr;
        do
        {
            cout << "Enter no. the parking space of the vehicle you want to drive: " << endl;
            cin >> nr;
        } while (!checkId(nr));


        parkingFactory[(nr - 1)]->drive();
    }
    else
        cout << "Your factory is empty" << endl;
}

void Factory::refuelVehicle()
{
    if(!parkingFactory.empty())
    {
        int nr;
        do
        {
            cout << "Enter no. parking space of the vehicle you want to refuel: " << endl;
            cin >> nr;
        } while (!checkId(nr));

        parkingFactory[(nr - 1)]->refuel();
    }
    else
        cout << "Your factory is empty" << endl;
}

void Factory::toPainting()
{
    if(!parkingFactory.empty())
    {
        int nr;
        do
        {
            cout << "Enter no. the parking space of the vehicle you want to paint (1 - " << parkingFactory.size() << "):" << endl;
            cin >> nr;
        } while (!checkId(nr));

        auto it = next(begin(parkingFactory), (nr - 1));
        VehicleDeparting = move(*it);
        parkingFactory.erase(it);

    }
    else
        cout << "Your factory is empty" << endl;
}

void Factory::fromPainting(std::unique_ptr<Vehicle> & p)
{
    parkingFactory.push_back(move(p));
}

void Factory::save()
{
    unsigned int size = parkingFactory.size();

    ofstream fileP;
    fileP.open("parkingFactorytxt", ofstream::out);

    for (unsigned int i = 0; i < size; i++)
        fileP << *(parkingFactory[i]);

    fileP.close();

    ofstream fileB;
    fileB.open("budgetFactory.txt", ofstream::out);

    fileB << budgetFactory;

    fileB.close();
}

void Factory::read()
{
    ifstream fileP;
    fileP.open("parkingFactory.txt", ios::in);

    if(fileP.is_open())
    {
        char type;
        std::string model;
        std::string color;
        float price;
        float capacity;
        int mileage;
        int tank;
        float fuel;
        float fuelUsage;
        float power;
        char numberOfDoors;
        bool rack;

        while (fileP >> type >> model >> color >> price >> capacity >> mileage)
        {
            switch(type)
            {
                case 'C':
                    fileP >> tank >> fuel >> fuelUsage >> power >> numberOfDoors;
                    parkingFactory.push_back(
                            make_unique<Car>(type, model, color, price, capacity, mileage, tank, fuel, fuelUsage, power,
                                             numberOfDoors));
                    break;
                case 'M':
                    fileP >> tank >> fuel >> fuelUsage >> power;
                    parkingFactory.push_back(
                            make_unique<Motorcycle>(type, model, color, price, capacity, mileage, tank, fuel, fuelUsage,
                                                    power));
                    break;
                case 'B':
                    fileP >> rack;
                    parkingFactory.push_back(
                            make_unique<Bicycle>(type, model, color, price, capacity, mileage, rack));
                    break;
                default:
                    cout << "Cannot read vehicle of this type" << endl;
            }
        }

        fileP.close();
    }
    else
        cout << "Cannot open file parkingFactory.txt" << endl;

    ifstream fileB;
    fileB.open("budgetFactory.txt", ios::in);

    if(fileB.is_open())
    {
        if (!fileB.good())
            cout << "Budget set on default value" << endl;
        else
            fileB >> budgetFactory;

        fileB.close();
    }
    else
        cout << "Cannot open file budgetFactory.txt" << endl;
}

unsigned int Factory::getSize()
{
    return parkingFactory.size();
}