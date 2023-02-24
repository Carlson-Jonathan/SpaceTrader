#ifndef ART_H
#define ART_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "miscellaneous.cpp"
using namespace std;

class Art {
public:
    Art(const Art& obj) = delete; // This is now a singleton

    static Art* getInstance() {
        if(!instancePtr) 
            instancePtr = new Art();
        return instancePtr;
    }

    map<string, vector<string>> ships    = {};
    map<string, vector<string>> crewmen  = {};
    map<string, vector<string>> aliens   = {};
    map<string, vector<string>> stations = {};
    map<string, vector<string>> planets  = {}; 
    map<string, vector<string>> misc     = {};

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
    Art() {
       populateListFromFile("asciiArt/characters/aliens/", aliens);
       populateListFromFile("asciiArt/characters/crew/", crewmen);
       populateListFromFile("asciiArt/planets/", planets);
       populateListFromFile("asciiArt/ships/", ships);
       populateListFromFile("asciiArt/stations/", stations);
       populateListFromFile("asciiArt/misc/", misc);
    }

    static Art* instancePtr;


    vector<string> getAsciiArt(const string & fileName) {
        ifstream file(fileName);
        if(file.fail()) 
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

    void populateListFromFile(const char* directory, map<string, vector<string>> & list) {
        vector<string> files = Misc::getAllFileNamesFromDirectory(directory);
        for(auto i : files) {
            vector<string> art = getAsciiArt(directory + i);
            art.push_back("\n");
            list.insert({i, art});
        }
    }            
};

Art* Art::instancePtr = NULL;

#endif // ART_H