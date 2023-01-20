#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "miscellaneous.cpp"
#include "goods.h"
#include "dialog.h"
#include "asciiArt.cpp"

using namespace std;
using namespace Jon;

class Ship {
public:
    Ship() {}

    string name = "";
    int shipId = 0;
    int hull = 0;
    int cargoCapacity = 0;
    int crewSize = 0;
    int money = 1000;

    vector<Goods*> cargo = {
        new Goods("Rand Cargo1", 100, 10),
        new Goods("Rand Cargo2",  85, 15),
        new Goods("Rand Cargo3",  40, 90)
    };

    // ---------------------------------------------------------------------------------------------

    void setCargoCapacity() {
        for(auto i : cargo) {
            cargoCapacity -= i->quantity;
        }
    }

    // ---------------------------------------------------------------------------------------------

    void displayShipStatus() {
        cout << Dialog::drawLine('=', 60) << endl;
        cout << AsciiArt::asciiShips[this->shipId] << endl;

        vector<string> content = {
            "Hull Integrity: " + to_string(this->hull),
            "Cargo Capacity: " + to_string(this->cargoCapacity),
            "Crew Capacity:  " + to_string(this->crewSize)
        };

        Dialog::generateDialogTerminal(this->name, content, 19, false);
        cout << Dialog::drawLine('=', 60) << endl;
    }

    // ---------------------------------------------------------------------------------------------

    void setupShip() {
        Dialog::clear();
        cout << Dialog::drawLine('=', 60) << endl;
        AsciiArt::saturn2();

        int selection = shipSelector();
        this->name = shipNames[selection - 1];
        this->hull = ships[selection - 1][0];
        this->cargoCapacity = ships[selection - 1][1];
        this->crewSize = ships[selection -1][2];
        this->money -= ships[selection - 1][3];

        Dialog::clear();

        Dialog::centerText("Ship Purchased!", 60);
        this->shipId = selection - 1;
        displayShipStatus();

        Dialog::pause();
        Dialog::clear();
    }

// =================================================================================================

private:

    vector<string> shipNames = {"Kestrel", "Falcon", "Stingray", "Galleon", "Rapier", "Hornet"};

    vector<vector<int>> ships = {
    //   Hull, cargo, crew, price
        { 100,    85,   10,   800},
        { 200,    30,   15,   750},
        { 150,    55,    8,   850},
        {  75,   100,    5,   675},
        { 250,     0,   20,   600},
        {  15,     5,    3,   150}
    };


    // ---------------------------------------------------------------------------------------------

    int shipSelector() {

        vector<string> title = {"Name", "Hull", "Cargo", "Crew", "Price"};

        vector<vector<string>> content;
        for(int i = 0; i < ships.size(); i++) {
            content.push_back({});
        }

        for(int i = 0; i < ships.size(); i++) {
            content[i].push_back(shipNames[i]);
            for(int j = 0; j < ships[0].size(); j++) {
                string x = to_string(ships[i][j]);
                if(j == 3)
                    x.insert(0, "$");
                content[i].push_back(x);
            }
        }

        string finances = "Credits: $" + to_string(money);
        Dialog::centerText(finances, 60);
        Dialog::generateDialogTerminal(title, content, 40, true);
        cout << Dialog::drawLine('=', 60) << endl;
        int selection = getInt(ships.size());
        return selection;
    }
};

#endif // SHIP_H