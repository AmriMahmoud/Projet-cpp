#include"Alcoolise.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Alcoolise& alcoolise) {
    os << "Taux d'alcool: " << alcoolise.getTauxAlcool() << "%";
    return os;
}

istream& operator>>(istream& is, Alcoolise& alcoolise) {
    double taux;
    cout << "Taux d'alcool (%): ";
    is >> taux;
    alcoolise.modifierTauxAlcool(taux);
    return is;
}