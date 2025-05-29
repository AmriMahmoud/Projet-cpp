#include "SauceMaison.h"

SauceMaison::SauceMaison(string n, double p, string o, int tp, string diff, int piquant, string b, vector<string> allergenes)
    : PreparationMaison(n, p, o, tp, diff), niveauPiquant(piquant), base(b) {
    listeAllergenes = allergenes;
}

bool SauceMaison::getEstRecyclable() const { return true; }
string SauceMaison::getMateriau() const { return "Verre"; }
double SauceMaison::getImpactEcologique() const { return 0.2; }

string SauceMaison::genererEtiquette() const {
    return PreparationMaison::genererEtiquette() + " - " + base + " - Piquant: " + to_string(niveauPiquant);
}

double SauceMaison::calculerPrixTTC() const {
    return prixHT * 1.20; 
}

ostream& operator<<(ostream& os, const SauceMaison& sauce) {
    os << static_cast<const PreparationMaison&>(sauce);
    os << " - Base: " << sauce.base
       << " - Niveau piquant: " << sauce.niveauPiquant;

    os << " - Allergenes: ";
    for (const auto& allergene : sauce.listeAllergenes) {
        os << allergene << ", ";
    }

    os << " - Conditionnement: " << sauce.getMateriau()
       << " (Recyclable: " << (sauce.getEstRecyclable() ? "Oui" : "Non") << ")";

    return os;
}

istream& operator>>(istream& is, SauceMaison& sauce) {
    is >> static_cast<PreparationMaison&>(sauce);

    cout << "Base: ";
    is.ignore();
    getline(is, sauce.base);

    cout << "Niveau piquant (1-10): ";
    is >> sauce.niveauPiquant;

    int nbAllergenes;
    cout << "Nombre d'allergenes: ";
    is >> nbAllergenes;

    sauce.listeAllergenes.clear();
    for (int i = 0; i < nbAllergenes; ++i) {
        string allergene;
        cout << "Allergene " << (i+1) << ": ";
        is.ignore();
        getline(is, allergene);
        sauce.listeAllergenes.push_back(allergene);
    }

    return is;
}

void SauceMaison::modifier(string n, double p, string o, int tp, string diff, int piquant, string b, vector<string> allergenes) {
    PreparationMaison::modifier(n, p, o, tp, diff);
    niveauPiquant = piquant;
    base = b;
    listeAllergenes = allergenes;
}

void SauceMaison::supprimer() {
    PreparationMaison::supprimer();
    niveauPiquant = 0;
    base = "";
    listeAllergenes.clear();
}

void SauceMaison::ajouter(vector<SauceMaison*>& sauces, SauceMaison* sauce) {
    sauces.push_back(sauce);
}
