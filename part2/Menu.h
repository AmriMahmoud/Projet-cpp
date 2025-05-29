#ifndef MENU_H
#define MENU_H
#include <vector>
#include <map>
#include <memory>
#include "MenuItem.h"
#include "DonneeInexistanteException.h"
#include <iostream>
#include <string>

using namespace std;

class Menu {
    vector<unique_ptr<MenuItem>> items;
    map<string, double> prixParCategorie;
public:
    Menu() = default;

    Menu& operator=(const Menu& other);

    friend ostream& operator<<(ostream& os, const Menu& menu);
    friend istream& operator>>(istream& is, Menu& menu);

    void ajouterItem(unique_ptr<MenuItem> item);
    void modifier(int index, unique_ptr<MenuItem> newItem);
    void supprimer(int index);
    void afficherMenu() const;

    void ajouterCategorie(const string& categorie, double prixMoyen);
    double getPrixMoyenCategorie(const string& categorie) const;
    void afficherCategoriesPrix() const;

    const vector<unique_ptr<MenuItem>>& getItems() const;
    vector<unique_ptr<MenuItem>>& getItems();
    size_t getNombreItems() const;
    void modifierItem(size_t index, const string& nom, const string& description, double prix);
    void supprimerItem(size_t index);
};
#endif
