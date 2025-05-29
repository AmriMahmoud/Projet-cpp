#include "Dessert.h"
#include <iostream>
#include <vector>
using namespace std;

Dessert::Dessert(string n, double p, string d, int tp, int cal)
    : Plat(n, p, d, tp), calories(cal) {}
ostream& operator<<(ostream& os, const Dessert& dessert) {
    os << "Dessert: " << static_cast<const Plat&>(dessert);
    os << " Calories: " << dessert.calories;
    return os;
}

istream& operator>>(istream& is, Dessert& dessert) {
    is >> static_cast<Plat&>(dessert);
    cout << "Calories: ";
    is >> dessert.calories;
    return is;
}
void Dessert::modifier(string n, double p, string d, int tp, int cal) {
    Plat::modifier(n, p, d, tp);
    calories = cal;
}
void Dessert::supprimer() {
    Plat::supprimer();
    calories = 0;
}
void Dessert::ajouter(vector<unique_ptr<Dessert>>& desserts, unique_ptr<Dessert> dessert) {
    desserts.push_back(move(dessert));
}
void Dessert::sauvegarderDansFichier(const string& nomFichier) const {
    ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        fichier << nom << endl;
        fichier << prix << endl;
        fichier << description << endl;
        fichier << tempsPreparation << endl;
        fichier << calories << endl;
        fichier.close();
    }
}

Dessert Dessert::chargerDeFichier(const string& nomFichier) {
    Dessert dessert;
    ifstream fichier(nomFichier);
    if (fichier.is_open()) {
        getline(fichier, dessert.nom);
        fichier >> dessert.prix;
        fichier.ignore();
        getline(fichier, dessert.description);
        fichier >> dessert.tempsPreparation;
        fichier >> dessert.calories;
        fichier.close();
    }
    return dessert;
}

void Dessert::afficherDetails(ostream& os) const {
    Plat::afficherDetails(os);
    os << " Calories: " << calories;
}

Dessert Dessert::operator+(int additionalCalories) const {
    Dessert result = *this;
    result.calories += additionalCalories;
    return result;
}

Dessert Dessert::operator-(int reducedCalories) const {
    Dessert result = *this;
    result.calories = max(0, result.calories - reducedCalories);
    return result;
}
