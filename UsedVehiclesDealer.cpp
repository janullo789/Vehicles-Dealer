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
            int mileage = parkingDealer[(parkingDealer.size())-1]->getter<int>('ma');
            string model = parkingDealer[(parkingDealer.size())-1]->getter<string>('m');

            budgetDealer -= (price - mileage); //it is simplification, better solution is dependence based on exponential function
            parkingDealer[(parkingDealer.size())-1]->changePrice();
        }
        else
            cout << "Your budget does not allow you to buy this vehicle.";
    }

}