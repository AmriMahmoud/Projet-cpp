#include "Table.h"
using namespace std;

Table::Table(int num, int cap) : numero(num), capacite(cap), estOccupee(false), clientActuel(nullptr) {}

void Table::occuper(Client* client) {
    if (!estOccupee) {
        clientActuel = client;
        estOccupee = true;
        time(&heureOccupation);
        cout << "Table " << numero << " occupee par " << client->getRole() << endl;
    }
}

void Table::liberer() {
    estOccupee = false;
    clientActuel = nullptr;
    cout << "Table " << numero << " liberee\n";
}

int Table::getTempsOccupation() const {
    if (!estOccupee) return 0;
    time_t maintenant;
    time(&maintenant);
    return difftime(maintenant, heureOccupation) / 60; 
}

int Table::getNumero() const { return numero; }
int Table::getCapacite() const { return capacite; }
bool Table::estDisponible() const { return !estOccupee; }

void Table::modifier(int num, int cap) {
    if (!estOccupee) {
        numero = num;
        capacite = cap;
    }
}

void Table::supprimer() {
    if (!estOccupee) {
        numero = 0;
        capacite = 0;
    }
}

ostream& operator<<(ostream& os, const Table& table) {
    os << "Table #" << table.numero << " (Capacite: " << table.capacite << ") - ";
    if (table.estOccupee) {
        os << "Occupee depuis " << table.getTempsOccupation() << " minutes";
        if (table.clientActuel) {
            os << " par " << table.clientActuel->getRole();
        }
    } else {
        os << "Disponible";
    }
    return os;
}

istream& operator>>(istream& is, Table& table) {
    cout << "Numuro de table: ";
    is >> table.numero;
    cout << "Capacite: ";
    is >> table.capacite;
    return is;
}
