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
        for(int i = 0; i < 50; i++) {
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

    string drawLine(char style, int width) {
        string line = "";
        while(width--) {
            line += style;
        }
        return line;
    }

    // ---------------------------------------------------------------------------------------------

    void centerText(string text, int columnWidth) {
        cout << setw(columnWidth / 2 + text.length() / 2) << right << text << endl;
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

    void generateDialogTerminal(vector<string> title, vector<vector<string>> content, 
                                int dialogWidth = 30, bool enumerate = true) {

        int indention = (60 - dialogWidth) / 2;
        string horizontalLine = "";
        int w = dialogWidth;

        while(w--)
            horizontalLine += "-";

        centerText(horizontalLine, 60);

        if(title.size() == 1)
            centerText(title[0], 60);
        else {
            for(int i = 0; i < title.size(); i++) {
                if(!i)
                    if(enumerate)
                        cout << setw(indention + 4) << " " << setw(12) << left;
                    else
                        cout << setw(indention) << " " << setw(12) << left;
                else 
                    cout << setw(6) << right;
                cout << title[i]; 
            }
            cout << endl;
        }


        centerText(horizontalLine, 60);

        for(int i = 0; i < content.size(); i++) {
            for(int j = 0; j < content[i].size(); j++) {
                if(!j)
                    if(enumerate)
                        cout << setw(indention + 1) << right << (i + 1) << ".) " << setw(12) << left;
                    else
                        cout << setw(indention) << right << "" << setw(12) << left;
                else 
                    cout << setw(6) << right;
                cout << content[i][j];
            }
            cout << endl;
        }
        centerText(horizontalLine, 60);
        cout << endl;
    }

    // ---------------------------------------------------------------------------------------------

    void generateDialogTerminal(string title, vector<string> content, int dialogWidth = 30, 
                                bool enumerate = true) {

        int indention = (60 - dialogWidth) / 2;
        string horizontalLine = "";
        int w = dialogWidth;        

        while(w--)
            horizontalLine += "-";

        centerText(horizontalLine, 60);
        centerText(title, 60);
        centerText(horizontalLine, 60);

        for(int i = 0; i < content.size(); i++) {
            if(enumerate)
                cout << setw(indention + 1) << right << (i + 1) << ".) " << setw(12) << left;
            else
                cout << setw(indention) << right << "" << setw(12) << left;
            cout << content[i] << endl;
        }

        centerText(horizontalLine, 60);
        cout << endl;
    }

    // ---------------------------------------------------------------------------------------------

    string centerBrokenString(string text, int indent) {
        size_t found = 0;
        string indention = "";
        while(indent--)
            indention += " ";

        do {
            found = text.find("\n", found + 1);
            text.insert(found + 1, indention);
        } while(found!=std::string::npos);

        return text;
    }

    // ---------------------------------------------------------------------------------------------

    void generateDialogTerminal(string title, string content, int dialogWidth = 30) {

        centerText(drawLine('-', dialogWidth), 60);
        centerText(title, 60);
        centerText(drawLine('-', dialogWidth), 60);

        content = formatTextWidth(content, dialogWidth);
        content = centerBrokenString(content, ((60 - dialogWidth) / 2));
        cout << content << endl;
        centerText(drawLine('-', dialogWidth), 60);
        cout << endl;
    }    

    // ---------------------------------------------------------------------------------------------

    void newGameIntro() {
        string introText = "Story exposition goes here. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sit amet nulla eu sem viverra tincidunt. Vivamus mollis turpis a elit porttitor, nec aliquet purus porta. Nullam vestibulum elit ut mi sollicitudin scelerisque. Donec sit amet consequat magna, vitae fermentum sem. In scelerisque dolor a arcu tempus pharetra. Nam scelerisque nisl nec semper ultrices. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Interdum et malesuada fames ac ante ipsum primis in faucibus. Cras ut nunc eu lacus sagittis ullamcorper non sit amet metus. Nullam interdum dui vitae tincidunt viverra. Donec pharetra feugiat congue. Maecenas lobortis lacus turpis, ac dapibus nulla feugiat vel. Nulla eu enim purus. Nulla feugiat justo vitae sagittis varius. Phasellus quis metus id lectus imperdiet convallis. End of string.";
        string title = "Welcome to Enceladus Station!";
        string content = introText;
        clear();

        cout << drawLine('=', 60) << endl;
        AsciiArt::saturn2();
        cout << drawLine('=', 60) << endl;

        generateDialogTerminal(title, content, 50);

        centerText("Before we can proceed, you must purchase a ship...\n", 60);
        cout << drawLine('=', 60) << endl;
        pause();
        clear();
    }
};

#endif // Events_H