#ifndef ART_H
#define ART_H

#include <iostream>
#include <fstream>
#include <vector>
#include "miscellaneous.cpp"
using namespace std;

class Art {
public:

    Art() {
       populateListFromFile("asciiArt/characters/aliens/", aliens);
       populateListFromFile("asciiArt/characters/crew/", crewmen);
       populateListFromFile("asciiArt/planets/", planets);
       populateListFromFile("asciiArt/ships/", ships);
       populateListFromFile("asciiArt/stations/", stations);
       populateListFromFile("asciiArt/misc/", misc);
    }

    vector<vector<string>> ships    = {};
    vector<vector<string>> crewmen  = {};
    vector<vector<string>> aliens   = {};
    vector<vector<string>> stations = {};
    vector<vector<string>> planets  = {}; 
    vector<vector<string>> misc     = {};

    // ---------------------------------------------------------------------------------------------

    void displayAsciiArt(vector<string> art, int screenWidth = 60) {
        string margin = "";
        int longest = Misc::getLongestStrLen(art);
        int marginSize = ((60 - longest) / 2);
        while(marginSize--) {
            margin += " ";
        }
        for(auto & i : art) {
            i = margin + i + margin;
            cout << i << "\n";
        }
    }

// =================================================================================================

private:

    vector<string> getAsciiArt(const string & fileName) {
        ifstream file(fileName);
        if (file.fail()) 
            cout << "Error reading file: " << fileName << "\n";
        vector<string> image = {};
        string line = "";
        while(getline(file, line)) {
            image.push_back(line);
        }
        file.close();
        return image;
    } 

    // ---------------------------------------------------------------------------------------------

    void populateListFromFile(const char* directory, vector<vector<string>> & list) {
        vector<string> files = Misc::getAllFileNamesFromDirectory(directory);
        for(auto i : files) {
            vector<string> art = getAsciiArt(directory + i);
            list.push_back(art);
            list[list.size() - 1].push_back("\n");
        }
    }
};

#endif // ART_H