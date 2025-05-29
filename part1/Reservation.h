#pragma once
#include "Client.h"
#include "Table.h"
#include <ctime>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Reservation {
    static int nextId;
    int idReservation;
    Client* client;
    Table* table;
    time_t date;
    int nbPersonnes;
    bool annulee;

public:
    Reservation(Client* cli = nullptr, Table* tab = nullptr, int nbP = 0);
    void confirmer();
    void annuler();
    bool estValide() const;
    string getDetails() const;
    void modifier(Client* cli, Table* tab, int nbP);
    void supprimer();
    friend ostream& operator<<(ostream& os, const Reservation& reservation);
    friend istream& operator>>(istream& is, Reservation& reservation);
    void setNbPersonnes(unsigned int nouveauNbPersonnes);
    void modifierNbPersonnes(unsigned int nouveauNbPersonnes);
};
