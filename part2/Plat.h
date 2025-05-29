#ifndef PLAT_H
#define PLAT_H
#include "MenuItem.h"
#include <fstream>
#include <iostream>

using namespace std;

class Plat : public MenuItem {
protected:
    int tempsPreparation;
public:
    Plat(string n = "", double p = 0.0, string d = "", int tp = 0);

    unique_ptr<MenuItem> clone() const override;

    friend ostream& operator<<(ostream& os, const Plat& plat);
    friend istream& operator>>(istream& is, Plat& plat);

    void modifier(string n, double p, string d, int tp);
    void supprimer() override;
    static void ajouter(vector<unique_ptr<Plat>>& plats, unique_ptr<Plat> plat);

    void sauvegarderDansFichier(const string& nomFichier) const;
    static Plat chargerDeFichier(const string& nomFichier);

    void afficherDetails(ostream& os) const override;
};
#endif
