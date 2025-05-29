#include "Entree.h"
#include <iostream>
#include <vector>

using namespace std;

Entree::Entree(string n, double p, string d, int tp, bool pgt)
    : Plat(n, p, d, tp), partageable(pgt) {}

ostream& operator<<(ostream& os, const Entree& entree) {
    os << "Entree: " << static_cast<const Plat&>(entree);
    os << " Partageable: " << (entree.partageable ? "Oui" : "Non");
    return os;
}

istream& operator>>(istream& is, Entree& entree) {
    is >> static_cast<Plat&>(entree);
    cout << "Partageable (1=Oui, 0=Non): ";
    is >> entree.partageable;
    return is;
}

void Entree::modifier(string n, double p, string d, int tp, bool pgt) {
    Plat::modifier(n, p, d, tp);
    partageable = pgt;
}

void Entree::supprimer() {
    Plat::supprimer();
    partageable = false;
}

void Entree::ajouter(vector<unique_ptr<Entree>>& entrees, unique_ptr<Entree> entree) {
    entrees.push_back(move(entree));
}

void Entree::afficherDetails(ostream& os) const {
    Plat::afficherDetails(os);
    os << " Partageable: " << (partageable ? "Oui" : "Non");
}
