#include "BoissonNonAlcoolisee.h"
#include <iostream>
using namespace std;

BoissonNonAlcoolisee::BoissonNonAlcoolisee(string n, double p, string d, double vol, bool gazeux)
    : Boisson(n, p, d, vol), estGazeuse(gazeux) {}
std::unique_ptr<MenuItem> BoissonNonAlcoolisee::clone() const {
    return std::make_unique<BoissonNonAlcoolisee>(*this);
}
ostream& operator<<(ostream& os, const BoissonNonAlcoolisee& boisson) {
    os << "Boisson Non-Alcoolisee: " << static_cast<const Boisson&>(boisson);
    os << " Gazeuse: " << (boisson.estGazeuse ? "Oui" : "Non");
    return os;
}

istream& operator>>(istream& is, BoissonNonAlcoolisee& boisson) {
    is >> static_cast<Boisson&>(boisson);
    cout << "Gazeuse (1=Oui, 0=Non): ";
    is >> boisson.estGazeuse;
    return is;
}

void BoissonNonAlcoolisee::modifier(string n, double p, string d, double vol, bool gazeux) {
    Boisson::modifier(n, p, d, vol);
    estGazeuse = gazeux;
}

void BoissonNonAlcoolisee::supprimer() {
    Boisson::supprimer();
    estGazeuse = false;
}

void BoissonNonAlcoolisee::ajouter(vector<unique_ptr<BoissonNonAlcoolisee>>& boissons, unique_ptr<BoissonNonAlcoolisee> boisson) {
    boissons.push_back(move(boisson));
}

void BoissonNonAlcoolisee::afficherDetails(ostream& os) const {
    Boisson::afficherDetails(os);
    os << " Gazeuse: " << (estGazeuse ? "Oui" : "Non");
}
