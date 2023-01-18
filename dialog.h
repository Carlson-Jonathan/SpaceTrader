#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <iomanip>
#include "miscellaneous.cpp"
#include "asciiArt.cpp"
using namespace std;
using namespace Jon;

namespace Dialog {

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

    // ---------------------------------------------------------------------------------------------

    void addLineSpace(int lines) {
        for(int i = 0; i < lines; i++) {
            cout << endl;
        }
    }

    // ---------------------------------------------------------------------------------------------

    void screenBorder() {
        cout << "============================================================" << endl;
    }

    // ---------------------------------------------------------------------------------------------

    void centerText(string text, int columnWidth) {
        cout << setw(columnWidth / 2 + text.length() / 2) << text << endl;
    }

    // ---------------------------------------------------------------------------------------------

    string formatTextWidth(string text, int columnWidth, int endOfLine = 0) {

        if(columnWidth < 20)
            columnWidth = 20;
        
        size_t found = 0;
        string line = text.substr(endOfLine, columnWidth);
        
        if(text[text.length() - 1] != ' ')
            text += " ";
        
        found = line.rfind(' ');
        if(found!=std::string::npos) {
            endOfLine += found;
            text[endOfLine] = '\n';
        }

        if(endOfLine < text.length() && (found!=std::string::npos))
            text = formatTextWidth(text, columnWidth, endOfLine);
        
        return text;    
    }

    // ---------------------------------------------------------------------------------------------

    void newGameIntro() {
        string introText = "Story exposition goes here. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sit amet nulla eu sem viverra tincidunt. Vivamus mollis turpis a elit porttitor, nec aliquet purus porta. Nullam vestibulum elit ut mi sollicitudin scelerisque. Donec sit amet consequat magna, vitae fermentum sem. In scelerisque dolor a arcu tempus pharetra. Nam scelerisque nisl nec semper ultrices. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Interdum et malesuada fames ac ante ipsum primis in faucibus. Cras ut nunc eu lacus sagittis ullamcorper non sit amet metus. Nullam interdum dui vitae tincidunt viverra. Donec pharetra feugiat congue. Maecenas lobortis lacus turpis, ac dapibus nulla feugiat vel. Nulla eu enim purus. Nulla feugiat justo vitae sagittis varius. Phasellus quis metus id lectus imperdiet convallis. End of string.";
        introText = formatTextWidth(introText, 60);

        clear();
        screenBorder();
        centerText("Welcome to Enceladus Station!", 60);
        AsciiArt::saturn2();
        cout << introText << endl;
        cout << "Before we can proceed, you must purchase a ship.\n\n";
        screenBorder();
        pause();
        clear();
    }
};

#endif // Events_H