#pragma once
#include "Client.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <memory>

class Table {
    int numero;
    int capacite;
    bool estOccupee;
    time_t heureOccupation;
    Client* clientActuel;

public:
    Table(int num = 0, int cap = 0);
    void occuper(Client* client);
    void liberer();
    int getTempsOccupation() const;
    int getNumero() const;
    int getCapacite() const;
    bool estDisponible() const;
    void modifier(int num, int cap);
    void supprimer();
    friend ostream& operator<<(ostream& os, const Table& table);
    friend istream& operator>>(istream& is, Table& table);
};
