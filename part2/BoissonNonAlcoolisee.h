#ifndef BOISSONNONALCOOLISEE_H
#define BOISSONNONALCOOLISEE_H
#include "Boisson.h"
#include <iostream>

using namespace std;

class BoissonNonAlcoolisee : public Boisson {
    bool estGazeuse;
public:
    BoissonNonAlcoolisee(string n = "", double p = 0.0, string d = "", double vol = 0.0, bool gazeux = false);
    unique_ptr<MenuItem> clone() const override;
    friend ostream& operator<<(ostream& os, const BoissonNonAlcoolisee& boisson);
    friend istream& operator>>(istream& is, BoissonNonAlcoolisee& boisson);
    void modifier(string n, double p, string d, double vol, bool gazeux);
    void supprimer() override;
    static void ajouter(vector<unique_ptr<BoissonNonAlcoolisee>>& boissons, unique_ptr<BoissonNonAlcoolisee> boisson);
    void afficherDetails(ostream& os) const override;
};
#endif
