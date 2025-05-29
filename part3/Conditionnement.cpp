#include "Conditionnement.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Conditionnement& conditionnement) {
    os << "Conditionnement: " << conditionnement.getMateriau()
       << " (Recyclable: " << (conditionnement.getEstRecyclable() ? "Oui" : "Non") << ")"
       << " Impact ecologique: " << conditionnement.getImpactEcologique();
    return os;
}

istream& operator>>(istream& is, Conditionnement& conditionnement) {
    return is;
}