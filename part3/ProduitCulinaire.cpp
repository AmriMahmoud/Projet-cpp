#include "ProduitCulinaire.h"

ProduitCulinaire::ProduitCulinaire(string n, double p, string o) : nom(n), prixHT(p), origine(o) {}

string ProduitCulinaire::getNom() const { return nom; }
double ProduitCulinaire::getPrixHT() const { return prixHT; }
string ProduitCulinaire::getOrigine() const { return origine; }
ostream& operator<<(ostream& os, const ProduitCulinaire& produit) {
    os << "Produit: " << produit.nom << " - Prix HT: " << produit.prixHT
       << "TND - Origine: " << produit.origine;
    return os;
}

istream& operator>>(istream& is, ProduitCulinaire& produit) {
    cout << "Nom du produit: ";
    is.ignore();
    getline(is, produit.nom);
    cout << "Prix HT: ";
    is >> produit.prixHT;
    cout << "Origine: ";
    is.ignore();
    getline(is, produit.origine);
    return is;
}

void ProduitCulinaire::modifier(string n, double p, string o) {
    nom = n;
    prixHT = p;
    origine = o;
}

void ProduitCulinaire::supprimer() {
    nom = "";
    prixHT = 0.0;
    origine = "";
}

void ProduitCulinaire::ajouter(vector<ProduitCulinaire*>& produits, ProduitCulinaire* produit) {
    produits.push_back(produit);
}
