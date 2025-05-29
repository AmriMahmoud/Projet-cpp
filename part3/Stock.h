#ifndef STOCK_H
#define STOCK_H
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include "ProduitCulinaire.h"
#include "LotProduction.h"
using namespace std;

class Stock {
    vector<ProduitCulinaire*> inventaireProduits;
    vector<LotProduction*> inventaireLots;
    map<string, int> seuilsAlerte;
    int seuilAlerte;
public:
    Stock(int seuil = 5);
    ~Stock();
    Stock& operator=(const Stock& other);
    friend ostream& operator<<(ostream& os, const Stock& stock);
    friend istream& operator>>(istream& is, Stock& stock);
    void ajouterProduit(ProduitCulinaire* produit);
    void modifierProduit(int index, ProduitCulinaire* nouveauProduit);
    void supprimerProduit(int index);
    void ajouterLot(LotProduction* lot);
    void modifierLot(int index, LotProduction* nouveauLot);
    void supprimerLot(int index);
    void definirSeuilAlerte(const string& nomProduit, int seuil);
    int getSeuilAlerte(const string& nomProduit) const;
    bool verifierDisponibilite(ProduitCulinaire* produit, int quantite);
    vector<pair<string, int>> faireInventaire() const;
    void passerCommandeFournisseur();
};
#endif
