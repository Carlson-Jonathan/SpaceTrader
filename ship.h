#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include "miscellaneous.cpp"
#include "goods.h"
#include "dialog.h"
#include "weapon.h"
#include "crewman.h"
#include "art.h"

using namespace std;

class Ship {
public:
    Ship() {
        sort(shipNames.begin(), shipNames.end());
    }

    string name = "";
    int shipId = 0;
    int hull = 0;
    int cargoCapacity = 0;
    int availableCargoSpace = 0;
    int crewSize = 0;
    int money = 1000;
    int engine = 40;

    Art art;

    unique_ptr<Weapon> weapon;
    vector<unique_ptr<Crewman>> crew = {};
    vector<unique_ptr<Goods>> cargo = {};

    // ---------------------------------------------------------------------------------------------

    void calculateAvailableCargoSpace() {
        availableCargoSpace = cargoCapacity;
        for(int i = 0; i < cargo.size(); i++) {
            availableCargoSpace -= cargo[i]->quantity;
        }
    }

    // ---------------------------------------------------------------------------------------------

    vector<vector<string>> formatCargoForPrinting() {
        vector<vector<string>> formatted = {};
        for(int i = 0; i < cargo.size(); i++) {
            formatted.push_back({
                cargo[i]->name,
                to_string(cargo[i]->quantity)
            });
        }
        return formatted;
    }

    // ---------------------------------------------------------------------------------------------

    void displayShipStatus() {
        calculateAvailableCargoSpace();

        vector<vector<string>> content = {
            {"Hull Integrity:", to_string(this->hull)},
            {"Cargo Space:", to_string(this->availableCargoSpace) + "/" + to_string(this->cargoCapacity)},
            {"Crew Capacity:", to_string(this->crewSize)},
            {"Engine:", to_string(this->engine)},
            {"Credits:", to_string(this->money)}
        };

        string title = "Cargo";
        Dialog::generateDialogBox(this->name, content);
        Dialog::generateDialogBox(title, formatCargoForPrinting());
        cout << Dialog::drawLine('=', 60) << "\n";
    }

    // ---------------------------------------------------------------------------------------------

    void setupShip() {
        Dialog::clear();
        art.displayAsciiArt(art.misc[0]);

        int selection = shipSelector();
        this->name = shipNames[selection - 1];
        this->hull = ships[selection - 1][0];
        this->cargoCapacity = ships[selection - 1][1];
        this->availableCargoSpace = cargoCapacity;
        this->crewSize = ships[selection -1][2];
        this->money -= ships[selection - 1][3];
        this->shipId = selection - 1;

        Dialog::clear();
        
        this->shipId = selection - 1;
        art.displayAsciiArt(art.ships[this->shipId]);
        Dialog::centerText("Ship Purchased:\n");
        displayShipStatus();
        Dialog::pause();
        Dialog::clear();
    }

// =================================================================================================

private:

    vector<string> shipNames = {"Kestrel", "Falcon", "Stingray", "Galleon", "Rapier", "Raptor", 
                                "Juggernaut", "Maurader", "Nautilus", "War Hammer"};

    vector<vector<int>> ships = {
    //   Hull, cargo, crew, price, eng
        { 100,  1500,   10,     1,  40},
        { 200,    30,   15,     2,  30},
        { 150,    55,    8,   850,  50},
        {  75,   100,    5,   675,  70},
        { 250,     0,   20,   600,  90},
        {  15,     5,    3,   150,  20},
        { 100,   100,  100,   100, 100},
        { 100,   100,  100,   100, 100},
        { 100,   100,  100,   100, 100},
        { 100,   100,  100,   100, 100}
    };


    // ---------------------------------------------------------------------------------------------

    int shipSelector() {

        vector<string> title = {"Name", "Hull", "Cargo", "Crew", "Price", "Engine"};

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

        string finances = "Credits: $" + to_string(money) + "\n";
        Dialog::centerText(finances, 60);
        Dialog::generateDialogBox(title, content, true);
        Dialog::drawBottomBorder();
        int selection = Misc::getInt(ships.size());
        return selection;
    }
};

#endif // SHIP_H