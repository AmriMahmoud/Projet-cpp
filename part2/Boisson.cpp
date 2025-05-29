
#include "Boisson.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

Boisson::Boisson(string n, double p, string d, double vol)
    : MenuItem(n, p, d), volume(vol) {}
ostream& operator<<(ostream& os, const Boisson& boisson) {
    os << static_cast<const MenuItem&>(boisson);
    os << " Volume: " << boisson.volume << " cL";
    return os;
}

istream& operator>>(istream& is, Boisson& boisson) {
    is >> static_cast<MenuItem&>(boisson);
    cout << "Volume (cL): ";
    is >> boisson.volume;
    return is;
}

void Boisson::modifier(string n, double p, string d, double vol) {
    MenuItem::modifier(n, p, d);
    volume = vol;
}

void Boisson::supprimer() {
    MenuItem::supprimer();
    volume = 0.0;
}

void Boisson::ajouter(vector<unique_ptr<Boisson>>& boissons, unique_ptr<Boisson> boisson) {
    boissons.push_back(move(boisson));
}

void Boisson::afficherDetails(ostream& os) const {
    os << " Volume: " << volume << " cL";
}
