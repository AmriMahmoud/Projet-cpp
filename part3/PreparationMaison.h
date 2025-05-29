#ifndef PREPARATIONMAISON_H
#define PREPARATIONMAISON_H
#include "ProduitCulinaire.h"
#include <fstream>
#include <iostream>

class PreparationMaison : public ProduitCulinaire {
protected:
    int tempsPreparation;
    string difficulte;
public:
    PreparationMaison(string n = "", double p = 0.0, string o = "", int tp = 0, string diff = "");
    PreparationMaison* clone() const override {
        return new PreparationMaison(*this); 
    }
    friend ostream& operator<<(ostream& os, const PreparationMaison& prep);
    friend istream& operator>>(istream& is, PreparationMaison& prep);
    void modifier(string n, double p, string o, int tp, string diff);
    void supprimer() override;
    static void ajouter(vector<PreparationMaison*>& preps, PreparationMaison* prep);
    void sauvegarderDansFichier(const string& nomFichier) const;
    static PreparationMaison* chargerDeFichier(const string& nomFichier);
    PreparationMaison operator+(int tempsSupplementaire) const;
    PreparationMaison operator-(int tempsReduit) const;

    double calculerPrixTTC() const override;
    string genererEtiquette() const override;
};
#endif 
