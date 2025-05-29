#ifndef LOTPRODUCTION_H
#define LOTPRODUCTION_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class LotProduction {
    string dateProduction;
    int quantite;
    string codeLot;
public:
    LotProduction(string date = "", int qte = 0, string code = "");
    virtual ~LotProduction() = default;
    friend ostream& operator<<(ostream& os, const LotProduction& lot);
    friend istream& operator>>(istream& is, LotProduction& lot);
    void modifier(string date, int qte, string code);
    void supprimer();
    static void ajouter(vector<LotProduction*>& lots, LotProduction* lot);
    bool estPerime() const;
    string getInfosLot() const;
    int getQuantite() const;
    void reduireQuantite(int qte);
};
#endif 
