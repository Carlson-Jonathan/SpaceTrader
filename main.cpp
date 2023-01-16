#include <iostream>
#include "spaceStation.h"
#include "dialog.h"
using namespace std;

int main() {

    Ship ship;
    Dialog::newGameIntro();
    ship.setupShip();



    return 0;
}