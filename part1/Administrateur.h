// Administrateur.h
#pragma once
#include "Employe.h"
#include "Gestionnaire.h"
#include <iostream>

class Administrateur : public Employe, public Gestionnaire {
public:
    Administrateur(string n = "", string p = "", string t = "", int id = 0, double s = 0.0);
    string getRole() const override;
    void gererSysteme() override;
    void modifier(string n, string p, string t, double s);
    void supprimer();
    static void ajouter(vector<shared_ptr<Administrateur>>& admins, shared_ptr<Administrateur> admin);
    friend ostream& operator<<(ostream& os, const Administrateur& admin);
    friend istream& operator>>(istream& is, Administrateur& admin);
};
