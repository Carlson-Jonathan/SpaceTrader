#ifndef SECTOR_H
#define SECTOR_H

#include <iostream>
#include <math.h>
#include <map>
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

    vector<string> sectorMap = {
        "",
        "O----------------------------------O",
        "|          *       .               |",
        "| .   (E)    .          .    (O)   |",
        "|                    .             |",
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
        "|                            (V)   |",
        "|  *    (R)       *       +        |",
        "|           .         .            |",
        "O----------------------------------O"
    };    

    vector<string> stations = {
        "Enceladus Station",
        "Centari Prime",
        "Orion V",
        "Terra Firma",
        "Sagetarius IV",
        "Polaris Nebula",
        "Lightyear Gangway",
        "Betelgeuse Trading Post",
        "Gravity Hub",
        "Vega Market",
        "Rigel Exchange"
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
    Dialog::screenBorder();
    Dialog::centerText(mapTitle, 60);
    Dialog::screenBorder();

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
                sectorMap[i - 1][found] = 'v';
                sectorMap[i + 1][found] = '^';
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
            station->printWares();
            break;
        case 5: 
            Dialog::clear();
            displayMap();
            stationSelector();
            Dialog::pause();
            Dialog::clear();
            displayMap();
            break;
        default:
            break;
    }
}

// -------------------------------------------------------------------------------------------------

void Sector::stationSelector() {

    cout << "\nSelect your next destination:\n\n";
    for(int i = 0; i < stations.size(); i++) {
        string nextSymbol = charToString(stations[i][0]);
        cout << nextSymbol << ".) " << setw(25) << stations[i] << "  (" 
             << setw(3) << getDistance(station->stationSymbol, nextSymbol) << " light years)" 
             << endl;
    }
    cout << endl;

    string availableSymbols = allStationSymbols;
    size_t found = allStationSymbols.find(station->stationSymbol);
    if(found!=std::string::npos) 
        availableSymbols.erase(availableSymbols.begin() + found);

    Dialog::screenBorder();
    string selection = charToString(getChar(availableSymbols));

    setMarker(selection);
    setMarker(station->stationSymbol, 1);

    for(auto i : stations) {
        if(i[0] == selection[0]) {
            station->stationName = i;
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