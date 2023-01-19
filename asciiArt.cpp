#ifndef ASCIIART_CPP
#define ASCIIART_CPP

#include <iostream>
using namespace std;

namespace AsciiArt {

    void broken() {
        string jupiter =     
            "     .    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠶⠾⠿⠿⠿⠿⠷⠶⠦⠀⠀⠀⠀⠀⠀*        |     "
            "              ⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀    - O -   "
            "          ⠀⠀⠀⠀⠰⠿⠿⠿⠟⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠉⠉⠉⠀⠀⠀⠀⠀    |     "
            "         + ⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀            "
            " *         ⠀⢀⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣙⣛⣛⣛⣛⣛⣛⣛⣛⣛⡀⠀⠀        + "
            "           ⠀⠚⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠋⠉⠉⠉⠉⠉⣉⣉⣉⣉⣉⣉⣉⣉⣁⠀⠀          "
            "          ⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣭⣭⣉⠀⠀ .        "
            "          ⠀⠀⢉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣩⡿⠟⠛⠛⠿⣯⣉⣉⣉⣉⣉⡉⠀⠀          "
            "      .    ⠀⠘⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⢿⣄⡀⠀⠀⣀⣼⠟⠛⠛⠛⠛⠃⠀⠀       .  "
            "           ⠀⠀⠀⣀⣀⣤⣤⣤⣤⣤⣤⣤⣤⣤⣴⣿⣿⣿⣿⣿⣷⣶⣶⣶⣿⡟⠀⠀⠀          "
            "              ⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠋⠀⠀⠀⠀          "
            "   *           ⠀⠀⠲⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠖⠀⠀⠀⠀⠀*          "
            "             .    ⠀⠀⠀⠀⠤⢤⣤⣤⣤⣤⡤⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀        +  ";

        for(auto i : jupiter) {
            cout << i << endl;
        }
    }

    // ---------------------------------------------------------------------------------------------

    void displayJupiter() {
        string jupiter = 
            "      .          *       +               .         .       \n"
            "           '                        *        |          .  \n"
            "   x         .        .-.,='``'=.          - o -           \n"
            "                      '=/_       \\    .    |        +     \n"
            "       +           *   |  '=._    |                       .\n"
            ".           .           \\     `=./`,        '             \n"
            "                  .      '=.__.=' `-'   *         .        \n"
            "    +                               +      .           *   \n"
            "          .      *      '     .                x           \n";

        cout << jupiter << endl;
    }

    // ---------------------------------------------------------------------------------------------

    void randomPlanet() {
        string planet = 
            "             o       .        ___---___                    .          x    "             
            "   *        .              .--\\        --.     .     .         .          "
            "                         ./.;_.\\     __/~ \\.                             "
            "                        /;  / `-'  __\\    . \\                            "
            "      .        .       / ,--'     / .   .;   \\        |               *   "
            "                      | .|       /       __   |      -O-       .           "
            "                     |__/    __ |  . ;   \\ | . |      |                   "
            "+                    |      /  \\_    . ;| \\___|                          "
            "        .    o       |      \\  .~\\___,--'     |           .         +    "
            "                      |     | . ; ~~~~\\_    __|                           "
            "  .      |             \\    \\   .  .  ; \\  /_/   .                      "
            "        -O-        .    \\   /         . |  ~/                  .          "
            "         |    .          ~\\ \\   .      /  /~          o                  "
            "       .                   ~--___ ; ___--~                             .   "
            "                      .          ---         .                +            ";

            cout << planet << endl;
    }

    // ---------------------------------------------------------------------------------------------

