#include "Allergenes.h"

bool Allergenes::contientAllergene(const string& allergene) const {
    return find(listeAllergenes.begin(), listeAllergenes.end(), allergene) != listeAllergenes.end();
}

vector<string> Allergenes::getListeComplete() const {
    return listeAllergenes;
}

ostream& operator<<(ostream& os, const Allergenes& allergenes) {
    os << "Allergenes: ";
    for (const auto& allergene : allergenes.listeAllergenes) {
        os << allergene << ", ";
    }
    return os;
}

istream& operator>>(istream& is, Allergenes& allergenes) {
    int nbAllergenes;
    cout << "Nombre d'allergenes: ";
    is >> nbAllergenes;
    allergenes.listeAllergenes.clear();
    for (int i = 0; i < nbAllergenes; ++i) {
        string allergene;
        cout << "Allergene " << (i + 1) << ": ";
        is.ignore();
        getline(is, allergene);
        allergenes.listeAllergenes.push_back(allergene);
    }
    return is;
}

void Allergenes::modifierAllergenes(const vector<string>& nouvelleListe) {
    listeAllergenes = nouvelleListe;
}

void Allergenes::supprimerAllergenes() {
    listeAllergenes.clear();
}

void Allergenes::ajouterAllergene(const string& allergene) {
    if (!contientAllergene(allergene)) {
        listeAllergenes.push_back(allergene);
    }
}