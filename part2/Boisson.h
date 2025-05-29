#ifndef BOISSON_H
#define BOISSON_H
#include "MenuItem.h"
#include <iostream>
#include <memory>


using namespace std;

class Boisson : public MenuItem {
protected:
    double volume;
public:
    Boisson(string n = "", double p = 0.0, string d = "", double vol = 0.0);
    friend ostream& operator<<(ostream& os, const Boisson& boisson);
    friend istream& operator>>(istream& is, Boisson& boisson);
    void modifier(string n, double p, string d, double vol);
    void supprimer() override;
    static void ajouter(vector<unique_ptr<Boisson>>& boissons, unique_ptr<Boisson> boisson);
    void afficherDetails(ostream& os) const override;
};
#endif 
