#ifndef GAMEEVENTS_H
#define GAMEEVENTS_H // <-- Because 'EVENTS' is reserved.

#include <iostream>
#include <vector>
#include "dialog.h"
#include "miscellaneous.cpp"
#include "art.h"
#include "spaceEvents.h"
using namespace std;

class Events {
public:

    Events() {
        populateEvents();
    }
    Art* art = Art::getInstance();

    // ---------------------------------------------------------------------------------------------

    vector<string> travelOptions {
        "Continue to your destination",
        "Return to previous station",
        "View ship status",
        "More options"
    };


    // ---------------------------------------------------------------------------------------------

    void travelCounter(int distance, int engine, string source, string dest) {
        int turns = (distance / engine - 1);
        if(distance % engine) turns++;
        while(turns--) { 
            // int random = Misc::generateRandomNumber(eventFunctions.size());
            // eventFunctions[random - 1]();
            int random = Misc::generateRandomNumber(allSpaceEvents.size());
            allSpaceEvents[random - 1]->playEvent();
            displayTravelOptions(distance, turns + 1, source, dest, engine);
        }
    }

    // ---------------------------------------------------------------------------------------------

    void displayTravelOptions(int distance, int turnsRemaining, string source, string dest, int engine) {
        int totalTurns = (distance / engine);
        if(distance % engine) totalTurns++;
        int turnsTaken = totalTurns - turnsRemaining;
        int distanceTraveled = turnsTaken * engine;
        string remaining = to_string(distanceTraveled) + "/" + to_string(distance) + " LYs";

        vector<vector<string>> logistics = {
            {"Departed:", source},
            {"Destination:", dest},
            {"Traveled:", remaining},
            {"Remaining Jumps:", to_string(turnsRemaining)}
        }; 

        Dialog::clear();
        Dialog::drawLine('=', 60);
        string title = "Travel Data";
        Dialog::generateDialogBox(title, logistics, false);
        title = "Make a Selection";
        Dialog::generateDialogBox(title, travelOptions, true);
        Dialog::drawBottomBorder();
        Misc::getInt(travelOptions.size());
    }

    // ---------------------------------------------------------------------------------------------

    vector<unique_ptr<EventContext>> allSpaceEvents;

    void populateEvents() {
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<PheonixEncouter>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<TriplePrice>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<AbandonedCraft>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Pirates>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Virus>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<SolarFlare>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<BlackHole>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Aliens>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<EngineFailure>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Asteroids>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Distress>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Amoebas>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Nebula>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Storm>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Shrimp>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Satellite>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Anomoly>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Hail>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Freighter>()));
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<Pulsar>()));
    }

};
#endif // GAMEEVENTS_H