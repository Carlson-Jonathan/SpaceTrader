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
    int fuelTank = 0;
    int availableCargoSpace = 0;
    int crewSize = 0;
    int money = 1000;
    int engine = 40;
    string engineDescription = 
        "The Flux Translocation Engine, or FTL for short, is a "
        "cutting-edge propulsion system that utilizes a revolutionary "
        "new technology to transport spacecraft across vast distances "
        "of space. Using the power of Flux Translocation, this engine "
        "is capable of jumping across many light years of space in an "
        "instant, making it a valuable asset for any long-distance "
        "space travel. While the engine has a limited range, it can "
        "be upgraded to increase its capabilities and travel even "
        "further. The FTL drive is fueled by a rare and exotic form "
        "of matter known as Lumonite, which is capable of harnessing "
        "and manipulating the fundamental forces of the universe to "
        "propel the ship forward. With its sleek design and advanced "
        "technology, the Flux Translocation Engine is a marvel of "
        "modern space travel, and a crucial tool for any interstellar "
        "adventurer seeking to explore the depths of the cosmos.";

    Art* art = Art::getInstance();

    unique_ptr<Weapon> weapon;
    vector<unique_ptr<Crewman>> crew = {};
    vector<unique_ptr<Goods>> cargo = {};
    string shipFile;

    // ---------------------------------------------------------------------------------------------

    void calculateAvailableCargoSpace() {
        availableCargoSpace = cargoCapacity;
        for(int i = 0; i < cargo.size(); i++) {
            availableCargoSpace -= cargo[i]->quantity;
        }
    }

    // ---------------------------------------------------------------------------------------------

    void viewEngine() {
        Dialog::generateDialogBox("FTL", engineDescription);
        vector<string> title = {
            "Level", "Range", "Fuel/Jump", "Cost"
        };

        vector<vector<string>> upgrades = {
            {"1", "40", "2", "N/A"},
            {"2", "55", "3", "10,000"},
            {"3", "70", "5", "25,000"},
            {"4", "75", "2", "100,000"},
            {"5", "100", "1", "200,000"}
        };

        Dialog::generateDialogBox(title, upgrades);
        Dialog::pause();
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
        art->displayAsciiArt(art->misc["shipyard.ascii"]);

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

        string shipName = shipNames[shipId];
        shipFile = Misc::charToString(tolower(shipName[0])) + 
            shipName.substr(1, shipName.length() - 1) + ".ascii";
        art->displayAsciiArt(art->ships[shipFile]);
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