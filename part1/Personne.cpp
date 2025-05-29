#include "Personne.h"
using namespace std;

Personne::Personne(string n, string p, string t) : nom(n), prenom(p), telephone(t) {}

void Personne::modifier(string n, string p, string t) {
    nom = n;
    prenom = p;
    telephone = t;
}

void Personne::supprimer() {
    nom = "";
    prenom = "";
    telephone = "";
}

void Personne::ajouter(vector<shared_ptr<Personne>>& personnes, shared_ptr<Personne> personne) {
    personnes.push_back(personne);
}

ostream& operator<<(ostream& os, const Personne& personne) {
    os << personne.nom << " " << personne.prenom << " - " << personne.telephone
       << " (" << personne.getRole() << ")";
    return os;
}

istream& operator>>(istream& is, Personne& personne) {
    cout << "Nom: ";
    is >> personne.nom;
    cout << "Prenom: ";
    is >> personne.prenom;
    cout << "Telephone: ";
    is >> personne.telephone;
    return is;
}
