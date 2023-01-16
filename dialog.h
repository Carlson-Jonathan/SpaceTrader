#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include "miscellaneous.cpp"
using namespace std;
using namespace Jon;

namespace Dialog {

    void newGameIntro() {
        clear();
        cout << "Welcome to Jupiter Station!" << endl;
        cout << "Story exposition goes here." << endl;
        cout << "Before we can proceed, you must purchase a ship." << endl;
        pause();
        clear();
    }

    // ---------------------------------------------------------------------------------------------

    int getInt(int max, int min = 1){
        int number = 0;
        bool invalid = false;

        do {
            cout << "\n>> ";
            cin >> number;
            invalid = (number < min || number > max || cin.fail());

            if(invalid) {
                cout << "Invalid input. Try again.\n";
                cin.clear();
                cin.ignore(10000,'\n');
            }

        } while(invalid);

        return number;
    }

    // ---------------------------------------------------------------------------------------------

    void clear() {
        for(int i = 0; i < 100; i++) {
            cout << "\n";
        }
    }

    // ---------------------------------------------------------------------------------------------

    void pause() {
        string nothing = "";
        cout << "\nPress [Enter] to continue...";
        getline(cin, nothing);
    }

};

#endif // Events_H