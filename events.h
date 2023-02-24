#ifndef GAMEEVENTS_H
#define GAMEEVENTS_H // <-- Because 'EVENTS' is reserved.

#include <iostream>
#include <vector>
#include "dialog.h"
#include "miscellaneous.cpp"
#include "art.h"
#include "newEvents.h"
using namespace std;

class Events {
public:

    Events() {
        populateEvents();
    }
    Art art;

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

    // static void triplePrice() {
    //     Art art;
    //     string title = "Code Green";        
    //     string content = 
    //         "After re-materializing, you receive a hail from a strange looking alien merchant. He "
    //         "explains that he is in desperate need of jumping jacks and will gladly pay 300 credits"
    //         "each if you have any to sell him.";
    //     vector<string> options = {
    //         "Do thing 1",
    //         "Do another thing",
    //         "Sing a song",
    //         "Eat spam",
    //         "Last thing here",
    //         "Return to previous station"
    //     };
    //     Dialog::clear();
    //     cout << Dialog::drawLine('=', 60) << "\n";
    //     art.displayAsciiArt(art.aliens[3]);
    //     Dialog::generateDialogBox(title, content);
    //     Dialog::generateDialogBox("What will you do?", options, true);
    //     Dialog::drawBottomBorder();
    //     int selection = Misc::getInt(options.size());
    // }

    // // ---------------------------------------------------------------------------------------------

    // static void unidentifiedVessel() {
    //     Art art;
    //     string title = "Yellow Alert";        
    //     string content = 
    //         "You come to a sudden halt. Before you drifts an alien vessle. You hail but receive no"
    //         "response. Scans show no lifesigns and no functioning systems.";
    //     vector<string> options = {
    //         "Board the vessel and search for supplies.",
    //         "Use your tractor beam to tow it to the next station.",
    //         "Fire on the vessel and destroy it.",
    //         "Ignore the vessel and make your next jump.",
    //     };
    //     Dialog::clear();
    //     cout << Dialog::drawLine('=', 60) << "\n";
    //     art.displayAsciiArt(art.aliens[Misc::generateRandomNumber(art.aliens.size()) - 1]);
    //     Dialog::generateDialogBox(title, content);
    //     Dialog::generateDialogBox("A Mysterious Craft", options, true);
    //     Dialog::drawBottomBorder();
    //     int selection = Misc::getInt(options.size());
    // }

    // // ---------------------------------------------------------------------------------------------

    // static void spaceBird() {
    //     Art art;
    //     string title = "Red Alert";        
    //     string content = 
    //         "As you drop back into normal space, you are suddenly blinded by a giant firey space"
    //         "bird. Your sensors show temperatures radiating from it of over a million degrees."
    //         "The beast seems to have noticed you and darts straight for your ship.";
    //     vector<string> options = {
    //         "Take evasive actions and retreat.",
    //         "Fire all weapons!",
    //         "Power down all systems and play dead.",
    //     };
    //     Dialog::clear();
    //     cout << Dialog::drawLine('=', 60) << "\n";
    //     art.displayAsciiArt(art.aliens[Misc::generateRandomNumber(art.aliens.size()) - 1]);
    //     Dialog::generateDialogBox(title, content);
    //     Dialog::generateDialogBox("A Celestial Bird", options, true);
    //     Dialog::drawBottomBorder();
    //     int selection = Misc::getInt(options.size());
    // }

    // ---------------------------------------------------------------------------------------------

    // vector<void (*)()> eventFunctions = {
    //     triplePrice, 
    //     unidentifiedVessel,
    //     spaceBird
    // };

    // ---------------------------------------------------------------------------------------------

    vector<unique_ptr<EventContext>> allSpaceEvents;

    void populateEvents() {
        allSpaceEvents.push_back(make_unique<EventContext>(make_unique<PheonixEncouter>()));
    }


};
#endif // GAMEEVENTS_H