#include "ChefCuisinier.h"
using namespace std;

ChefCuisinier::ChefCuisinier(string n, string p, string t, int id, double s, string spec)
    : Employe(n, p, t, id, s), specialite(spec) {}

string ChefCuisinier::getRole() const {
    return "Chef Cuisinier (" + specialite + ")";
}

int ChefCuisinier::evaluerQualite() {
    return 5;
}
void ChefCuisinier::modifier(string n, string p, string t, double s, string spec) {
    Employe::modifier(n, p, t, s);
    specialite = spec;
}

void ChefCuisinier::supprimer() {
    Employe::supprimer();
    specialite = "";
}
void ChefCuisinier::ajouter(vector<shared_ptr<ChefCuisinier>>& chefs, shared_ptr<ChefCuisinier> chef) {
    chefs.push_back(chef);
}

ostream& operator<<(ostream& os, const ChefCuisinier& chef) {
    os << static_cast<const Employe&>(chef);
    os << " - Specialite: " << chef.specialite;
    return os;
}

istream& operator>>(istream& is, ChefCuisinier& chef) {
    is >> static_cast<Employe&>(chef);
    cout << "Specialite: ";
    is >> chef.specialite;
    return is;
}

void ChefCuisinier::sauvegarderDansFichier(const string& nomFichier) const {
    ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        fichier << nom << endl;
        fichier << prenom << endl;
        fichier << telephone << endl;
        fichier << idEmploye << endl;
        fichier << salaire << endl;
        fichier << dateEmbauche << endl;
        fichier << specialite << endl;
        fichier.close();
    }
}

ChefCuisinier ChefCuisinier::chargerDeFichier(const string& nomFichier) {
    ChefCuisinier chef;
    ifstream fichier(nomFichier);
    if (fichier.is_open()) {
        getline(fichier, chef.nom);
        getline(fichier, chef.prenom);
        getline(fichier, chef.telephone);
        fichier >> chef.idEmploye;
        fichier >> chef.salaire;
        fichier >> chef.dateEmbauche;
        fichier.ignore(); 
        getline(fichier, chef.specialite);
        fichier.close();
    }
    return chef;
}
