#include "LotProduction.h"

LotProduction::LotProduction(string date, int qte, string code)
    : dateProduction(date), quantite(qte), codeLot(code) {}

bool LotProduction::estPerime() const {
    return dateProduction < "2023-01-01"; 
}

string LotProduction::getInfosLot() const {
    return "Lot " + codeLot + " - " + dateProduction + " - " + to_string(quantite) + " unites";
}

int LotProduction::getQuantite() const { return quantite; }
void LotProduction::reduireQuantite(int qte) { quantite -= qte; }

ostream& operator<<(ostream& os, const LotProduction& lot) {
    os << "Lot " << lot.codeLot << " - Date: " << lot.dateProduction
       << " - Quantite: " << lot.quantite << " unites"
       << " - Statut: " << (lot.estPerime() ? "Perime" : "Valide");
    return os;
}

istream& operator>>(istream& is, LotProduction& lot) {
    cout << "Code du lot: ";
    is.ignore();
    getline(is, lot.codeLot);

    cout << "Date de production (YYYY-MM-DD): ";
    getline(is, lot.dateProduction);

    cout << "Quantite: ";
    is >> lot.quantite;

    return is;
}

void LotProduction::modifier(string date, int qte, string code) {
    dateProduction = date;
    quantite = qte;
    codeLot = code;
}

void LotProduction::supprimer() {
    dateProduction = "";
    quantite = 0;
    codeLot = "";
}

void LotProduction::ajouter(vector<LotProduction*>& lots, LotProduction* lot) {
    lots.push_back(lot);
}
