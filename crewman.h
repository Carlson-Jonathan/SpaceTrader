#ifndef CREWMAN_H
#define CREMAN_H

#include <iostream>
using namespace std;

class Crewman {
public:

    string name = "";
    int health = 0;
    int price = 0;

    int navigation = 0;
    int negotiator = 0;
    int security = 0;
    int famous = 0;
    int perception = 0;
    int engineering = 0;
    int medical = 0;

    bool linguist = false;
    bool telepath = false;
    bool hacker = false;
    bool diplomat = false;
    bool gunner = false;
    bool thief = false;
    bool sabatour = false;


};

#endif // CREWMAN_H