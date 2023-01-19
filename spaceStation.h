#ifndef SPACESTATION_H
#define SPACESTATION_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "ship.h"
#include "goods.h"
#include "dialog.h"
#include "asciiArt.cpp"
#include "miscellaneous.cpp"

using namespace std;
using namespace Jon;

class SpaceStation { 
public:

    SpaceStation() {}
    SpaceStation(string stationName) {
        this->stationName = stationName;
        this->stationSymbol = charToString(stationName[0]);
    }

    string stationName = "";
    string stationSymbol = "";
    Ship ship;

    // ---------------------------------------------------------------------------------------------

    void printWares() {
        
        cout << setw(17) << "Name" << setw(7) << "Price" 
            << setw(10) << "Quantity" << "\n----------------------------------\n";
        
        for(int i = 0; i < wares.size(); i++) {
            cout << setw(2) << (i + 1) << ".) ";
            wares[i]->printGoodsData();
        }
    }    

    // ---------------------------------------------------------------------------------------------

    void interactWithStation() {
        Dialog::screenBorder();
        AsciiArt::saturn2();

        vector<string> title = {this->stationName};
        vector<vector<string>> content = {
            {"Buy trade cargo"},
            {"Sell trade cargo"},
            {"Hire crew"},
            {"Upgrade ship"},
            {"Depart for next station"}
        };

        Dialog::generateDialogTerminal(title, content, 27, true);
        Dialog::screenBorder();
    }

// =================================================================================================

private:

    vector<Goods*> wares = {
        new Goods("Pencils",      generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Pens",         generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Straws",       generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Forks",        generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Diapers",      generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Fingers",      generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Turkey",       generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Clowns",       generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Rainbows",     generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Wrachets",     generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Icecream",     generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Snot drip",    generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Hair plug",    generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Dandilion",    generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Shovels",      generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Cat nip",      generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Nick nack",    generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("French fry",   generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Fire ladder",  generateRandomNumber(100), generateRandomNumber(100)),
        new Goods("Jumping Jack", generateRandomNumber(100), generateRandomNumber(100)),  
        new Goods("Fire hose",    generateRandomNumber(100), generateRandomNumber(100)),  
        new Goods("Acorns",       generateRandomNumber(100), generateRandomNumber(100))
    };
};

#endif // SPACESTATION_H

