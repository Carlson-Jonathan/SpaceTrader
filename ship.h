#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "miscellaneous.cpp"
using namespace std;
using namespace Jon;

class Ship {
public:
    Ship() {}

    string name = "";
    int hull = 0;
    int cargoCapacity = 0;
    int crewSize = 0;
    int money = 1000;

    void displayShipStatus() {
        int width = 22;
        cout << setfill('=') << setw(width) << "" << endl << setfill(' ');
        cout << setw((width / 2) + (name.length() / 2)) << this->name << endl;
        cout << setfill('=') << setw(width) << "" << endl << setfill(' ');
        cout << setw(18) << "Hull Integrity: " << this->hull          << endl;
        cout << setw(18) << "Cargo Capacity: " << this->cargoCapacity << endl;
        cout << setw(18) << "Crew Capacity: "  << this->crewSize      << endl;
        cout << setfill('=') << setw(width) << "" << endl << setfill(' ');
    }

    // ---------------------------------------------------------------------------------------------

    void setupShip() {
        int selection = shipSelector();
        this->name = shipNames[selection - 1];
        this->hull = ships[selection - 1][0];
        this->cargoCapacity = ships[selection - 1][1];
        this->crewSize = ships[selection -1][2];
        this->money -= ships[selection - 1][3];
        cout << "\nShip purchased!" << endl;
        displayShipStatus();
        pause();
        clear();
    }

// =================================================================================================

private:

    vector<vector<int>> ships = {
    //   Hull, cargo, crew, price
        { 100,    85,   10,   800},
        { 200,    30,   15,   750},
        { 150,    55,    8,   850},
        {  75,   100,    5,   675},
        { 250,     0,   20,   600}
    };

    vector<string> shipNames = {"Kestrel", "Falcon", "Stingray", "Galleon", "Rapier"};

    int shipSelector() {
        cout << "\nCredits: $" << money << endl;
        cout << "Select your ship:\n\n";
        cout << setw(13) << "Name" << setw(8) << "Hull" << setw(10) << "Capacity" 
             << setw(7) << "Crew" << setw(8) << "Price" << endl;
        cout << "     -----------------------------------------\n";
        for(int i = 0; i < ships.size(); i++) {
            cout << (i + 1) << ".)" << setw(10) << shipNames[i] << setw(8) << ships[i][0] << setw(10) << ships[i][1]
                 << setw(7) << ships[i][2] << setw(5) << "$" << ships[i][3] << endl;
        }
        return getInt(ships.size());
    }
};

#endif // SHIP_H