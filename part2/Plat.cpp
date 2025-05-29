#include "Plat.h"
#include <iostream>
using namespace std;

Plat::Plat(string n, double p, string d, int tp) : MenuItem(n, p, d), tempsPreparation(tp) {}

unique_ptr<MenuItem> Plat::clone() const {
    return make_unique<Plat>(*this);
}

ostream& operator<<(ostream& os, const Plat& plat) {
    os << static_cast<const MenuItem&>(plat);
    os << " [Pret en " << plat.tempsPreparation << " min]";
    return os;
}

istream& operator>>(istream& is, Plat& plat) {
    is >> static_cast<MenuItem&>(plat);
    cout << "Temps de preparation (min): ";
    is >> plat.tempsPreparation;
    return is;
}

void Plat::modifier(string n, double p, string d, int tp) {
    MenuItem::modifier(n, p, d);
    tempsPreparation = tp;
}

void Plat::supprimer() {
    MenuItem::supprimer();
    tempsPreparation = 0;
}

void Plat::ajouter(vector<unique_ptr<Plat>>& plats, unique_ptr<Plat> plat) {
    plats.push_back(move(plat));
}

void Plat::sauvegarderDansFichier(const string& nomFichier) const {
    ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        fichier << nom << endl;
        fichier << prix << endl;
        fichier << description << endl;
        fichier << tempsPreparation << endl;
        fichier.close();
    }
}

Plat Plat::chargerDeFichier(const string& nomFichier) {
    Plat plat;
    ifstream fichier(nomFichier);
    if (fichier.is_open()) {
        getline(fichier, plat.nom);
        fichier >> plat.prix;
        fichier.ignore();
        getline(fichier, plat.description);
        fichier >> plat.tempsPreparation;
        fichier.close();
    }
    return plat;
}

void Plat::afficherDetails(ostream& os) const {
    os << " [Pret en " << tempsPreparation << " min]";
}
