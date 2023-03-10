#ifndef SECTOR_H
#define SECTOR_H

#include <iostream>
#include <math.h>
#include <map>
#include "miscellaneous.cpp"
#include "events.h"
using namespace std;

class Sector {
public:

    Sector() : station("Calypso Station") {
        setMarker("C");
        populateStationSymbols();
        setThisStationsNameAndSymbol("C");
        this->station.ship.setupShip();
        sort(stations.begin(), stations.end());
        gameLoop();
    };

// -------------------------------------------------------------------------------------------------

private:

    Events events;
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
        "Betelgeuse Waypoint",
        "Calypso Station",
        "Enceladus Trade",
        "Hyperion Market",
        "Orion Vendors",
        "Proxima Central",
        "Rigel Exchange",
        "Solaris III",
        "Terrilius Oasis"
    };

    void displayMap();
    void setMarker(string station, bool erase = 0);
    pair<int, int> getStationCoordinates(string station);
    int  getDistance(string station, string destination);
    void gameLoop();
    string stationSelector();
    void populateStationSymbols();
    void displayStationOptions();
    void setThisStationsNameAndSymbol(string symbol);
    void setNewStation(string symbol);
    string getStationNameFromSymbol(string symbol);
};

// =================================================================================================

void Sector::displayMap() {
    string mapTitle = "Current Location: " + station.stationName;
    Dialog::centerText(mapTitle, 60);

    for(auto i : sectorMap) {
        Dialog::centerText(i, 60);
    }
    cout << "\n";
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

void Sector::populateStationSymbols() {
    for(int i = 0; i < stations.size(); i++) {
        allStationSymbols += stations[i][0];
    }
}

// -------------------------------------------------------------------------------------------------

string Sector::getStationNameFromSymbol(string symbol) {
    string name = "";
    for(int i = 0; i < stations.size(); i++) {
        if(stations[i][0] == symbol[0]) 
            name = stations[i];
    }
    return name;
}

// -------------------------------------------------------------------------------------------------

void Sector::setThisStationsNameAndSymbol(string symbol) {
    for(int i = 0; i < stations.size(); i++) {
        if(stations[i][0] == symbol[0]) {
            this->station.stationId = i;
            this->station.stationName = stations[i];
            this->station.stationSymbol = Misc::charToString(stations[i][0]);
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
            Misc::charToString(this->allStationSymbols[i]))) + " LYs";
        stationsList.push_back({stations[i], dist});
    }

    vector<string> title = {"Station", "Distance"};
    Dialog::generateDialogBox(title, stationsList);

}

// -------------------------------------------------------------------------------------------------

void Sector::setNewStation(string symbol) {
    if(symbol == station.stationSymbol) 
        return;

    if(symbol == "O") 
    
    cout << "Erasing marker...\n";
    setMarker(this->station.stationSymbol, 1); // Erase current station marker
    setMarker(symbol); 
    setThisStationsNameAndSymbol(symbol);
    station.randomizeMerchAttr(0);
    station.randomizeMerchAttr(1);
}

// -------------------------------------------------------------------------------------------------

string Sector::stationSelector() {
    Dialog::clear();
    displayMap();
    displayStationOptions();
    Dialog::drawBottomBorder("Select Next Destination");
    return Misc::charToString(Misc::getChar(allStationSymbols));
}

// -------------------------------------------------------------------------------------------------

void Sector::gameLoop() {
    bool gameover = false;
    do {
        station.interactWithStation();
        string symbol = stationSelector();
        if(symbol == station.stationSymbol) continue;
        events.travelCounter(getDistance(this->station.stationSymbol, symbol), 
                             this->station.ship.engine, 
                             this->station.stationName, 
                             getStationNameFromSymbol(symbol));
        setNewStation(symbol);
    } while (!gameover);
}

// -------------------------------------------------------------------------------------------------

#endif // GOODS_H