#ifndef SPACESTATION_H
#define SPACESTATION_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <memory>
#include "ship.h"
#include "goods.h"
#include "dialog.h"
#include "miscellaneous.cpp"

using namespace std;

class SpaceStation { 
public:

    SpaceStation() {}
    SpaceStation(string stationName) {        
        this->stationName = stationName;
        this->stationSymbol = Misc::charToString(stationName[0]);
        populateWares();
        randomizeMerchAttr(0);
        randomizeMerchAttr(1);
    }

    string stationName = "";
    string stationSymbol = "";
    string stationFile = "";
    int stationId = 0;
    Ship ship;
    Art* art = Art::getInstance();

    vector<unique_ptr<Goods>> wares = {};
    vector<string> merchandiseList = {
        "Pencils",    
        "Pens",      
        "Forks",      
        "Diapers",    
        "Fingers",   
        "Turkey",      
        "Clowns",      
        "Rainbows",   
        "Wrachets",   
        "Icecream",   
        "Snot drip",  
        "Hair plug",  
        "Dandilion",   
        "Shovels",     
        "Cat nip",     
        "Nick nack",   
        "French fry",   
        "Fire ladder",  
        "Jumping Jack", 
        "Fire hose",     
        "Acorns",
        "Telescope",
        "Fluffy Plush"      
    };

    // ---------------------------------------------------------------------------------------------

    void randomizeMerchAttr(int attribute) {
        for(int i = 0; i < wares.size(); i++) {
            if(attribute == 0 )
                wares[i]->price = Misc::generateRandomNumber(100);
            else if(attribute == 1)
                wares[i]->quantity = Misc::generateRandomNumber(100);
        }
    }

    // ---------------------------------------------------------------------------------------------

    void populateWares() {
        for(auto i : merchandiseList) {
            wares.push_back(make_unique<Goods>(i, 0, 0));
        }
    }

    // ---------------------------------------------------------------------------------------------

    void printWares(const vector<unique_ptr<Goods>> & goods, bool enumerated = true) {
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
            ship.cargo.push_back(make_unique<Goods>(wares[selection - 1]->name,
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
                ship.cargo.push_back(make_unique<Goods>(wares[selection - 1]->name,
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

    void printPurchaseMenu(string addedText) {
        Dialog::clear();
        cout << Dialog::drawLine('=', 60) << "\n";
        Dialog::centerText(this->stationName);
        cout << "\n";
        printWares(wares, true);
        Dialog::centerText("<Your Merchandise>");
        ship.calculateAvailableCargoSpace();
        Dialog::centerText("Cargo Space: " + to_string(ship.availableCargoSpace) + 
                           "/" + to_string(ship.cargoCapacity));
        Dialog::centerText("Credits: $" + to_string(ship.money) + "\n");
        printWares(ship.cargo, false);
        Dialog::drawBottomBorder(addedText);
        Dialog::centerText("0.) Cancel");
        Dialog::drawLine('=', 60);
    }

    // ---------------------------------------------------------------------------------------------

    void purchaseGoods() {
        int selection = 0;
        do {
            printPurchaseMenu("Select An Item To Buy");
            selection = Misc::getInt(wares.size(), 0);
            if(selection) {
                int limit = getPurchasingLimit(selection);
                if(!limit) {
                    Dialog::centerText("You cannot buy that item.");
                    Dialog::pause();
                    return;
                }
                printPurchaseMenu("Buy how many " + wares[selection - 1]->name + "? (Max " + 
                                to_string(limit) + ")");
                int qty = Misc::getInt(limit, 0);
                if(qty)
                    transactPurchase(selection, qty);
            }
        } while(selection);
    }

    // ---------------------------------------------------------------------------------------------

    void printSaleMenu(string addedText) {
        Dialog::clear();
        Dialog::centerText(this->stationName);
        cout << "\n";
        printWares(wares, false);
        Dialog::centerText("<Your Merchandise>");
        Dialog::centerText("Cargo Space: " + to_string(ship.availableCargoSpace) + 
                           "/" + to_string(ship.cargoCapacity));        
        Dialog::centerText("Credits: $" + to_string(ship.money) + "\n");
        printWares(ship.cargo);
        Dialog::drawBottomBorder(addedText);
        Dialog::centerText("0.) Cancel");
    }

    // ---------------------------------------------------------------------------------------------

    void sellGoods() {
        int selection = 0;
        do {
            printSaleMenu("Select an item to sell.");
            selection = Misc::getInt(ship.cargo.size(), 0);
            if(selection) {
                printSaleMenu("Sell how many " + ship.cargo[selection - 1]->name + "?");
                int qty = Misc::getInt(ship.cargo[selection - 1]->quantity, 0);
                if(qty)
                    transactSale(selection, qty);
            }
        } while(selection);
    }

    // ---------------------------------------------------------------------------------------------

    void printStationMenu() {
        string title = this->stationName;
        vector<string> content = {
            "Buy trade cargo",
            "Sell trade cargo",
            "Hire crew",
            "View Ship Info",
            "Leave Station"
        };

        Dialog::generateDialogBox(this->stationName, content, true);
    }

    // ---------------------------------------------------------------------------------------------

    string setStationImageFile() {
        string fileName = "";
        for(int i = 0; stationName[i] != ' '; i++) {
            fileName += Misc::charToString(stationName[i]);
        }
        return fileName + ".ascii";
    }

    // ---------------------------------------------------------------------------------------------

    void interactWithStation() {
        bool onStation = true;
        do {
            Dialog::clear();
            stationFile = setStationImageFile();
            art->displayAsciiArt(art->stations[stationFile]);
            printStationMenu();
            Dialog::drawBottomBorder();
            int selection = Misc::getInt(5);
            switch(selection) {
                case 1: 
                    purchaseGoods();
                    break;
                case 2:
                    sellGoods();
                    break;
                case 4:
                    Dialog::clear();
                    art->displayAsciiArt(art->ships[ship.shipFile]);
                    ship.displayShipStatus();
                    Dialog::pause();
                    break;   
                case 5:
                    onStation = false;
                    break; 
                default:
                    break;
            }     
        } while(onStation);   
    }


// =================================================================================================
};

#endif // SPACESTATION_H

