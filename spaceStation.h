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

    vector<Goods*> wares = {//             Price                     Quantity           
        new Goods("Pencils",      generateRandomNumber(10, 2), generateRandomNumber(350)),
        new Goods("Pens",         generateRandomNumber(15, 8), generateRandomNumber(100, 80)),
        new Goods("Diamonds",     generateRandomNumber(300, 250), generateRandomNumber(8, 3)),
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

    void printWares(const vector<Goods*> & goods, bool enumerated = true) {
        vector<string> title = {"Name", "Price", "Quantity"};
        vector<vector<string>> content = {};
        for(int i = 0; i < goods.size(); i++) {
            string name = goods[i]->name;
            int price = goods[i]->price;
            int qty = goods[i]->quantity;
            vector<string> line = {name, to_string(price), to_string(qty)};
            content.push_back(line);
        }
        Dialog::generateDialogBox(title, content, enumerated);
    }    

    // ---------------------------------------------------------------------------------------------

    int getPurchasingLimit(int selection) {
        int supplyLimit = this->wares[selection - 1]->quantity;
        int affordabaleLimit = ship.money / this->wares[selection - 1]->price;
        int availableSpace = ship.availableCargoSpace;
        int limits[] = {supplyLimit, affordabaleLimit, availableSpace};
        int* limit = min_element(limits, limits + 3);
        return *limit;
    }

    // ---------------------------------------------------------------------------------------------

    void transactPurchase(int selection, int qty) {
        // If type of goods is already on ship, add to it. Otherwise make a new one.
        if(!ship.cargo.size())
            ship.cargo.push_back(new Goods(wares[selection - 1]->name,
                                               wares[selection - 1]->price, qty));
        else {
            // Search for item and increment
            bool itemExists = false;
            for(int i = 0; i < ship.cargo.size(); i++) {
                if(ship.cargo[i]->name == wares[selection - 1]->name) {
                    ship.cargo[i]->quantity += qty;  
                    itemExists = true;                      
                    break;
                }        
            }
            if(!itemExists) {
                ship.cargo.push_back(new Goods(wares[selection - 1]->name,
                                            wares[selection - 1]->price, qty));
            }
        }
        wares[selection - 1]->quantity -= qty;
        ship.money -= this->wares[selection - 1]->price * qty;
    }

    // ---------------------------------------------------------------------------------------------

    string transactSale(int selection, int qty) {
        int price = 0;
        string sale = "";
        for(int i = 0; i < wares.size(); i++) {
            if(ship.cargo[selection - 1]->name == wares[i]->name) {
                sale = "Selling " + to_string(qty) + " " + wares[i]->name +
                        " @ $" + to_string(wares[i]->price) + "ea. (+$" + 
                        to_string(wares[i]->price * qty) + ")";
                int price = wares[i]->price;
                this->ship.cargo[selection - 1]->quantity -= qty;
                this->wares[i]->quantity += qty;
                this->ship.money += (price * qty);
                this->ship.availableCargoSpace += qty;  
                break;
            }
        }
        if(!ship.cargo[selection - 1]->quantity)
            ship.cargo.erase(ship.cargo.begin() + (selection -1));

        return sale;
    }

    // ---------------------------------------------------------------------------------------------

    void purchaseGoods() {

        printWares(wares);
        int selection = getInt(this->wares.size());
        int limit = getPurchasingLimit(selection);

        if(!limit) {
            Dialog::centerText("You cannot buy that item.");
            Dialog::pause();
            return;
        }

        Dialog::centerText("Purchase how many? (Max " + to_string(limit) + ")", 60);
        int qty = getInt(limit);
        transactPurchase(selection, qty);

        ship.displayShipStatus();
    }

    // ---------------------------------------------------------------------------------------------

    void printSaleMenu(string addedText) {
        Dialog::clear();
        Dialog::centerText("<" + this->stationName + " Merchandise>\n");
        printWares(wares, false);
        Dialog::centerText("<Your Merchandise>\n");
        Dialog::centerText("Credits: $" + to_string(ship.money));
        printWares(ship.cargo);
        Dialog::centerText(addedText);
    }

    // ---------------------------------------------------------------------------------------------

    void sellGoods() {
        printSaleMenu("Select Item To Sell");
        int selection = getInt(ship.cargo.size());
        printSaleMenu("Sell how many " + ship.cargo[selection - 1]->name + "?");
        int qty = getInt(ship.cargo[selection - 1]->quantity);
        transactSale(selection, qty);
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

