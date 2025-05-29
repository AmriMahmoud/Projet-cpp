#ifndef PIECEVIANDE_H
#define PIECEVIANDE_H
#include "ProduitCulinaire.h"
#include <iostream>

class PieceViande : public ProduitCulinaire {
    double poids;
    int ageMaturation;
    string gradeQualite;
public:
    PieceViande(string n = "", double p = 0.0, string o = "", double pd = 0.0, int am = 0, string gq = "");
    PieceViande* clone() const override {
        return new PieceViande(*this);
    }
    friend ostream& operator<<(ostream& os, const PieceViande& viande);
    friend istream& operator>>(istream& is, PieceViande& viande);
    void modifier(string n, double p, string o, double pd, int am, string gq);
    void supprimer() override;
    static void ajouter(vector<PieceViande*>& viandes, PieceViande* viande);

    double calculerPrixTTC() const override;
    string genererEtiquette() const override;
};
#endif 
