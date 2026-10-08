#include <iostream>
#include "RoboticArm.h"

using namespace std;

int main() {

    RoboticArm brazo(0, 0, 0, false);

    cout << "Posicion inicial: "
         << "(" << brazo.getX() << ", "
         << brazo.getY() << ", "
         << brazo.getZ() << ")" << endl;

    brazo.move(10, 20, 30);

    cout << "Nueva posicion: "
         << "(" << brazo.getX() << ", "
         << brazo.getY() << ", "
         << brazo.getZ() << ")" << endl;

    brazo.grab();

    cout << "¿Esta sujetando un objeto? "
         << brazo.getSujetando() << endl;

    return 0;
}
