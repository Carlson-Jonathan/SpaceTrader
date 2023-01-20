#ifndef SECTOR_H
#define SECTOR_H

#include <iostream>
#include <math.h>
#include <map>
#include "miscellaneous.cpp"
using namespace std;

class Sector {
public:

    Sector() {
        setMarker("E");
        setStationSymbols();
        this->station = new SpaceStation(stations[0]); 
        station->ship.setupShip();
        gameLoop();
    };

// -------------------------------------------------------------------------------------------------

private:

    SpaceStation* station;
    string allStationSymbols = "";

    vector<string> sectorMap = {" ",
        "0----------------------------------0",
        "|          *       .            .  |",
        "| .   (E)    .          .          |",
        "|                    .       (O)   |",
        "|  *       +    (C)           .    |",
        "|                         *        |",
        "|   (T)       .                  . |",
        "|        .                  (S)    |",
        "| .                  +             |",
        "|     *     (P)               .    |",
        "|                 .       (L)      |",
        "|        .                         |",
        "|  .           (B)          .      |",
        "|    (G)              +         .  |",
        "|             .                    |",
        "|                            (H)   |",
        "|  *    (R)       *   (U)  +       |",
        "|           .       .              |",
        "0----------------------------------0"
    };    

    vector<string> stations = {
        "Enceladus Station",
        "Centari Prime",
        "Orion V",
        "Terra Firma",
        "Sagetarius IV",
        "Polaris Nebula",
        "Lightyear Gangway",
        "Betelgeuse Post",
        "Gravity Hub",
        "Hyperion Market",
        "Rigel Exchange",
        "Ursa Ultra"
    };

    void           displayMap           ();
    void           setMarker            (string station, bool erase = 0);
    pair<int, int> getStationCoordinates(string station);
    int            getDistance          (string station, string destination);
    void           gameLoop             ();
    void           stationSelector      ();
    void           setStationSymbols    ();
};

// =================================================================================================

void Sector::displayMap() {
    string mapTitle = "Current Location: " + station->stationName;
    cout << Dialog::drawLine('=', 60) << endl;
    Dialog::centerText(mapTitle, 60);
    cout << Dialog::drawLine('=', 60) << endl;

    for(auto i : sectorMap) {
        Dialog::centerText(i, 60);
    }
}

// -------------------------------------------------------------------------------------------------

void Sector::setMarker(string station, bool erase) {
    toupper(station[0]);
    for(int i = 0; i < sectorMap.size(); i++) {
        size_t found = sectorMap[i].find(station);
        if(found!=std::string::npos) {
            if(erase) {
                sectorMap[i][found - 2] = ' ';
                sectorMap[i][found + 2] = ' ';
                sectorMap[i - 1][found] = ' ';
                sectorMap[i + 1][found] = ' ';
            }
            else {
                sectorMap[i][found - 2] = '>';
                sectorMap[i][found + 2] = '<';
                sectorMap[i - 1][found] = 'V';
                sectorMap[i + 1][found] = 'A';
            }
            break;
        }
    }
}

// -------------------------------------------------------------------------------------------------

pair<int, int> Sector::getStationCoordinates(string station) {
    int x = 0, y = 0;

    for(int i = 0; i < sectorMap.size(); i++) {
        x = sectorMap[i].find(station);
        if(x!=std::string::npos) {
            y = i;
            break;
        }
    }

    return {x, y};
}

// -------------------------------------------------------------------------------------------------

int Sector::getDistance(string station, string destination) {
    int x = 0, y = 0, distance = 0;

    pair<int, int> origin = getStationCoordinates(station);
    pair<int, int> dest   = getStationCoordinates(destination);

    origin.second *= 2; dest.second *= 2; 
    origin.first *= 10; origin.second *= 10; dest.first *= 10; dest.second *= 10;

    x = abs(int(origin.first - dest.first));
    y = abs(origin.second - dest.second);
    distance = hypot(x, y);

    return distance;
}

// -------------------------------------------------------------------------------------------------

void Sector::gameLoop() {
    station->interactWithStation();
    int selection = getInt(5);
    switch (selection) {
        case 1: 
            Dialog::clear();
            station->purchaseGoods();
            break;
        case 2:
            Dialog::clear();
            station->printWares(station->ship.cargo);
            break;
        case 4:
            Dialog::clear();
            station->ship.displayShipStatus();
            break;            
        case 5: 
            Dialog::clear();
            while(true) {
                displayMap();
                stationSelector();
                // Dialog::pause();
                Dialog::clear();
            }
            displayMap();
            break;
        default:
            break;
    }
}

// -------------------------------------------------------------------------------------------------

void Sector::stationSelector() {

    vector<string> line = stations;
    for(int i = 0; i < stations.size(); i++) {
        line[i] += (" (" + to_string(getDistance(this->station->stationSymbol, charToString(this->allStationSymbols[i]))) + " LYs)");
    }

    string title = "Select Your Next Destination";
    Dialog::generateDialogBox(title, line, 36, false);

    // Create options and remove symbol for current station
    string availableSymbols = allStationSymbols;
    size_t found = allStationSymbols.find(station->stationSymbol);
    if(found!=std::string::npos) 
        availableSymbols.erase(availableSymbols.begin() + found);

    cout << Dialog::drawLine('=', 60) << endl;

    // Change the Marker on the map
    string selection = charToString(getChar(availableSymbols));
    setMarker(selection);
    setMarker(this->station->stationSymbol, 1);
    for(auto i : stations) {
        if(i[0] == selection[0]) {
            this->station->stationName = i;
            this->station->stationSymbol = charToString(i[0]);
            break;
        }
    }
}

// -------------------------------------------------------------------------------------------------

void Sector::setStationSymbols() {
    for(int i = 0; i < stations.size(); i++) {
        allStationSymbols += stations[i][0];
    }
}

#endif // GOODS_H