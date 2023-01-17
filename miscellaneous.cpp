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

        cin.clear();
        cin.ignore(10000,'\n');

        return number;
    }

    // ---------------------------------------------------------------------------------------------

    char getChar(string validChars) {
        char letter = ' ';
        bool invalid = false;

        do {
            cout << "\n>> ";
            cin >> letter;

            size_t found = validChars.find(toupper(letter));
            invalid = (found==std::string::npos) || cin.fail();            

            if(invalid) {
                cout << "Invalid input. Try again.\n";
                cin.clear();
                cin.ignore(10000,'\n');
            }

        } while(invalid);
        
        cin.clear();
        cin.ignore(10000,'\n');
        
        return toupper(letter);
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