#include "Administrateur.h"
using namespace std;

Administrateur::Administrateur(string n, string p, string t, int id, double s)
    : Employe(n, p, t, id, s) {}

string Administrateur::getRole() const {
    return "Administrateur";
}
void Administrateur::gererSysteme() {
    cout << "Gestion du systeme en cours...\n";
}

void Administrateur::modifier(string n, string p, string t, double s) {
    Employe::modifier(n, p, t, s);
}
void Administrateur::ajouter(vector<shared_ptr<Administrateur>>& admins, shared_ptr<Administrateur> admin) {
    admins.push_back(admin);
}

void Administrateur::supprimer() {
    Employe::supprimer();
}

ostream& operator<<(ostream& os, const Administrateur& admin) {
    os << static_cast<const Employe&>(admin);
    return os;
}

istream& operator>>(istream& is, Administrateur& admin) {
    is >> static_cast<Employe&>(admin);
    return is;
}
