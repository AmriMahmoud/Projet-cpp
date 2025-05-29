#include "Stock.h"

Stock::Stock(int seuil) : seuilAlerte(seuil) {}

Stock::~Stock() {
    for (auto p : inventaireProduits) delete p;
    for (auto l : inventaireLots) delete l;
}

Stock& Stock::operator=(const Stock& other) {
    if (this != &other) {
        for (auto p : inventaireProduits) delete p;
        for (auto l : inventaireLots) delete l;
        inventaireProduits.clear();
        inventaireLots.clear();
        seuilsAlerte = other.seuilsAlerte;
        seuilAlerte = other.seuilAlerte;
        for (auto p : other.inventaireProduits) {
            inventaireProduits.push_back(p->clone());
        }
        for (auto l : other.inventaireLots) {
            inventaireLots.push_back(new LotProduction(*l));
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const Stock& stock) {
    os << "=== Inventaire des Produits ===" << endl;
    for (const auto& produit : stock.inventaireProduits) {
        os << *produit << endl;
    }
    os << "=== Inventaire des Lots ===" << endl;
    for (const auto& lot : stock.inventaireLots) {
        os << *lot << endl;
    }
    os << "=== Seuils d'Alerte ===" << endl;
    for (const auto& pair : stock.seuilsAlerte) {
        os << pair.first << ": " << pair.second << " unites" << endl;
    }
    return os;
}

istream& operator>>(istream& is, Stock& stock) {
    int seuilGeneral;
    cout << "Seuil d'alerte general: ";
    is >> seuilGeneral;
    stock.seuilAlerte = seuilGeneral;
    int nbProduits;
    cout << "Nombre de produits a ajouter: ";
    is >> nbProduits;
    return is;
}

void Stock::ajouterProduit(ProduitCulinaire* produit) {
    inventaireProduits.push_back(produit);
}

void Stock::modifierProduit(int index, ProduitCulinaire* nouveauProduit) {
    if (index >= 0 && index < inventaireProduits.size()) {
        delete inventaireProduits[index];
        inventaireProduits[index] = nouveauProduit;
    }
}

void Stock::supprimerProduit(int index) {
    if (index >= 0 && index < inventaireProduits.size()) {
        delete inventaireProduits[index];
        inventaireProduits.erase(inventaireProduits.begin() + index);
    }
}

void Stock::ajouterLot(LotProduction* lot) {
    inventaireLots.push_back(lot);
}

void Stock::modifierLot(int index, LotProduction* nouveauLot) {
    if (index >= 0 && index < inventaireLots.size()) {
        delete inventaireLots[index];
        inventaireLots[index] = nouveauLot;
    }
}

void Stock::supprimerLot(int index) {
    if (index >= 0 && index < inventaireLots.size()) {
        delete inventaireLots[index];
        inventaireLots.erase(inventaireLots.begin() + index);
    }
}

void Stock::definirSeuilAlerte(const string& nomProduit, int seuil) {
    seuilsAlerte[nomProduit] = seuil;
}

int Stock::getSeuilAlerte(const string& nomProduit) const {
    auto it = seuilsAlerte.find(nomProduit);
    if (it != seuilsAlerte.end()) {
        return it->second;
    }
    return seuilAlerte;
}

bool Stock::verifierDisponibilite(ProduitCulinaire* produit, int quantite) {
    int total = 0;
    for (auto lot : inventaireLots) {
        if (!lot->estPerime()) {
            total += lot->getQuantite();
            if (total >= quantite) return true;
        }
    }
    return false;
}

vector<pair<string, int>> Stock::faireInventaire() const {
    vector<pair<string, int>> resultat;
    for (auto produit : inventaireProduits) {
        int total = 0;
        for (auto lot : inventaireLots) {
            if (!lot->estPerime()) {
                total += lot->getQuantite();
            }
        }
        resultat.emplace_back(produit->getNom(), total);
    }
    return resultat;
}

void Stock::passerCommandeFournisseur() {
    cout << "Commande passee pour les produits sous le seuil" << endl;
}
