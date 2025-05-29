#pragma once
#include "Employe.h"
#include "Table.h"
#include "Reservation.h"
#include <vector>
#include <iostream>

class Serveur : public Employe {
    vector<Table*> tablesResponsables;

public:
    Serveur(string n = "", string p = "", string t = "", int id = 0, double s = 0.0);
    string getRole() const override;
    void affecterTable(Table* table);
    Serveur& operator=(const Serveur& other);
    void modifier(string n, string p, string t, double s);
    void supprimer();
    friend ostream& operator<<(ostream& os, const Serveur& serveur);
    friend istream& operator>>(istream& is, Serveur& serveur);
};
