#include "Reservation.h"
#include <fstream>
using namespace std;

int Reservation::nextId = 0;

Reservation::Reservation(Client* cli, Table* tab, int nbP)
    : idReservation(++nextId), client(cli), table(tab), nbPersonnes(nbP), annulee(false) {
    time(&date);
}

void Reservation::confirmer() {
    if (table && table->estDisponible()) {
        table->occuper(client);
        cout << "Reservation #" << idReservation << " confirmee\n";
    }
}

void Reservation::annuler() {
    annulee = true;
    if (table && !table->estDisponible()) {
        table->liberer();
    }
    cout << "Reservation #" << idReservation << " annulee\n";
}

bool Reservation::estValide() const {
    return !annulee;
}

string Reservation::getDetails() const {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M", localtime(&date));

    string clientInfo = client ? client->getRole() : "Client inconnu";
    string tableInfo = table ? "Table " + to_string(table->getNumero()) : "Table inconnue";

    string status = estValide() ? "Active" : "Annulee";

    return "Res #" + to_string(idReservation) + " - " + clientInfo +
           " - " + tableInfo + " - " + buffer +
           " - Personnes: " + to_string(nbPersonnes) +
           " - Statut: " + status;
}

void Reservation::modifier(Client* cli, Table* tab, int nbP) {
    if (!annulee) {
        if (table && !table->estDisponible()) {
            table->liberer();
        }
        client = cli;
        table = tab;
        nbPersonnes = nbP;
        time(&date);
    }
}

void Reservation::supprimer() {
    annuler();
}

ostream& operator<<(ostream& os, const Reservation& reservation) {
    os << reservation.getDetails();
    if (reservation.annulee) {
        os << " (ANNULEE)";
    }
    return os;
}

istream& operator>>(istream& is, Reservation& reservation) {
    cout << "Nombre de personnes: ";
    is >> reservation.nbPersonnes;
    return is;
}
void Reservation::setNbPersonnes(unsigned int nouveauNbPersonnes) {
    nbPersonnes = nouveauNbPersonnes;
}

void Reservation::modifierNbPersonnes(unsigned int nouveauNbPersonnes) {
    nbPersonnes = nouveauNbPersonnes;
}
