#ifndef CONDITIONNEMENT_H
#define CONDITIONNEMENT_H
#include <string>
#include <iostream>

using namespace std;

class Conditionnement {
public:
    virtual ~Conditionnement() = default;
    friend ostream& operator<<(ostream& os, const Conditionnement& conditionnement);
    friend istream& operator>>(istream& is, Conditionnement& conditionnement);
    virtual void modifierConditionnement() {}
    virtual void supprimerConditionnement() {}
    virtual bool getEstRecyclable() const = 0;
    virtual string getMateriau() const = 0;
    virtual double getImpactEcologique() const = 0;
};

#endif
