#ifndef JON
#define JON

#include <iostream>
using namespace std;

namespace Jon {

    int generateRandomNumber(int max = 10, int min = 1) {
        return rand() % (max + 1 - min) + (min - 1);
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
        cin.clear();
        cin.ignore(10000,'\n');        
        cout << "\nPress [Enter] to continue...";
        string nothing = "";
        getline(cin, nothing);
    }

}

#endif // JON