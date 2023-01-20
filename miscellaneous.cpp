#ifndef JON
#define JON

#include <iostream>
#include <vector>
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

    int getLongestStrLen(vector<string> strings) {
        int longest = 0; 
        for(auto i : strings) {
            if(i.length() > longest)
                longest = i.length();
        }
        return longest;
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

    string charToString(char letter) {
        string str = " ";
        str[0] = letter;
        return str;
    }

    // ---------------------------------------------------------------------------------------------

}

#endif // JON