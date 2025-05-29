
#include "Employe.h"
#include"OperationInvalideException.h"
using namespace std;

Employe::Employe(string n, string p, string t, int id, double s)
    : Personne(n, p, t), idEmploye(id), salaire(s) {
    time(&dateEmbauche);
}
string Employe::getRole() const {
    return "Employe";
}

double Employe::getSalaire() const {
    return salaire;
}

string Employe::getDateEmbauche() const {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", localtime(&dateEmbauche));
    return string(buffer);
}


Employe Employe::operator+(double bonus) const {
    Employe result = *this;
    result.salaire += bonus;
    return result;
}
Employe Employe::operator-(double montant) const {
    Employe resultat = *this;
    if (resultat.salaire - montant < 0) {
        throw OperationInvalideException(
            "Le salaire ne peut pas etre negatif",
            "reduction de salaire",
            montant
        );
    }
    resultat.salaire -= montant;
    return resultat;
}

void Employe::modifier(string n, string p, string t, double s) {
    nom = n;
    prenom = p;
    telephone = t;
    salaire = s;
}

void Employe::supprimer() {
    nom = "";
    prenom = "";
    telephone = "";
    salaire = 0;
    
}
void Employe::ajouter(vector<shared_ptr<Employe>>& employes, shared_ptr<Employe> emp) {
    employes.push_back(emp);
}

ostream& operator<<(ostream& os, const Employe& emp) {
    os << emp.nom << " " << emp.prenom << " - " << emp.telephone
       << " - ID: " << emp.idEmploye << " - Salaire: " << emp.salaire
       << " - Embauche le: " << emp.getDateEmbauche();
    return os;
}

istream& operator>>(istream& is, Employe& emp) {
    cout << "Nom: ";
    is >> emp.nom;
    cout << "Prenom: ";
    is >> emp.prenom;
    cout << "Telephone: ";
    is >> emp.telephone;
    cout << "ID Employe: ";
    is >> emp.idEmploye;
    cout << "Salaire: ";
    is >> emp.salaire;
    return is;
}


void Employe::sauvegarderDansFichier(const string& nomFichier) const {
    ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        fichier << nom << endl;
        fichier << prenom << endl;
        fichier << telephone << endl;
        fichier << idEmploye << endl;
        fichier << salaire << endl;
        fichier << dateEmbauche << endl;
        fichier.close();
    }
}

Employe Employe::chargerDeFichier(const string& nomFichier) {
    Employe emp;
    ifstream fichier(nomFichier);
    if (fichier.is_open()) {
        getline(fichier, emp.nom);
        getline(fichier, emp.prenom);
        getline(fichier, emp.telephone);
        fichier >> emp.idEmploye;
        fichier >> emp.salaire;
        fichier >> emp.dateEmbauche;
        fichier.close();
    }
    return emp;
}
