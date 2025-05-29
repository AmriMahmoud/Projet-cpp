#pragma once
#include "Employe.h"
#include "Evaluateur.h"
#include <fstream>
#include <string>

class ChefCuisinier : public Employe, public Evaluateur {
    string specialite;

public:
    ChefCuisinier(string n = "", string p = "", string t = "", int id = 0, double s = 0.0, string spec = "");
    string getRole() const override;
    int evaluerQualite() override;
    void modifier(string n, string p, string t, double s, string spec);
    void supprimer();
    static void ajouter(vector<shared_ptr<ChefCuisinier>>& chefs, shared_ptr<ChefCuisinier> chef);
    friend ostream& operator<<(ostream& os, const ChefCuisinier& chef);
    friend istream& operator>>(istream& is, ChefCuisinier& chef);
    void sauvegarderDansFichier(const string& nomFichier) const;
    static ChefCuisinier chargerDeFichier(const string& nomFichier);
};
