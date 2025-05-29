#include "Menu.h"
#include <iostream>
using namespace std;

Menu& Menu::operator=(const Menu& other) {
    if (this != &other) {
        items.clear();
        prixParCategorie = other.prixParCategorie;

        for (const auto& item : other.items) {
            items.push_back(item->clone());
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const Menu& menu) {
    os << "===== MENU =====" << endl;
    for (const auto& item : menu.items) {
        os << *item << endl;
        os << "----------------" << endl;
    }
    return os;
}

istream& operator>>(istream& is, Menu& menu) {
    int numItems;
    cout << "Nombre d'items a ajouter: ";
    is >> numItems;
    return is;
}

void Menu::ajouterItem(unique_ptr<MenuItem> item) {
    items.push_back(move(item));
}

void Menu::modifier(int index, unique_ptr<MenuItem> newItem) {
    if (index < 0 || index >= items.size()) {
        return;
    }
    items[index] = move(newItem);
}

void Menu::supprimer(int index) {
    if (index < 0 || index >= items.size()) {
        return;
    }
    items.erase(items.begin() + index);
}

void Menu::afficherMenu() const {
    cout << *this;
}

void Menu::ajouterCategorie(const string& categorie, double prixMoyen) {
    prixParCategorie[categorie] = prixMoyen;
}

double Menu::getPrixMoyenCategorie(const string& categorie) const {
    auto it = prixParCategorie.find(categorie);
    if (it == prixParCategorie.end()) {
        throw DonneeInexistanteException("Categorie non trouvee", "prixParCategorie", categorie);
    }
    return it->second;
}

void Menu::afficherCategoriesPrix() const {
    cout << "Prix moyens par categorie:" << endl;
    for (const auto& pair : prixParCategorie) {
        cout << pair.first << ": " << pair.second << "TND" << endl;
    }
}

const vector<unique_ptr<MenuItem>>& Menu::getItems() const {
    return items;
}

vector<unique_ptr<MenuItem>>& Menu::getItems() {
    return items;
}

size_t Menu::getNombreItems() const {
    return items.size();
}

void Menu::modifierItem(size_t index, const string& nom, const string& description, double prix) {
    if (index >= items.size()) return;

    items[index]->setNom(nom);
    items[index]->setDescription(description);
    items[index]->setPrix(prix);
}

void Menu::supprimerItem(size_t index) {
    if (index >= items.size()) {
        items.erase(items.begin() + index);
        cout << "Item supprime.\n";
    } else {
        cout << "Index invalide.\n";
    }
}