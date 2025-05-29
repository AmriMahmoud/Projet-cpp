#ifndef BOISSONALCOOLISEE_H
#define BOISSONALCOOLISEE_H
#include "Boisson.h"
#include "Alcoolise.h"
#include <iostream>

using namespace std;

class BoissonAlcoolisee : public Boisson, public Alcoolise {
    double tauxAlcool;
public:
    BoissonAlcoolisee(string n = "", double p = 0.0, string d = "", double vol = 0.0, double alc = 0.0);
    double getTauxAlcool() const override;
    std::unique_ptr<MenuItem> clone() const override;
    friend ostream& operator<<(ostream& os, const BoissonAlcoolisee& boisson);
    friend istream& operator>>(istream& is, BoissonAlcoolisee& boisson);
    void modifier(string n, double p, string d, double vol, double alc);
    void supprimer() override;
    static void ajouter(vector<unique_ptr<BoissonAlcoolisee>>& boissons, unique_ptr<BoissonAlcoolisee> boisson);
    void afficherDetails(ostream& os) const override;
};
#endif 
