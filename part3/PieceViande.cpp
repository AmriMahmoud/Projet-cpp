#include "PieceViande.h"

PieceViande::PieceViande(string n, double p, string o, double pd, int am, string gq)
    : ProduitCulinaire(n, p, o), poids(pd), ageMaturation(am), gradeQualite(gq) {}

double PieceViande::calculerPrixTTC() const {
    return prixHT * 1.10; 
}

string PieceViande::genererEtiquette() const {
    return nom + " (" + gradeQualite + ") - " + to_string(poids) + "kg - " + origine;
}

ostream& operator<<(ostream& os, const PieceViande& viande) {
    os << static_cast<const ProduitCulinaire&>(viande);
    os << " - Poids: " << viande.poids << "kg"
       << " - Age de maturation: " << viande.ageMaturation << " jours"
       << " - Grade: " << viande.gradeQualite;
    return os;
}

istream& operator>>(istream& is, PieceViande& viande) {
    is >> static_cast<ProduitCulinaire&>(viande);

    cout << "Poids (kg): ";
    is >> viande.poids;

    cout << "Age de maturation (jours): ";
    is >> viande.ageMaturation;

    cout << "Grade de qualite: ";
    is.ignore();
    getline(is, viande.gradeQualite);

    return is;
}

// CRUD methods
void PieceViande::modifier(string n, double p, string o, double pd, int am, string gq) {
    ProduitCulinaire::modifier(n, p, o);
    poids = pd;
    ageMaturation = am;
    gradeQualite = gq;
}

void PieceViande::supprimer() {
    ProduitCulinaire::supprimer();
    poids = 0.0;
    ageMaturation = 0;
    gradeQualite = "";
}

void PieceViande::ajouter(vector<PieceViande*>& viandes, PieceViande* viande) {
    viandes.push_back(viande);
}
