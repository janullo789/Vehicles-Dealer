#include <iostream>

using namespace std;

#include "Factory.h"
#include "UsedVehiclesDealer.h"
#include "Vehicle.h"
#include "Painter.h"

void loadParkingCity(vector<unique_ptr<Vehicle>>& parking);
void saveParkingCity(vector<unique_ptr<Vehicle>>& parking);
void painting(Factory &f);

template<typename T>
void sizeOfParking(T &object);

int main()
{
    Factory f1;
    UsedVehiclesDealer d1;

    vector<std::unique_ptr<Vehicle>> parkingCity; //vector contains vehicle which sold by factory, able to buy by dealer

    cout << "Load factory state from file? [Y/N]" << endl;
    char ans;
    cin >> ans;
    if(ans == 'Y' || ans == 'y')
    {
        f1.read();
        d1.read();
        loadParkingCity(parkingCity);
    }

    char choice1;
    char choice2;
    bool check;

    do
    {
        cout <<"Menu" << endl;
        cout <<"Changes in:" << endl;
        cout <<"1. Factory" << endl <<
             "2. Used Vehicles Dealer" << endl <<
             "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice1;

        if(choice1 == '1')
        {
            do
            {
                cerr.flush();
                cout <<"1. Produce a vehicle" << endl <<
                     "2. Sell a vehicle" << endl <<
                     "3. Show state of factory" << endl <<
                     "4. Drive your chosen vehicle" << endl <<
                     "5. Refuel your chosen vehicle" << endl <<
                     "6. Repaint your chosen vehicle" << endl <<
                     "0. Exit" << endl;
                cout << "Choice: ";
                cin >> choice2;

                switch (choice2)
                {
                    case '0':
                        break;
                    case '1':
                        f1.order();
                        break;
                    case '2':
                        check = f1.sell();
                        if(check) //if check = true, then the factory sold a motor vehicle (not a bicycle)
                        {                // which needs to be added to the parkingCity vector
                            parkingCity.push_back(move(f1.VehicleDeparting));
                        }
                        break;
                    case '3':
                        f1.show();
                        sizeOfParking(f1);
                        break;
                    case '4':
                        f1.driveVehicle();
                        break;
                    case '5':
                        f1.refuelVehicle();
                        break;
                    case '6':
                        painting(f1);
                        break;
                    default:
                        cout << "Enter number between: 0 - 6\n";
                        break;
                }
            }while(choice2 != '0');
        }
        else if(choice1 == '2')
        {
            do
            {
                cerr.flush();
                cout <<"1. Buy a vehicle" << endl <<
                     "2. Sell a vehicle" << endl <<
                     "3. Show state of dealer" << endl <<
                     "4. Drive your chosen vehicle" << endl <<
                     "5. Refuel your chosen vehicle" << endl <<
                     "6. Repaint your chosen vehicle" << endl <<
                     "0. Exit" << endl;
                cout << "Choice: ";
                cin >> choice2;

                switch (choice2)
                {
                    case '0':
                        break;
                    case '1':
                        d1.buy(parkingCity);
                        break;
                    case '2':
                        d1.sell();
                        parkingCity.push_back(move(d1.vehicleForSell));
                        break;
                    case '3':
                        d1.show();
                        sizeOfParking(d1);
                        break;
                    case '4':
                        d1.driveVehicle();
                        break;
                    case '5':
                        d1.refuelVehicle();
                        break;
                    default:
                        cout << "Enter number between: 0 - 6\n";
                        break;
                }
            }while(choice2 != '0');
        }
        else if(choice1 != '0')
            cout << "Enter number between: 0 - 2 :)" << endl;

    }while(choice1 != '0');

    f1.save();
    d1.save();
    saveParkingCity(parkingCity);

    return 0;
}

void loadParkingCity(vector<unique_ptr<Vehicle>>& parking)
{
    ifstream fileP;
    fileP.open("parkingCity.txt", ios::in);

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

        while (fileP >> type >> model >> color >> price >> capacity >> mileage)
        {
            switch(type)
            {
                case 'S':
                    fileP >> tank >> fuel >> fuelUsage >> power >> numberOfDoors;
                    parking.push_back(
                            make_unique<Car>(type, model, color, price, capacity, mileage, tank,
                                                  fuel, fuelUsage, power, numberOfDoors));
                    break;
                case 'M':
                    fileP >> tank >> fuel >> fuelUsage >> power;
                    parking.push_back(
                            make_unique<Motorcycle>(type, model, color, price, capacity, mileage, tank,
                                                  fuel, fuelUsage, power));
                    break;
                default:
                    cout << "This type of vehicle cannot be loaded" << endl;
                    break;
            }
        }
        fileP.close();
    }
    else
        cout << "File parkingCity.txt cannot opened" << endl;
}

void saveParkingCity(vector<unique_ptr<Vehicle>>& parking)
{
    unsigned int size = parking.size();
    ofstream fileP;
    fileP.open("parkingCity.txt", ofstream::out);

    for (unsigned int i = 0; i < size; i++)
        fileP << *(parking[i]);

    fileP.close();
}

void painting(Factory &f)
{
    unique_ptr<Vehicle> vehicleToPainting;               //the factory sends the vehicle to the paint shop, he must first go to the "city"
    f.toPainting();                            //then he is admitted to the doctor who changes his color
    vehicleToPainting = move(f.VehicleDeparting);   //after which the refinisher sends the vehicle back to "city" where the factory picks it up
    Painter p1(vehicleToPainting);                 //the painted vehicle goes to the last parking spot (end of the vector)
    p1.painting();
    f.fromPainting(p1.fromPainting);
}


template<typename T>
void sizeOfParking(T &object) //Factor or UsedVehicleDealer
{
    cout << "Number of vehicles: " << object.getSize() << endl;
}