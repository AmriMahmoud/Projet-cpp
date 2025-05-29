#ifndef SAUCEMAISON_H
#define SAUCEMAISON_H
#include "PreparationMaison.h"
#include "Conditionnement.h"
#include "Allergenes.h"
#include <iostream>

class SauceMaison : public PreparationMaison, public Conditionnement, public Allergenes {
    int niveauPiquant;
    string base;
public:
    SauceMaison(string n = "", double p = 0.0, string o = "", int tp = 0, string diff = "",
               int piquant = 0, string b = "", vector<string> allergenes = {});
    SauceMaison* clone() const override {
        return new SauceMaison(*this);
    }
    friend ostream& operator<<(ostream& os, const SauceMaison& sauce);
    friend istream& operator>>(istream& is, SauceMaison& sauce);
    void modifier(string n, double p, string o, int tp, string diff, int piquant, string b, vector<string> allergenes);
    void supprimer();
    static void ajouter(vector<SauceMaison*>& sauces, SauceMaison* sauce);
    bool getEstRecyclable() const override;
    string getMateriau() const override;
    double getImpactEcologique() const override;
    string genererEtiquette() const override;
    double calculerPrixTTC() const override;
};
#endif 
