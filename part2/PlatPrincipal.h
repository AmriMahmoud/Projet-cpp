#ifndef PLATPRINCIPAL_H
#define PLATPRINCIPAL_H
#include "Plat.h"
#include "Vegetarien.h"
#include <iostream>

using namespace std;

class PlatPrincipal : public Plat, public Vegetarien {
    string accompagnement;
    bool vegetarien;
public:
    PlatPrincipal(string n = "", double p = 0.0, string d = "", int tp = 0, string acc = "", bool veg = false);
    bool estVegetarien() const override;

    friend ostream& operator<<(ostream& os, const PlatPrincipal& plat);
    friend istream& operator>>(istream& is, PlatPrincipal& plat);

    void modifier(string n, double p, string d, int tp, string acc, bool veg);
    void supprimer() override;
    static void ajouter(vector<unique_ptr<PlatPrincipal>>& plats, unique_ptr<PlatPrincipal> plat);

    void afficherDetails(ostream& os) const override;
};
#endif
