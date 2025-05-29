#include "Serveur.h"
using namespace std;

Serveur::Serveur(string n, string p, string t, int id, double s)
    : Employe(n, p, t, id, s) {}

string Serveur::getRole() const {
    return "Serveur";
}

void Serveur::affecterTable(Table* table) {
    if (table) {
        tablesResponsables.push_back(table);
        cout << "Table " << table->getNumero() << " affectee a " << nom << endl;
    }
}

Serveur& Serveur::operator=(const Serveur& other) {
    if (this != &other) {
        Employe::operator=(other);
        tablesResponsables.clear();
        for (const auto& table : other.tablesResponsables) {
            tablesResponsables.push_back(table);
        }
    }
    return *this;
}

void Serveur::modifier(string n, string p, string t, double s) {
    Employe::modifier(n, p, t, s);
}

void Serveur::supprimer() {
    Employe::supprimer();
    tablesResponsables.clear();
}

ostream& operator<<(ostream& os, const Serveur& serveur) {
    os << static_cast<const Employe&>(serveur);
    os << endl << "Tables gerees: " << serveur.tablesResponsables.size();
    for (size_t i = 0; i < serveur.tablesResponsables.size(); ++i) {
        if (serveur.tablesResponsables[i]) {
            os << endl << "  - Table " << serveur.tablesResponsables[i]->getNumero();
        }
    }
    return os;
}

istream& operator>>(istream& is, Serveur& serveur) {
    is >> static_cast<Employe&>(serveur);
    return is;
}
