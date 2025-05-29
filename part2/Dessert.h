#ifndef DESSERT_H
#define DESSERT_H
#include "Plat.h"
#include <fstream>
#include <iostream>

using namespace std;

class Dessert : public Plat {
    int calories;
public:
    Dessert(string n = "", double p = 0.0, string d = "", int tp = 0, int cal = 0);
    friend ostream& operator<<(ostream& os, const Dessert& dessert);
    friend istream& operator>>(istream& is, Dessert& dessert);
    void modifier(string n, double p, string d, int tp, int cal);
    void supprimer() override;
    static void ajouter(vector<unique_ptr<Dessert>>& desserts, unique_ptr<Dessert> dessert);
    void sauvegarderDansFichier(const string& nomFichier) const;
    static Dessert chargerDeFichier(const string& nomFichier);
    void afficherDetails(ostream& os) const override;
    Dessert operator+(int additionalCalories) const;
    Dessert operator-(int reducedCalories) const;
};
#endif 
