#ifndef SPACESTATION_H
#define SPACESTATION_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
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

    // ---------------------------------------------------------------------------------------------

    void printWares(vector<Goods*> goods) {
        vector<string> title = {"Name", "Price", "Quantity"};
        vector<vector<string>> content = {};
        for(int i = 0; i < goods.size(); i++) {
            content.push_back({goods[i]->name, 
                               to_string(goods[i]->price),
                               to_string(goods[i]->quantity)});
        }

        Dialog::generateDialogBox(title, content, true);
    }    

    // ---------------------------------------------------------------------------------------------

    void purchaseGoods() {

        // View and select items
        cout << Dialog::drawLine('=', 60) << "\n\n";
        printWares(this->wares);
        string infoLine = "Credits: $" + to_string(ship.money) + "   Cargo Holds: " + 
               to_string(ship.availableCargoSpace) + "/" + to_string(ship.cargoCapacity);
        Dialog::centerText(infoLine);
        Dialog::centerText("Make your selection:\n", 60);
        cout << Dialog::drawLine('=', 60) << endl;
        int goodSelection = getInt(this->wares.size());

        // Determine max goods that can be bought
        int supplyLimit = this->wares[goodSelection - 1]->quantity;
        int affordabaleLimit = ship.money / this->wares[goodSelection - 1]->price;
        int availableSpace = ship.availableCargoSpace;
        int limits[] = {supplyLimit, affordabaleLimit, availableSpace};
        int* limit = min_element(limits, limits + 3);
        
        // cout << "supplyLimit = " << supplyLimit << endl;
        // cout << "affordabaleLimit = " << affordabaleLimit << endl;
        // cout << "availableSpace = " << availableSpace << endl;
        // cout << "Minimum int = " << *limit << endl;

        if(!limit) {
            purchaseGoods();
            Dialog::centerText("You may not purchase this merchandise!");
            return;
        }

        Dialog::centerText("Purchase how many? (Max " + to_string(*limit) + ")", 60);
        int qty = getInt(*limit);

        // If type of goods is already on ship, add to it. Otherwise make a new one.
        if(!ship.cargo.size())
            ship.cargo.push_back(new Goods(wares[goodSelection - 1]->name,
                                               wares[goodSelection - 1]->price, qty));
        else {
            for(int i = 0; i < ship.cargo.size(); i++) {
                if(ship.cargo[i]->name == wares[goodSelection - 1]->name) {
                    ship.cargo[i]->quantity += qty;                        
                    break;
                }        
                else {
                    ship.cargo.push_back(new Goods(wares[goodSelection - 1]->name,
                                                wares[goodSelection - 1]->price, qty));
                    break;                                               
                }
            }
        }

        // Adjust station supply/ship capacity/money
        wares[goodSelection - 1]->quantity -= qty;
        ship.calculateAvailableCargoSpace();
        ship.money -= this->wares[goodSelection - 1]->price * qty;

        ship.displayShipStatus();
    }

    // ---------------------------------------------------------------------------------------------

    void interactWithStation() {
        cout << Dialog::drawLine('=', 60) << endl;
        AsciiArt::saturn2();

        string title = this->stationName;
        vector<string> content = {
            "Buy trade cargo",
            "Sell trade cargo",
            "Hire crew",
            "View Ship",
            "Depart for next station"
        };

        Dialog::generateDialogBox(this->stationName, content, true);
        cout << Dialog::drawLine('=', 60) << endl;
    }


// =================================================================================================
};

#endif // SPACESTATION_H

