#ifndef DESSERTFRAIS_H
#define DESSERTFRAIS_H
#include "PreparationMaison.h"
#include "Conservation.h"
#include "Allergenes.h"
#include <fstream>
#include <iostream>

class DessertFrais : public PreparationMaison, public Conservation, public Allergenes {
    bool lactose;
    bool gluten;
public:
    DessertFrais(string n = "", double p = 0.0, string o = "", int tp = 0, string diff = "",
                bool lact = false, bool glut = false, vector<string> allergenes = {});
    DessertFrais* clone() const override {
        return new DessertFrais(*this); 
    }
    friend ostream& operator<<(ostream& os, const DessertFrais& dessert);
    friend istream& operator>>(istream& is, DessertFrais& dessert);
    void modifier(string n, double p, string o, int tp, string diff, bool lact, bool glut, vector<string> allergenes);
    void supprimer();
    static void ajouter(vector<DessertFrais*>& desserts, DessertFrais* dessert);
    void sauvegarderDansFichier(const string& nomFichier) const;
    static DessertFrais* chargerDeFichier(const string& nomFichier);
    int getTemperatureOptimal() const override;
    int getDureeConservation() const override;
    string getInstructionsStockage() const override;
    string genererEtiquette() const override;
    double calculerPrixTTC() const override;
};
#endif 
