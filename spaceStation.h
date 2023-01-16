#ifndef SPACESTATION_H
#define SPACESTATION_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "miscellaneous.cpp"
#include "ship.h"
#include "goods.h"
using namespace std;
using namespace Jon;

class SpaceStation { 
public:

    SpaceStation() {}

    string stationName = "";

    // ---------------------------------------------------------------------------------------------

    void printWares(vector<Goods*> wares) {
        
        cout << setw(17) << "Name" << setw(7) << "Price" 
            << setw(10) << "Quantity" << "\n----------------------------------\n";
        
        for(int i = 0; i < wares.size(); i++) {
            cout << setw(2) << (i + 1) << ".) ";
            wares[i]->printGoodsData();
        }
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