    void saturnx() {
        string saturn = 
            "                                                                    ..;===+. \n"
            "                                                                .:=iiiiii=+= \n" 
            "                                                             .=i))=;::+)i=+, \n"
            "                                                          ,=i);)I)))I):=i=;  \n"
            "                                                       .=i==))))ii)))I:i++   \n"
            "                                                     +)+))iiiiiiii))I=i+:'   \n"
            "                                .,:;;++++++;:,.       )iii+:::;iii))+i='     \n"
            "                             .:;++=iiiiiiiiii=++;.    =::,,,:::=i));=+'      \n"
            "                           ,;+==ii)))))))))))ii==+;,      ,,,:=i))+=:        \n"
            "                         ,;+=ii))))))IIIIII))))ii===;.    ,,:=i)=i+          \n"
            "                        ;+=ii)))IIIIITIIIIII))))iiii=+,   ,:=));=,           \n"
            "                      ,+=i))IIIIIITTTTTITIIIIII)))I)i=+,,:+i)=i+             \n"
            "                     ,+i))IIIIIITTTTTTTTTTTTI))IIII))i=::i))i='              \n"
            "                    ,=i))IIIIITLLTTTTTTTTTTIITTTTIII)+;+i)+i`                \n"
            "                    =i))IIITTLTLTTTTTTTTTIITTLLTTTII+:i)ii:'                 \n"
            "                   +i))IITTTLLLTTTTTTTTTTTTLLLTTTT+:i)))=,                   \n"
            "                   =))ITTTTTTTTTTTLTTTTTTLLLLLLTi:=)IIiii;                   \n"
            "                  .i)IIITTTTTTTTLTTTITLLLLLLLT);=)I)))))i;                   \n"
            "                  :))IIITTTTTLTTTTTTLLHLLLLL);=)II)IIIIi=:                   \n"
            "                  :i)IIITTTTTTTTTLLLHLLHLL)+=)II)ITTTI)i=                    \n"
            "                  .i)IIITTTTITTLLLHHLLLL);=)II)ITTTTII)i+                    \n"
            "                  =i)IIIIIITTLLLLLLHLL=:i)II)TTTTTTIII)i'                    \n"
            "                +i)i)))IITTLLLLLLLLT=:i)II)TTTTLTTIII)i;                     \n"
            "              +ii)i:)IITTLLTLLLLT=;+i)I)ITTTTLTTTII))i;                      \n"
            "             =;)i=:,=)ITTTTLTTI=:i))I)TTTLLLTTTTTII)i;                       \n"
            "           +i)ii::,  +)IIITI+:+i)I))TTTTLLTTTTTII))=,                        \n"
            "         :=;)i=:,,    ,i++::i))I)ITTTTTTTTTTIIII)=+'                         \n"
            "       .+ii)i=::,,   ,,::=i)))iIITTTTTTTTIIIII)=+                            \n"
            "      ,==)ii=;:,,,,:::=ii)i)iIIIITIIITIIII))i+:'                             \n"
            "     +=:))i==;:::;=iii)+)=  `:i)))IIIII)ii+'                                 \n"
            "   .+=:))iiiiiiii)))+ii;                                                     \n"
            "  .+=;))iiiiii)));ii+                                                        \n"
            " .+=i:)))))))=+ii+                                                           \n"
            ".;==i+::::=)i=;                                                              \n"
            ",+==iiiiii+,                                                                 \n"
            "`+=+++;`                                                                     \n";

        cout << saturn << endl;
    }                            

    // ---------------------------------------------------------------------------------------------

    void saturn2() {
        string saturn = "\n"
            " .             *                    .          ,o88888    .\n"
            "                                            ,o8888888'     \n"
            "     .                ,:o:o:oooo.        ,8O88Pd8888\"     \n"
            "                  ,.::.::o:ooooOoOoO. ,oO8O8Pd888'\"       \n"   
            "                ,.:.::o:ooOoOoOO8O8OOo.8OOPd8O8O\"         \n"
            "   +            , ..:.::o:ooOoOOOO8OOOOo.FdO8O8\"          \n"
            "              , ..:.::o:ooOoOO8O888O8O,COCOO\"             \n"
            "        .    , . ..:.::o:ooOoOOOO8OOOOCOCO\"            .  \n"
            "              . ..:.::o:ooOoOoOO8O8OCCCC\"o      +         \n" 
            "                 . ..:.::o:ooooOoCoCCC\"o:o                \n"
            "  .              . ..:.::o:o:,cooooCo\"oo:o:               \n"
            "         .    `   . . ..:.:cocoooo\"'o:o:::'              .\n"
            "              .`   . ..::ccccoc\"'o:o:o:::'                \n" 
            "             :.:.    ,c:cccc\"':.:.:.:.:.'          *      \n"
            "           ..:.:\"'`::::c:\"'..:.:.:.:.:.'                 \n"
            "    .    ...:.'.:.::::\"'    . . . . .'     .              \n"
            "        .. . ....:.\"' `   .  . . ''                       \n"
            "*     . . . ....\"'                                   .    \n"
            "      .. . .\"'                            .               \n"
            "     .               .          *                        + \n";
        cout << saturn << endl;
    } 

    // ---------------------------------------------------------------------------------------------

    string spaceShip1 = 
        "\n"
        "                       ___\\____               \n"
        "                      0)__/... \\_             \n"
        "                     00)__)  .___)             \n"
        "    ___              _0__)\\_/ OOO/`':.        \n"
        "   0)_^'-._    __..-'`:  \\ | / ::  \\ o`:     \n"
        "   0)_\\ \\~_..-': \\ \\   :  \\|/   ::  |   \\\n"
        "       \\ /      : | |  :    :  ::  /  _./>-   \n"
        "        (__ ))): /_/____.))_____//.-'`         \n"
        "         7 7~~'\"\"\"            7 7           \n"
        "         L_L                 / /               \n"
        "        0) ^'-.__            |_|               \n"
        "        0)__.-'             0) ^'-.__          \n"
        "                            0)__.-'            \n";
        
