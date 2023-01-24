#ifndef SECTOR_H
#define SECTOR_H

#include <iostream>
#include <math.h>
#include <map>
#include "miscellaneous.cpp"
using namespace std;

class Sector {
public:

    Sector() : station("Enceladus Station") {
        setMarker("E");
        populateStationSymbols();
        setThisStationsNameAndSymbol("E");
        this->station.ship.setupShip();
        gameLoop();
        sort(stations.begin(), stations.end());
    };

// -------------------------------------------------------------------------------------------------

private:

    SpaceStation station;
    string allStationSymbols = "";

    vector<string> sectorMap = {" ",
        "0----------------------------------0",
        "|   *               .           .  |",
        "|       (E)    .         .         |",
        "|                    .       (O)   |",
        "|  .       +                       |",
        "|                 (C)     *        |",
        "|   (T)       .                  . |",
        "|                                  |",
        "| .        .       .     +         |",
        "|     *                     (S)    |",
        "|              (B)   .             |",
        "|        .                         |",
        "|  (P)                      .      |",
        "|              .      +         .  |",
        "|      +                           |",
        "|                      (H)         |",
        "|  *    (R)       *          +     |",
        "|                     .            |",
        "0----------------------------------0"
    };    

    vector<string> stations = {
        "Betelgeuse Way",
        "Calypso Trade Center",
        "Enceladus Station",
        "Hyperion Market",
        "Orion Vendors",
        "Proxima Central",
        "Rigel Exchange",
        "Solaris III",
        "Terrilius Auction"
    };

    void displayMap();
    void setMarker(string station, bool erase = 0);
    pair<int, int> getStationCoordinates(string station);
    int  getDistance(string station, string destination);
    void gameLoop();
    void stationSelector();
    void populateStationSymbols();
    void displayStationOptions();
    void setThisStationsNameAndSymbol(string symbol);
};

// =================================================================================================

void Sector::displayMap() {
    string mapTitle = "Current Location: " + station.stationName;
    Dialog::centerText(mapTitle, 60);

    for(auto i : sectorMap) {
        Dialog::centerText(i, 60);
    }
    cout << endl;
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
    bool gameover = false;
    do {
        station.interactWithStation();
        stationSelector();
    } while (!gameover);
}

// -------------------------------------------------------------------------------------------------

void Sector::populateStationSymbols() {
    for(int i = 0; i < stations.size(); i++) {
        allStationSymbols += stations[i][0];
    }
}

// -------------------------------------------------------------------------------------------------

void Sector::setThisStationsNameAndSymbol(string symbol) {
    for(int i = 0; i < stations.size(); i++) {
        if(stations[i][0] == symbol[0]) {
            this->station.stationId = i;
            this->station.stationName = stations[i];
            this->station.stationSymbol = charToString(stations[i][0]);
            break;
        }
    }
}

// -------------------------------------------------------------------------------------------------

void Sector::displayStationOptions() {
    vector<vector<string>> stationsList = {};

    for(int i = 0; i < stations.size(); i++) {
        string dist = "";
        dist = to_string(getDistance(this->station.stationSymbol, 
            charToString(this->allStationSymbols[i]))) + " LYs";
        stationsList.push_back({stations[i], dist});
    }

    vector<string> title = {"Station", "Distance"};
    Dialog::generateDialogBox(title, stationsList);

}

// -------------------------------------------------------------------------------------------------

void Sector::stationSelector() {
    Dialog::clear();
    cout << Dialog::drawLine('=', 60) << endl;
    displayMap();
    displayStationOptions();
    Dialog::drawBottomBorder("Select Next Destination");

    string selection = charToString(getChar(allStationSymbols));

    if(selection != station.stationName) {
        setMarker(this->station.stationSymbol, 1); // Erase current station marker
        setMarker(selection); 
        setThisStationsNameAndSymbol(selection);
        station.randomizeMerchAttr(0);
        station.randomizeMerchAttr(1);
    }
}

// -------------------------------------------------------------------------------------------------


#endif // GOODS_H