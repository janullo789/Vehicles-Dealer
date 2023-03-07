//
// Created by Jan Skwarczenski on 07.03.2023.
//

#include "Painter.h"

using namespace std;

Painter::Painter() = default;

Painter::Painter(unique_ptr<Vehicle>& paintingVehicle) : paintingVehicle(std::move(paintingVehicle)) {}

void Painter::painting()
{
    char choice;
    string color;

    do
    {
        cout << "Select new vehicle color" << endl;
        cout << "1. White" << endl <<
             "2. Black" << endl <<
             "3. Silver" << endl <<
             "4. Red" << endl <<
             "5. Gold" << endl <<
             "6. Green" << endl;
        cin >> choice;

        switch (choice)
        {
            case '1':
                color = "White";
                break;
            case '2':
                color = "Black";
                break;
            case '3':
                color = "Silver";
                break;
            case '4':
                color = "Red";
                break;
            case '5':
                color = "Gold";
                break;
            case '6':
                color = "Green";
            default:
                cout << "Enter number between 1 - 6" << endl;
                break;

        }
    } while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6');

    paintingVehicle->repaint(color);
    fromPainting = move(paintingVehicle);
}