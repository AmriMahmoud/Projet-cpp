#include "Vegetarien.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Vegetarien& vegetarien) {
    os << "Vegetarien: " << (vegetarien.estVegetarien() ? "Oui" : "Non");
    return os;
}

istream& operator>>(istream& is, Vegetarien& vegetarien) {
    bool estVeg;
    cout << "Vegetarien (1=Oui, 0=Non): ";
    is >> estVeg;
    vegetarien.modifierVegetarien(estVeg);
    return is;
}