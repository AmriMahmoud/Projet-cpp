#include "MenuItem.h"
using namespace std;

MenuItem::MenuItem(string n, double p, string d) : nom(n), prix(p), description(d) {}

ostream& operator<<(ostream& os, const MenuItem& item) {
    os << item.nom << " (" << item.prix << "TND) - " << item.description;
    item.afficherDetails(os);
    return os;
}

istream& operator>>(istream& is, MenuItem& item) {
    cout << "Nom: ";
    is.ignore();
    getline(is, item.nom);
    cout << "Prix: ";
    is >> item.prix;
    cout << "Description: ";
    is.ignore();
    getline(is, item.description);
    return is;
}

void MenuItem::modifier(string n, double p, string d) {
    nom = n;
    prix = p;
    description = d;
}

void MenuItem::supprimer() {
    nom = "";
    prix = 0.0;
    description = "";
}

void MenuItem::ajouter(vector<unique_ptr<MenuItem>>& items, unique_ptr<MenuItem> item) {
    items.push_back(move(item));
}
