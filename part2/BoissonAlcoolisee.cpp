
#include "BoissonAlcoolisee.h"
#include <iostream>
using namespace std;

BoissonAlcoolisee::BoissonAlcoolisee(string n, double p, string d, double vol, double alc)
    : Boisson(n, p, d, vol), tauxAlcool(alc) {}

double BoissonAlcoolisee::getTauxAlcool() const {
    return tauxAlcool;
}
std::unique_ptr<MenuItem> BoissonAlcoolisee::clone() const {
    return std::make_unique<BoissonAlcoolisee>(*this);
}

ostream& operator<<(ostream& os, const BoissonAlcoolisee& boisson) {
    os << "Boisson Alcoolisee: " << static_cast<const Boisson&>(boisson);
    os << " Taux d'alcool: " << boisson.tauxAlcool << "%";
    return os;
}

istream& operator>>(istream& is, BoissonAlcoolisee& boisson) {
    is >> static_cast<Boisson&>(boisson);
    cout << "Taux d'alcool (%): ";
    is >> boisson.tauxAlcool;
    return is;
}

void BoissonAlcoolisee::modifier(string n, double p, string d, double vol, double alc) {
    Boisson::modifier(n, p, d, vol);
    tauxAlcool = alc;
}

void BoissonAlcoolisee::supprimer() {
    Boisson::supprimer();
    tauxAlcool = 0.0;
}

void BoissonAlcoolisee::ajouter(vector<unique_ptr<BoissonAlcoolisee>>& boissons, unique_ptr<BoissonAlcoolisee> boisson) {
    boissons.push_back(move(boisson));
}

void BoissonAlcoolisee::afficherDetails(ostream& os) const {
    Boisson::afficherDetails(os);
    os << " Taux d'alcool: " << tauxAlcool << "%";
}
