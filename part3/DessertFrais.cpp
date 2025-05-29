// DessertFrais.cpp - Implementation with fstream
#include "DessertFrais.h"

DessertFrais::DessertFrais(string n, double p, string o, int tp, string diff, bool lact, bool glut, vector<string> allergenes)
    : PreparationMaison(n, p, o, tp, diff), lactose(lact), gluten(glut) {
    listeAllergenes = allergenes;
}

int DessertFrais::getTemperatureOptimal() const { return 4; }
int DessertFrais::getDureeConservation() const { return 48; }
string DessertFrais::getInstructionsStockage() const { return "Conserver au refrigerateur"; }

string DessertFrais::genererEtiquette() const {
    return PreparationMaison::genererEtiquette() +
           " - " + (lactose ? "Contient lactose" : "Sans lactose") +
           " - " + (gluten ? "Contient gluten" : "Sans gluten");
}

double DessertFrais::calculerPrixTTC() const {
    return prixHT * 1.10; 
}

ostream& operator<<(ostream& os, const DessertFrais& dessert) {
    os << static_cast<const PreparationMaison&>(dessert);
    os << " - Lactose: " << (dessert.lactose ? "Oui" : "Non")
       << " - Gluten: " << (dessert.gluten ? "Oui" : "Non");

    os << " - Allergenes: ";
    for (const auto& allergene : dessert.listeAllergenes) {
        os << allergene << ", ";
    }

    os << " - Conservation: " << dessert.getTemperatureOptimal() << "°C, "
       << dessert.getDureeConservation() << "h";

    return os;
}

istream& operator>>(istream& is, DessertFrais& dessert) {
    is >> static_cast<PreparationMaison&>(dessert);

    cout << "Contient du lactose (1=Oui, 0=Non): ";
    is >> dessert.lactose;

    cout << "Contient du gluten (1=Oui, 0=Non): ";
    is >> dessert.gluten;

    int nbAllergenes;
    cout << "Nombre d'allergenes: ";
    is >> nbAllergenes;

    dessert.listeAllergenes.clear();
    for (int i = 0; i < nbAllergenes; ++i) {
        string allergene;
        cout << "Allergene " << (i+1) << ": ";
        is.ignore();
        getline(is, allergene);
        dessert.listeAllergenes.push_back(allergene);
    }

    return is;
}

void DessertFrais::modifier(string n, double p, string o, int tp, string diff, bool lact, bool glut, vector<string> allergenes) {
    PreparationMaison::modifier(n, p, o, tp, diff);
    lactose = lact;
    gluten = glut;
    listeAllergenes = allergenes;
}

void DessertFrais::supprimer() {
    PreparationMaison::supprimer();
    lactose = false;
    gluten = false;
    listeAllergenes.clear();
}

void DessertFrais::ajouter(vector<DessertFrais*>& desserts, DessertFrais* dessert) {
    desserts.push_back(dessert);
}

void DessertFrais::sauvegarderDansFichier(const string& nomFichier) const {
    ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        fichier << nom << endl;
        fichier << prixHT << endl;
        fichier << origine << endl;
        fichier << tempsPreparation << endl;
        fichier << difficulte << endl;
        fichier << lactose << endl;
        fichier << gluten << endl;

        fichier << listeAllergenes.size() << endl;
        for (const auto& allergene : listeAllergenes) {
            fichier << allergene << endl;
        }

        fichier.close();
    }
}

DessertFrais* DessertFrais::chargerDeFichier(const string& nomFichier) {
    string n, o, diff;
    double p;
    int tp;
    bool lact, glut;
    vector<string> allergenes;

    ifstream fichier(nomFichier);
    if (fichier.is_open()) {
        getline(fichier, n);
        fichier >> p;
        fichier.ignore();
        getline(fichier, o);
        fichier >> tp;
        fichier.ignore();
        getline(fichier, diff);
        fichier >> lact;
        fichier >> glut;

        int nbAllergenes;
        fichier >> nbAllergenes;
        fichier.ignore();

        for (int i = 0; i < nbAllergenes; ++i) {
            string allergene;
            getline(fichier, allergene);
            allergenes.push_back(allergene);
        }

        fichier.close();

        return new DessertFrais(n, p, o, tp, diff, lact, glut, allergenes);
    }
    return nullptr;
}
