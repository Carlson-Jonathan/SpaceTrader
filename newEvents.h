#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "dialog.h"
#include "art.h"

using namespace std;

class EventState {
public:
    virtual void event() = 0;
    virtual int  responseOptions() = 0;
    virtual void selection1_outcomes() = 0;
    virtual void selection2_outcomes() = 0;
    virtual void selection3_outcomes() = 0;
private:
    Art art;
    string title;
    vector<string> image;
};

// -------------------------------------------------------------------------------------------------

class PheonixEncouter : public EventState {
public:
    void event() {
        string content = 
            "As you drop back into normal space, you are suddenly blinded by a giant firey space "
            "bird. Your sensors show temperatures radiating from it of over a million degrees! "
            "The beast seems to have noticed you and darts straight for your ship.";

        art.displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Take evasive actions and retreat.",
            "Fire all weapons!",
            "Power down all systems and play dead."
        };

        Dialog::generateDialogBox("", options, true);
        return Misc::getInt(options.size());
    }

    void selection1_outcomes() {
        int outcome = Misc::generateRandomNumber(3);
        switch(outcome) {
            case 1:
                cout << "Bad Stuff" << endl;
                break;
            case 2:
                cout << "Neutral Stuff" << endl;
                break;
            case 3:
                cout << "Good Stuff" << endl;
                break;
            default:
                break;
        }
    }

    void selection2_outcomes() {
        int outcome = Misc::generateRandomNumber(3);
        switch(outcome) {
            case 1:
                cout << "Bad Stuff" << endl;
                break;
            case 2:
                cout << "Neutral Stuff" << endl;
                break;
            case 3:
                cout << "Good Stuff" << endl;
                break;
            default:
                break;
        }
    }

    void selection3_outcomes() {
        int outcome = Misc::generateRandomNumber(3);
        switch(outcome) {
            case 1:
                cout << "Bad Stuff" << endl;
                break;
            case 2:
                cout << "Neutral Stuff" << endl;
                break;
            case 3:
                cout << "Good Stuff" << endl;
                break;
            default:
                break;
        }
    }       

private: 
    Art art;
    vector<string> image = art.aliens["pheonix.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class TriplePrice : public EventState {
public:
    void event() {
        string content = 
            "After re-materializing, you receive a hail from a strange looking alien merchant. He "
            "explains that he is in desperate need of jumping jacks and will gladly pay 300 credits "
            "each if you have any to sell him.";

        art.displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Take evasive actions and retreat.",
            "Fire all weapons!",
            "Power down all systems and play dead."
        };

        Dialog::generateDialogBox("", options, true);
        return Misc::getInt(options.size());
    }

    void selection1_outcomes() {
        int outcome = Misc::generateRandomNumber(3);
        switch(outcome) {
            case 1:
                cout << "Bad Stuff" << endl;
                break;
            case 2:
                cout << "Neutral Stuff" << endl;
                break;
            case 3:
                cout << "Good Stuff" << endl;
                break;
            default:
                break;
        }
    }

    void selection2_outcomes() {
        int outcome = Misc::generateRandomNumber(3);
        switch(outcome) {
            case 1:
                cout << "Bad Stuff" << endl;
                break;
            case 2:
                cout << "Neutral Stuff" << endl;
                break;
            case 3:
                cout << "Good Stuff" << endl;
                break;
            default:
                break;
        }
    }

    void selection3_outcomes() {
        int outcome = Misc::generateRandomNumber(3);
        switch(outcome) {
            case 1:
                cout << "Bad Stuff" << endl;
                break;
            case 2:
                cout << "Neutral Stuff" << endl;
                break;
            case 3:
                cout << "Good Stuff" << endl;
                break;
            default:
                break;
        }
    }       

private: 
    Art art;
    vector<string> image = art.aliens["pheonix.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class EventContext {
public:
    EventContext() {}
    EventContext(unique_ptr<EventState> newState) : state(move(newState)) {}

    void event() {
        state->event();
    }

    void responseOptions() {
        selection = state->responseOptions();
    }

    void outcome() {
        switch(selection) {
            case 1: 
                state->selection1_outcomes();
                break;
            case 2:
                state->selection1_outcomes();
                break;
            case 3:
                state->selection1_outcomes();
                break;
            default:
                break;
        }
    }

    void playEvent() {
        Dialog::clear();
        event();
        responseOptions();
        Dialog::drawBottomBorder();
        outcome();
        Dialog::pause();
        Dialog::drawBottomBorder();
    }

private:
    int selection = 0;
    unique_ptr<EventState> state;
};