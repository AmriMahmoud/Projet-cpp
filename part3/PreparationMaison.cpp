#include "PreparationMaison.h"
#include"FichierException.h"

PreparationMaison::PreparationMaison(string n, double p, string o, int tp, string diff)
    : ProduitCulinaire(n, p, o), tempsPreparation(tp), difficulte(diff) {}

double PreparationMaison::calculerPrixTTC() const {
    return prixHT * 1.20; 
}

string PreparationMaison::genererEtiquette() const {
    return nom + " - " + difficulte + " - " + to_string(tempsPreparation) + "min";
}

ostream& operator<<(ostream& os, const PreparationMaison& prep) {
    os << static_cast<const ProduitCulinaire&>(prep);
    os << " - Temps de preparation: " << prep.tempsPreparation
       << "min - Difficulte: " << prep.difficulte;
    return os;
}

istream& operator>>(istream& is, PreparationMaison& prep) {
    is >> static_cast<ProduitCulinaire&>(prep);
    cout << "Temps de preparation (min): ";
    is >> prep.tempsPreparation;
    cout << "Difficulte: ";
    is.ignore();
    getline(is, prep.difficulte);
    return is;
}

void PreparationMaison::modifier(string n, double p, string o, int tp, string diff) {
    ProduitCulinaire::modifier(n, p, o);
    tempsPreparation = tp;
    difficulte = diff;
}

void PreparationMaison::supprimer() {
    ProduitCulinaire::supprimer();
    tempsPreparation = 0;
    difficulte = "";
}

void PreparationMaison::ajouter(vector<PreparationMaison*>& preps, PreparationMaison* prep) {
    preps.push_back(prep);
}

void PreparationMaison::sauvegarderDansFichier(const string& nomFichier) const {
    ofstream fichier(nomFichier);
    if (!fichier) {
        throw FichierException("Impossible d'ouvrir le fichier en ecriture", nomFichier, "ecriture");
    }

    try {
        fichier << nom << endl;
        fichier << prixHT << endl;
        fichier << origine << endl;
        fichier << tempsPreparation << endl;
        fichier << difficulte << endl;

        if (!fichier.good()) {
            throw FichierException("Erreur pendant l'ecriture des donnees", nomFichier, "ecriture");
        }

        fichier.close();
    } catch (...) {
        fichier.close();
        throw; 
    }
}


PreparationMaison* PreparationMaison::chargerDeFichier(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier) {
        throw FichierException("Impossible d'ouvrir le fichier en lecture", nomFichier, "lecture");
    }

    string n, o, diff;
    double p;
    int tp;

    try {
        getline(fichier, n);
        fichier >> p;
        fichier.ignore();
        getline(fichier, o);
        fichier >> tp;
        fichier.ignore();
        getline(fichier, diff);

        if (fichier.fail()) {
            throw FichierException("Format de fichier invalide", nomFichier, "lecture");
        }

        fichier.close();
        return new PreparationMaison(n, p, o, tp, diff);

    } catch (const FichierException& e) {
        fichier.close();
        throw;  
    } catch (...) {
        fichier.close();
        throw FichierException("Erreur inattendue lors de la lecture", nomFichier, "lecture");
    }
}


PreparationMaison PreparationMaison::operator+(int tempsSupplementaire) const {
    PreparationMaison result = *this;
    result.tempsPreparation += tempsSupplementaire;
    return result;
}

PreparationMaison PreparationMaison::operator-(int tempsReduit) const {
    PreparationMaison result = *this;
    result.tempsPreparation = max(0, result.tempsPreparation - tempsReduit);
    return result;
}