    // ---------------------------------------------------------------------------------------------

    string spaceShip2 = "\n"
        "          ____,----._                                  \n"
        "      ,--'| _|\" o;.  `.____        ____  ,,=====._    \n"
        "    .=|.':| U| ;:;:  .- \\,,`-.===='}.,'\\//       \"` \n"
        "   (]=|;: |o |  ,.  (  :;)::(     ):;::>}X==========-  \n"
        "    `=| :;|  | ,: o  `-_/``,-`====.}___/\\       _,    \n"
        "      `--.|__|_ .:  _,' \"\"\"              ``=====''  \n"
        "          ~  ~`----'                                   \n";

    // ---------------------------------------------------------------------------------------------

    string spaceShip3 = "\n"
        "                             /\\                          \n"
        "                            /  \\                         \n"
        "                           /^^^^\\                        \n"
        "                           |----|                         \n"
        "                           /    \\                        \n"
        "                          (|(||)|)                        \n"
        "                           |^^^^|                         \n"
        "                           /----\\                        \n"
        "                          /      \\                       \n"
        "                         /        \\                      \n"
        "                      O-[{[[||||]]}]-O                    \n"
        "                        /|        |\\                     \n"
        "                       / |        | \\                    \n"
        "                      /  |        |  \\                   \n"
        "                     / -[{[[||||]]}]- \\                  \n"
        "                    /####|        |####\\                 \n"
        "                   / I ^ /(::::::)\\ ^ I \\               \n"
        "                  ^--____{|!....!|}____--^                \n"
        "                         /--------\\                      \n"
        "                        /_|######|_\\                     \n"
        "                          ^^^^^^^^                        \n";

    // ---------------------------------------------------------------------------------------------

    string spaceShip4 = "\n"
        "                                                           \n"
        "           ,,o                            __.o+.           \n"
        "         od8^                         oo888888P^b          \n"
        "       ,\".o'                          `b^'\"\"`b -`b      \n"
        "     ,'.'o'                            t. = -`b -`t.       \n"
        "    ; d o'          ___          _.--.. 8  -  `b  =`b      \n"
        "   dooo8<       .o:':__;o.     ,;;o88%%8bb - = `b  =`b.    \n"
        "  |^88^88=. .,x88/::/ | \\`;;;;;;d%%%%%88%88888/%x88888    \n"
        "  :-88=88%%L8`%`|::|_>-<_||%;;%;8%%=;:::=%8;;\\%%%%\\8888  \n"
        "  |=88 88%%|HHHH|::| >-< |||;%;;8%%=;:::=%8;;;%%%%+|]88    \n"
        "  | 88-88%%LL.%.%b::Y_|_Y/%|;;;;`%8%%oo88%:o%.;;;;+|]88    \n"
        "  Yx88o88^^'\"`^^%8boooood..-\\H_Hd%P%%88%P^%%^'\\;;;/%%88 \n"
        "   `\"\\^\\          ''''''      d%P ''''' ^\" ; = `+' - P \n"
        "    `.`.b                    :<%%>      :  -   d' - P      \n"
        "      .`.b                   `788      ,'-  = d' =.'       \n"
        "       ``.b.                           :..-  :'  P         \n"
        "        `q.>b                         `^^^:::::,'          \n"
        "          \"\"^^                                           \n";

    // ---------------------------------------------------------------------------------------------

    string spaceShip5 = "\n"
        "                     `. ___                                 \n" 
        "                    __,' __`.                _..----....____\n"
        "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-\n"
        "  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'   \n"
        ",'________________                          \\`-._`-','     \n"
        " `._              ```````````------...___   '-.._'-:        \n"
        "    ```--.._      ,.                     ````--...__\\-.    \n"
        "            `.--. `-`                       ____    |  |`   \n"
        "              `. `.                       ,'`````.  ;  ;`   \n"
        "                `._`.        __________   `.      \'__/`    \n"
        "                   `-:._____/______/___/____`.     \\  `    \n"
        "                               |       `._    `.    \\      \n"
        "                               `._________`-.   `.   `.___  \n"
        "                                                  `------'` \n";

    string asciiShips[] = {spaceShip1, spaceShip2, spaceShip3, spaceShip4, spaceShip5};
}

#endif // ASCIIART_CPP


