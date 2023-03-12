//
// Created by Jan Skwarczenski on 03.03.2023.
//

#include "UsedVehiclesDealer.h"

using namespace std;

UsedVehiclesDealer::UsedVehiclesDealer(float budgetDealer) : budgetDealer(budgetDealer) {}

void UsedVehiclesDealer::buy(std::vector<std::unique_ptr<Vehicle>> &listOfVehicle)
{
    unsigned int size = listOfVehicle.size();

    if (size == 0)
        cout << "No available vehicles available for purchase by used car dealer" << endl;
    else
    {
        for (unsigned int i = 0; i < size; i++)
            cout << i + 1 << ". " << *(listOfVehicle[i]);

        int no;
        do
        {
            cout << "Enter no. of vehicle for buy: " << endl;
            cin >> no;
        } while (!checkId(no, listOfVehicle));

        if (listOfVehicle[no - 1]->getter<float>('p') < budgetDealer)
        {
            auto it = next(begin(listOfVehicle), (no-1));
            parkingDealer.push_back(move(*it));
            listOfVehicle.erase(it);

            float price = parkingDealer[(parkingDealer.size())-1]->getter<float>('p');
            int mileage = parkingDealer[(parkingDealer.size())-1]->getter<int>('a');
            string model = parkingDealer[(parkingDealer.size())-1]->getter<string>('m');

            budgetDealer -= (price - mileage); //it is simplification, better solution is dependence based on exponential function
            parkingDealer[(parkingDealer.size())-1]->changePrice();
        }
        else
            cout << "Your budget does not allow you to buy this vehicle.";
    }
}

void UsedVehiclesDealer::sell()
{
    if(!parkingDealer.empty())
    {
        int no;
        do
        {
            cout << "Enter number of car park for sale (1 - " << parkingDealer.size() << "):" << endl;
            cin >> no;
        } while (!checkId(no, parkingDealer));

        budgetDealer+= 1.2*(parkingDealer[(no - 1)]->getter<float>('p'));

        auto it = next(begin(parkingDealer), (no - 1));
        vehicleForSell = move(*it);

        parkingDealer.erase(it);
    }
}

void UsedVehiclesDealer::show()
{
    unsigned int size = parkingDealer.size();
    if(size == 0)
        cout << "Your parking is empty" << endl;
    else
        for(unsigned int i = 0; i < size; i++)
            cout << i + 1 << ". " << *(parkingDealer[i]);

    cout << "Budget is " << budgetDealer << "PLN" << endl;
}

void UsedVehiclesDealer::driveVehicle()
{
    if(!parkingDealer.empty())
    {
        int no;
        do
        {
            cout << "Enter no. the parking space of the vehicle you want to drive: " << endl;
            cin >> no;
        } while (!checkId(no, parkingDealer));


        parkingDealer[(no - 1)]->drive();
    }
    else
        cout << "Your factory is empty" << endl;
}

void UsedVehiclesDealer::refuelVehicle()
{
    if(!parkingDealer.empty())
    {
        int no;
        do
        {
            cout << "Enter no. parking space of the vehicle you want to refuel: " << endl;
            cin >> no;
        } while (!checkId(no, parkingDealer));

        parkingDealer[(no - 1)]->refuel();
    }
    else
        cout << "Your factory is empty" << endl;
}

void UsedVehiclesDealer::save()
{
    unsigned int size = parkingDealer.size();

    ofstream fileP;
    fileP.open("parkingDealer.txt", ofstream::out);

    for (unsigned int i = 0; i < size; i++)
        fileP << *(parkingDealer[i]);

    fileP.close();

    ofstream fileB;
    fileB.open("budgetDealer.txt", ofstream::out);

    fileB << budgetDealer;

    fileB.close();
}

void UsedVehiclesDealer::read()
{
    ifstream fileP;
    fileP.open("parkingDealer.txt", ios::in);

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
                    parkingDealer.push_back(
                            make_unique<Car>(type, model, color, price, capacity, mileage, tank, fuel, fuelUsage, power,
                                             numberOfDoors));
                    break;
                case 'M':
                    fileP >> tank >> fuel >> fuelUsage >> power;
                    parkingDealer.push_back(
                            make_unique<Motorcycle>(type, model, color, price, capacity, mileage, tank, fuel, fuelUsage,
                                                    power));
                    break;
                case 'B':
                    fileP >> rack;
                    parkingDealer.push_back(
                            make_unique<Bicycle>(type, model, color, price, capacity, mileage, rack));
                    break;
                default:
                    cout << "Cannot read vehicle of this type" << endl;
            }
        }

        fileP.close();
    }
    else
        cout << "Cannot open file parkingDealer.txt" << endl;

    ifstream fileB;
    fileB.open("budgetDealer.txt", ios::in);

    if(fileB.is_open())
    {
        if (!fileB.good())
            cout << "Budget set on default value" << endl;
        else
            fileB >> budgetDealer;

        fileB.close();
    }
    else
        cout << "Cannot open file budgetDealer.txt" << endl;
}

bool UsedVehiclesDealer::checkId(int no, std::vector<std::unique_ptr<Vehicle>> &checkedVector)
{
    if((no >= 1) && (no <= checkedVector.size()))
        return true;
    return false;
}

unsigned int UsedVehiclesDealer::getSize()
{
    return parkingDealer.size();
}
