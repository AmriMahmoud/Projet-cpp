#ifndef ENTREE_H
#define ENTREE_H
#include "Plat.h"
#include <iostream>
#include <vector>


using namespace std;

class Entree : public Plat {
    bool partageable;
public:
    Entree(string n = "", double p = 0.0, string d = "", int tp = 0, bool pgt = false);


    friend ostream& operator<<(ostream& os, const Entree& entree);
    friend istream& operator>>(istream& is, Entree& entree);

   
    void modifier(string n, double p, string d, int tp, bool pgt);
    void supprimer() override;
    static void ajouter(vector<unique_ptr<Entree>>& entrees, unique_ptr<Entree> entree);

   
    void afficherDetails(ostream& os) const override;
};
#endif 
