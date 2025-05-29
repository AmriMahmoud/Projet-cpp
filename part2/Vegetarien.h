#ifndef VEGETARIEN_H
#define VEGETARIEN_H
#include <iostream>

using namespace std;

class Vegetarien {
public:
    virtual bool estVegetarien() const { return false; }
    virtual ~Vegetarien() = default;

    friend ostream& operator<<(ostream& os, const Vegetarien& vegetarien);
    friend istream& operator>>(istream& is, Vegetarien& vegetarien);

    virtual void modifierVegetarien(bool estVeg) {}
    virtual void supprimerVegetarien() {}
};

#endif
