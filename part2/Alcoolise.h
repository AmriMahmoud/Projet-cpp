#ifndef ALCOOLISE_H
#define ALCOOLISE_H
#include <iostream>

using namespace std;

class Alcoolise {
public:
    virtual double getTauxAlcool() const { return 0.0; }
    virtual ~Alcoolise() = default;
    friend ostream& operator<<(ostream& os, const Alcoolise& alcoolise);
    friend istream& operator>>(istream& is, Alcoolise& alcoolise);
    virtual void modifierTauxAlcool(double taux) {}
    virtual void supprimerTauxAlcool() {}
};
#endif 
