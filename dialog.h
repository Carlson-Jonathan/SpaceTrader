#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <iomanip>
#include "miscellaneous.cpp"
#include "asciiArt.cpp"
#include "art.h"
using namespace std;
using namespace Misc;

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

    string drawLine(char style, int width) {
        string line = "";
        while(width--) {
            line += style;
        }
        return line;
    }

    // ---------------------------------------------------------------------------------------------

    void centerText(string text, int columnWidth = 60) {
        cout << setw(columnWidth / 2 + text.length() / 2) << right << text << "\n";
    }

    // ---------------------------------------------------------------------------------------------

    vector<string> splitString(string text) {
        char split_char = '\n';
        istringstream split(text);
        vector<string> lines;
        for(string each; getline(split, each, split_char); lines.push_back(each));
        return lines;
    }

    // ---------------------------------------------------------------------------------------------

    vector<vector<string>> buildTable(vector<vector<string>> content) {
        vector<vector<string>> fContent = {};
        for(int i = 0; i < content[0].size(); i++) {
            fContent.push_back({});
            for(int j = 0; j < content.size(); j++) {
                fContent[i].push_back(content[j][i]);
            }
        }
        return fContent;
    }

    // ---------------------------------------------------------------------------------------------

    void drawBottomBorder(string prompt = "Make Your Selection") {
        cout << drawLine('=', 60);
        cout << "\n";
        centerText(prompt);
    }

    // ---------------------------------------------------------------------------------------------

    vector<string> vectorIntsToStrings(vector<int> content) {
        vector<string> fContent = {};
        for(auto i : content) {
            fContent.push_back(to_string(i));
        }
        return fContent;
    }

    // ---------------------------------------------------------------------------------------------

    void centerAsciiArt(string art) {
        vector<string> splArt = splitString(art);
        string margin = "";
        int marginSize = (60 - splArt[1].length()) / 2;
        while(marginSize--) {
            margin += " ";
        }
        cout << drawLine('=', 60) << "\n";
        for(auto & i : splArt) {
            i = margin + i + margin;
            cout << i << "\n";
        }
    }

    // ---------------------------------------------------------------------------------------------

    string wrapText(string text, int columnWidth, int endOfLine = 0) {

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
            text = wrapText(text, columnWidth, endOfLine);
            
        if(text[text.length() - 1] == ' ')
            text.erase(text.length() - 1);
        
        return text;    
    }

    // ---------------------------------------------------------------------------------------------

    int getDialogBoxWidth(vector<string> content, bool enumerated = false) {
        int width = getLongestStrLen(content);
        if(enumerated)
            width += 4;
        return width;
    }

    // ---------------------------------------------------------------------------------------------

    vector<int> getColumnWidths(vector<vector<string>> content, int enumerated = false) {
        vector<int> colWidths = {};
        int maxLen = 0;
        if(!content.size()) return {0};
        for(int i = 0; i < content[0].size(); i++) {
            maxLen = 0;
            for(int j = 0; j < content.size(); j++) {
                int newLen = content[j][i].length();
                if(newLen > maxLen)
                    maxLen = newLen;
            }
            colWidths.push_back(maxLen);
        }
        return colWidths;
    }

    // ---------------------------------------------------------------------------------------------

    int getDialogBoxWidth(vector<vector<string>> content, bool enumerated = false) {
        vector<int> widths = getColumnWidths(content, enumerated);
        int boxWidth = 0;
        for(auto i : widths) {
            boxWidth += i;
        }

        if(enumerated)
            boxWidth += 4 + (content.size() > 9); // For numbering

        if(content.size())
            boxWidth += (content[0].size() - 1) * 2; // Space between columns
        
        return boxWidth;
    }

    // ---------------------------------------------------------------------------------------------

    void generateDialogHeader(vector<string> title, int indention, vector<int> columnWidths, 
                              bool numExpand, bool enumerated = false) {

        cout << setw(indention) << " ";
        if(enumerated) cout << setw(4 + numExpand) << "  ";
        cout << setw(columnWidths[0]) << left << title[0] << "  ";
        for(int i = 1; i < title.size(); i++) {
            cout << right << setw(columnWidths[i]) << title[i] << "  ";
        }
        cout << "\n";
    }  

    // ---------------------------------------------------------------------------------------------

    void debugDialogBox(int boxWidth, int indentColumn, vector<int> columnWidths) {
        cout << "Box width: " << boxWidth << "\n";
        cout << "Indent Column: " << indentColumn << "\n";
        cout << "columnWidths: {";
        for(auto i : columnWidths) {
            cout << i << ", "; 
        }
        cout << "}" << "\n";
    }

    // ---------------------------------------------------------------------------------------------

    void generateDialogBox(vector<string> & title, vector<vector<string>> & content, 
                           bool enumerated = false, int screenWidth = 60) {
        content.push_back(title);
        int boxWidth = getDialogBoxWidth(content, enumerated);
        int indentColumn = (60 - boxWidth) / 2;
        vector<int> columnWidths = getColumnWidths(content);
        int expand = (content.size() > 9) + 1;
        content.erase(content.end());
        // debugDialogBox(boxWidth, indentColumn, columnWidths);
        
        generateDialogHeader(title, indentColumn, columnWidths, (content.size() > 9), enumerated);
        centerText(drawLine('-', boxWidth), screenWidth);
        for(int i = 0; i < content.size(); i++) {
            cout << setw(indentColumn) << " ";
            if(enumerated) cout << setw(expand) << right << (i + 1) << left << ".) ";
            cout << setw(columnWidths[0]) << left << content[i][0] << right << "  ";
            for(int j = 1; j < content[i].size(); j++) {
                cout << setw(columnWidths[j]) << content[i][j] << "  ";
            }
            cout << "\n";
        }
        centerText(drawLine('-', boxWidth), screenWidth);
        cout << "\n";
    }

    // ---------------------------------------------------------------------------------------------

    void generateDialogBox(string title, vector<vector<string>> content, 
                           bool enumerated = false, int screenWidth = 60) {
        int boxWidth = getDialogBoxWidth(content, enumerated);
        int indentColumn = (60 - boxWidth) / 2;
        vector<int> columnWidths = getColumnWidths(content);
        int expand = (content.size() > 9) + 1;

        centerText(title);        
        centerText(drawLine('-', boxWidth), screenWidth);
        for(int i = 0; i < content.size(); i++) {
            cout << setw(indentColumn) << " ";
            if(enumerated) cout << setw(expand) << right << (i + 1) << left << ".) ";
            cout << setw(columnWidths[0]) << left << content[i][0] << right << "  ";
            for(int j = 1; j < content[i].size(); j++) {
                cout << setw(columnWidths[j]) << content[i][j] << "  ";
            }
            cout << "\n";
        }
        centerText(drawLine('-', boxWidth), screenWidth);
        cout << "\n";
    }

    // ---------------------------------------------------------------------------------------------

    void generateDialogBox(string title, vector<string> content, bool enumerated = false, int screenWidth = 60) {
        int boxWidth = getDialogBoxWidth(content, enumerated);
        int indentColumn = (60 - boxWidth) / 2;
        int columnWidth = getLongestStrLen(content);
        int expand = (content.size() > 9) + 1;

        centerText(title);
        centerText(drawLine('-', boxWidth), screenWidth);
        for(int i = 0; i < content.size(); i++) {
            cout << setw(indentColumn) << " ";
            if(enumerated) cout << setw(expand) << right << (i + 1) << left << ".) ";
            cout << setw(columnWidth) << left << content[i] << right << "\n";
        }
        centerText(drawLine('-', boxWidth), screenWidth);
        cout << "\n";
    }

    // ---------------------------------------------------------------------------------------------

    void generateDialogBox(string title, string content, int dialogBoxWidth = 45) {
        content = wrapText(content, dialogBoxWidth);
        vector<string> fContent = splitString(content);
        generateDialogBox(title, fContent);
    }   

    // ---------------------------------------------------------------------------------------------

    void newGameIntro() {
        string introText = "Story exposition goes here. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sit amet nulla eu sem viverra tincidunt. Vivamus mollis turpis a elit porttitor, nec aliquet purus porta. Nullam vestibulum elit ut mi sollicitudin scelerisque. Donec sit amet consequat magna, vitae fermentum sem. In scelerisque dolor a arcu tempus pharetra. Nam scelerisque nisl nec semper ultrices. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. End of string.";
        string title = "Welcome to Calypso Station!";
        string content = introText;

        Art art;
        clear();
        art.displayAsciiArt(art.aliens[0]);
        generateDialogBox(title, content);

        centerText("Before we can proceed, you must purchase a ship...\n", 60);
        cout << drawLine('=', 60) << "\n";
        pause();
        clear();
    }
};

#endif // Events_H