#include "PlatPrincipal.h"
#include <iostream>
using namespace std;

PlatPrincipal::PlatPrincipal(string n, double p, string d, int tp, string acc, bool veg)
    : Plat(n, p, d, tp), accompagnement(acc), vegetarien(veg) {}

bool PlatPrincipal::estVegetarien() const {
    return vegetarien;
}

ostream& operator<<(ostream& os, const PlatPrincipal& plat) {
    os << "Plat Principal: " << static_cast<const Plat&>(plat);
    os << " Accompagnement: " << plat.accompagnement;
    os << " Vegetarien: " << (plat.vegetarien ? "Oui" : "Non");
    return os;
}

istream& operator>>(istream& is, PlatPrincipal& plat) {
    is >> static_cast<Plat&>(plat);
    cout << "Accompagnement: ";
    is.ignore();
    getline(is, plat.accompagnement);
    cout << "Vegetarien (1=Oui, 0=Non): ";
    is >> plat.vegetarien;
    return is;
}

void PlatPrincipal::modifier(string n, double p, string d, int tp, string acc, bool veg) {
    Plat::modifier(n, p, d, tp);
    accompagnement = acc;
    vegetarien = veg;
}

void PlatPrincipal::supprimer() {
    Plat::supprimer();
    accompagnement = "";
    vegetarien = false;
}

void PlatPrincipal::ajouter(vector<unique_ptr<PlatPrincipal>>& plats, unique_ptr<PlatPrincipal> plat) {
    plats.push_back(move(plat));
}

void PlatPrincipal::afficherDetails(ostream& os) const {
    Plat::afficherDetails(os);
    os << " Accompagnement: " << accompagnement;
    os << " Vegetarien: " << (vegetarien ? "Oui" : "Non");
}
