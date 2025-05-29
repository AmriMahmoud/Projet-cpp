
#pragma once
#include "Personne.h"
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>

class Employe : public Personne {
protected:
    int idEmploye;
    double salaire;
    time_t dateEmbauche;

public:
    Employe(string n = "", string p = "", string t = "", int id = 0, double s = 0.0);
    virtual ~Employe() = default;
    string getRole() const override;
    double getSalaire() const;
    string getDateEmbauche() const;
    Employe operator+(double bonus) const;
    Employe operator-(double reduction) const;
    void modifier(string n, string p, string t, double s);
    void supprimer();
    static void ajouter(vector<shared_ptr<Employe>>& employes, shared_ptr<Employe> emp);
    friend ostream& operator<<(ostream& os, const Employe& emp);
    friend istream& operator>>(istream& is, Employe& emp);
    void sauvegarderDansFichier(const string& nomFichier) const;
    static Employe chargerDeFichier(const string& nomFichier);
};
