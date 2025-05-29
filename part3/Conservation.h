#ifndef CONSERVATION_H
#define CONSERVATION_H
#include <string>
#include <iostream>

using namespace std;

class Conservation {
public:
    virtual ~Conservation() = default;
    friend ostream& operator<<(ostream& os, const Conservation& conservation);
    friend istream& operator>>(istream& is, Conservation& conservation);
    virtual void modifierConservation() {}
    virtual void supprimerConservation() {}
    virtual int getTemperatureOptimal() const = 0;
    virtual int getDureeConservation() const = 0;
    virtual string getInstructionsStockage() const = 0;
};

#endif
