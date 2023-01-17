#ifndef SECTOR_H
#define SECTOR_H

#include <iostream>
#include <math.h>
using namespace std;

class Sector {
public:
    Sector() {
        setMarker("J");
        getDistance("S", "L");
    };

    string sectorName = "Jupiter Station";

    // ---------------------------------------------------------------------------------------------

    void displayMap() {
        cout << "\t" << setw((sectorMap[0].length() / 2) + (sectorName.length() / 2)) << sectorName 
             << endl;
        cout << "\t+----------------------------------+" << endl;

        for(auto i : sectorMap) {
            cout << i << endl;
        }
        cout << "\t+----------------------------------+" << endl;
    }

    // ---------------------------------------------------------------------------------------------

    void setMarker(string mark, bool erase = 0) {
        toupper(mark[0]);
        for(int i = 0; i < sectorMap.size(); i++) {
            size_t found = sectorMap[i].find(mark);
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
    // ---------------------------------------------------------------------------------------------

    int getDistance(string current, string dest) {
        size_t x1 = 0, x2 = 0;
        int y1 = 0, y2 = 0, X = 0, Y = 0, xSq = 0, ySq = 0, dist = 0;

        for(int i = 0; i < sectorMap.size(); i++) {
            x1 = sectorMap[i].find(current);
            if(x1!=std::string::npos) {
                y1 = i;
                break;
            }
        }

        for(int i = 0; i < sectorMap.size(); i++) {
            x2 = sectorMap[i].find(dest);
            if(x2!=std::string::npos) {
                y2 = i;
                break;
            }
        }

        y1 += y1; y2 += y2;
        y1 *= 10; y2 *= 10; x1 *= 10; x2 *= 10;
        X = abs(int(x1 - x2));
        Y = abs(y1 - y2);
        xSq = pow(X, 2);
        ySq = pow(Y, 2);
        dist = sqrt((xSq + ySq));

        return dist;    
    }

    // ---------------------------------------------------------------------------------------------

    void stationSelector() {
        string sectorMark = " ";
        sectorMark[0] = sectorName[0];
        setMarker(sectorMark);
        cout << "\nSelect your next destination.\n\n";
        for(int i = 0; i < stations.size(); i++) {
            string stMark = " ";
            stMark = stations[i][0];
            cout << stations[i][0] << ".) " << setw(25) << stations[i] << "  (" 
                 << setw(3) << getDistance(sectorMark, stMark) << " light years)" << endl;
        }
        string selection = " ";
        selection[0] = getChar("JOCTPSLGBRV");
        setMarker(selection);
        setMarker(sectorMark, 1);
        sectorName = selection;
    }

// =================================================================================================

private:

    vector<string> sectorMap = {
        "\t|          *       .               |",
        "\t| .   (J)    .          .    (O)   |",
        "\t|                    .             |",
        "\t|  *       +    (C)           .    |",
        "\t|                         *        |",
        "\t|   (T)       .                  . |",
        "\t|        .                  (S)    |",
        "\t| .                  +             |",
        "\t|     *     (P)               .    |",
        "\t|                 .       (L)      |",
        "\t|        .                         |",
        "\t|  .           (B)          .      |",
        "\t|    (G)              +         .  |",
        "\t|             .                    |",
        "\t|                            (V)   |",
        "\t|  *    (R)       *       +        |",
        "\t|           .         .            |"
    };    

    vector<string> stations = {
        "Jupiter Station",
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
};

#endif // GOODS_H