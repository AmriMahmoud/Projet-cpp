#ifndef ALLERGENES_H
#define ALLERGENES_H
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Allergenes {
protected:
    vector<string> listeAllergenes;
public:
    virtual ~Allergenes() = default;
    friend ostream& operator<<(ostream& os, const Allergenes& allergenes);
    friend istream& operator>>(istream& is, Allergenes& allergenes);
    virtual void modifierAllergenes(const vector<string>& nouvelleListe);
    virtual void supprimerAllergenes();
    virtual void ajouterAllergene(const string& allergene);
    virtual bool contientAllergene(const string& allergene) const;
    virtual vector<string> getListeComplete() const;
};

#endif
