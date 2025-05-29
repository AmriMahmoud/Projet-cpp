#ifndef PRODUITCULINAIRE_H
#define PRODUITCULINAIRE_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class ProduitCulinaire {
protected:
    string nom;
    double prixHT;
    string origine;
public:
    ProduitCulinaire(string n = "", double p = 0.0, string o = "");
    virtual ~ProduitCulinaire() = default;
    virtual ProduitCulinaire* clone() const = 0;
    friend ostream& operator<<(ostream& os, const ProduitCulinaire& produit);
    friend istream& operator>>(istream& is, ProduitCulinaire& produit);
    virtual void modifier(string n, double p, string o);
    virtual void supprimer();
    static void ajouter(vector<ProduitCulinaire*>& produits, ProduitCulinaire* produit);
    virtual double calculerPrixTTC() const = 0;
    virtual string genererEtiquette() const = 0;
    string getNom() const;
    double getPrixHT() const;
    string getOrigine() const;
};
#endif 
