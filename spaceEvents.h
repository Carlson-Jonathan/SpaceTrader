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
    Art* art = Art::getInstance();
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

        art->displayAsciiArt(image);
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["pheonix.ascii"];
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

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "This alien can't be trusted. Refuse and leave.",
            "Sell any jumping jacks you may have.",
            "Attack the alien and take its stuff."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class AbandonedCraft : public EventState {
public:

    void event() {
        string content = 
            "You come to a sudden halt. Before you drifts an alien vessle. You hail but receive no "
            "response. Scans show no lifesigns and no functioning systems.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Board the vessel and search for supplies.",
            "Fire on the vessel and destroy it.",
            "Ignore the vessel and make your next jump."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Pirates : public EventState {
public:

    void event() {
        string content = 
            "Your ship is ambushed by a group of pirates, who demand that you hand over a portion of "
            "your cargo or risk being destroyed. They sound serious.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Do whatever they say. No cargo is worth your life.",
            "Attempt a distraction, power your engines and escape.",
            "Attack the pirates. You will not be bullied!"
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Virus : public EventState {
public:

    void event() {
        string content = 
            "While enroute, you discover a deadly virus has somehow infected your crew.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Quarantine the infected. Begin containment procedure.",
            "Order all crew to work on finding a cure.",
            "Send a distress call using biohazard warnings."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class SolarFlare : public EventState {
public:

    void event() {
        string content = 
            "A powerful solar flare damages your ship's systems and causes a massive power surge. "
            "You must find a way to repair the damage before it's too late.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Canabalize parts of your ship to repair damaged systems.",
            "Use whatever cargo you can to make the repairs.",
            "Activate backup systems until you reach your destination."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class BlackHole : public EventState {
public:

    void event() {
        string content = 
            "Your ship is pulled into the gravitational pull of a black hole. You must navigate "
            "through its dangerous gravitational fields and escape before your ship is destroyed.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "All power to the engines! Fight the gravitational force!",
            "Attempt to use the black hole as a slingshot assist.",
            "Analyze the gravity fields. Try to plot a safe course out."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Aliens : public EventState {
public:

    void event() {
        string content = 
            "You come across a previously undiscovered alien species. Will they be friendly, or will "
            "they pose a threat to your ship and crew?";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Observe and gather information from a distance.",
            "Attempt to communicate and interact with them.",
            "Take defensive precautions to protect your ship."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class EngineFailure : public EventState {
public:

    void event() {
        string content = 
            "While traveling through deep space, the ship's engines suddenly malfunction, leaving "
            "the ship stranded. Sensors indicate your cargo is to blame.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Jettison all cargo and procede to your destination.",
            "Search your wares and attempt to isolate the culprit.",
            "Attempt to repair the engines to prevent further problems."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Asteroids : public EventState {
public:

    void event() {
        string content = 
            "Random Event Scenario: A rogue asteroid field suddenly appears in the path of your ship, "
            "threatening to damage or destroy your ship and cargo.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Attempt to maneuver around the asteroid field.",
            "Use defensive systems to destroy approaching asteroids.",
            "Jettison your cargo to improve manueverability."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Distress : public EventState {
public:

    void event() {
        string content = 
            "While traveling to your destination, you receive a distress signal from a nearby ship. "
            "The ship is carrying a group of colonists who have been stranded on a nearby planet and "
            "are in desperate need of assistance.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Answer and move into help the colonists.",
            "Ignore the signal. Continue to your destination.",
            "Amplify and repeat the distress signal."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Amoebas : public EventState {
public:

    void event() {
        string content = 
            "While traveling to your destination, you come upon a nearby spacecraft under attack by "
            "a swarm of space amoebas. They look poorly defended and are in desperate need of assistance.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Engage the creatures and defent the ship.",
            "It is too late for them. Avoid and move on.",
            "Fire on the ship. Give them a merciful death."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Nebula : public EventState {
public:

    void event() {
        string content = 
            "Your ship enters a nebula of radioactive gas. Your hull should sufficiently protect you "
            "but some of this gas looks like it would sell well at your next stop.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Attempt to harvest the gas for later sale.",
            "Continue on. The risk is not worth it.",
            "Note the coordinates for later use."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Storm : public EventState {
public:

    void event() {
        string content = 
            "A massive solar storm is detected ahead, with strong solar winds and radiation that "
            "can damage the ship's systems and cargo. The ship must navigate through the storm to "
            "reach its destination safely.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Attempt to navigate away from the storm.",
            "Divert power to shields and hunker down.",
            "All stop. Wait and see if conditions improve."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Shrimp : public EventState {
public:

    void event() {
        string content = 
            "You stop in front of a baby space shrimp about half the size of your ship. "
            "Reports indicate these creatures to generally be harmless garbadge feeders "
            "that clean up space debris.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Attack the shrimp.",
            "Release some of your cargo for it to feed on.",
            "Ignore the creature and contine on."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Satellite : public EventState {
public:

    void event() {
        string content = 
            "As you complete your jump you notice an alien satellite drifting through "
            "space. There is nothing nearby for it to be observing and it seems rogue.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Bring the device aboard for examination.",
            "Shoot the satellite and destroy it.",
            "Ignore the satellite and carry on."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Anomoly : public EventState {
public:

    void event() {
        string content = 
            "You encounter an undocumented space anomoly which approaches and engulfs your ship. "
            "Some of your crew begin to act strangely, while random systems malfuncion.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Flee the area and attempt to outrun it.",
            "Activate the computer's AI to obtain data on it.",
            "Do nothing. Wait and see what happens."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Hail : public EventState {
public:

    void event() {
        string content = 
            "Your ship suddenly starts receiving a hail in an unknown language. Dispite your crew's "
            "best efforts, they are unable to interpret the hail or determine its source.";

        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Ignore the signal and continue forward.",
            "Search the ship's database for interpretations.",
            "Reply to the hail using all known languages."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Freighter : public EventState {
public:

    void event() {
        string content = 
            "You encounter a recently wrecked freigther. Much of their cargo has leaked through a "
            "in the hull and you see the crew of the freighter desperately scrambling to salvage it.";
            
        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Steal some of the cargo and fly away.",
            "Hail the freighter and offer assitance.",
            "Leave them to their own problems."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
    string title = "Red Alert";
};

// -------------------------------------------------------------------------------------------------

class Pulsar : public EventState {
public:

    void event() {
        string content = 
            "Your ship has re-materialized dangerously close to a pulsar. You are being bombarded "
            "dangerous highly ionized particles with every wave. There is a rogue asteroid near by "
            "which may offer you some shelter.";
            
        art->displayAsciiArt(image);
        Dialog::generateDialogBox(title, content);
    }

    int responseOptions() {
        vector<string> options = {
            "Shields up. Resist until you can escape.",
            "Manuever behind the asteroid for protection.",
            "Fire at the asteroid. See what happens."
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
    Art* art = Art::getInstance();
    vector<string> image = art->aliens["buyer.ascii"];
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