#include <iostream>
#include "spaceStation.h"
#include "dialog.h"
#include "sector.h"
using namespace std;

int main() {

    Ship ship;
    SpaceStation station;
    Sector sector;
    Dialog::newGameIntro();
    ship.setupShip();
    station.interactWithStation();
    int selection = getInt(5);
    switch (selection) {
        case 1: 
            clear();
            station.printWares();
            break;
        case 5: 
            clear();
            sector.displayMap();
            sector.stationSelector();
            pause();
            clear();
            sector.displayMap();
            break;
        default:
            break;
    }




    return 0;
}