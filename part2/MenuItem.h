#ifndef MENUITEM_H
#define MENUITEM_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class MenuItem {
protected:
    string nom;
    double prix;
    string description;
public:
    MenuItem(string n = "", double p = 0.0, string d = "");
    virtual ~MenuItem() = default;

    virtual unique_ptr<MenuItem> clone() const = 0;

    friend ostream& operator<<(ostream& os, const MenuItem& item);
    friend istream& operator>>(istream& is, MenuItem& item);

    virtual void modifier(string n, double p, string d);
    virtual void supprimer();
    static void ajouter(vector<unique_ptr<MenuItem>>& items, unique_ptr<MenuItem> item);

    virtual void afficherDetails(ostream& os) const = 0;

    void setNom(const string& nouveauNom) {
        nom = nouveauNom;
    }

    void setDescription(const string& nouvelleDescription) {
        description = nouvelleDescription;
    }

    void setPrix(double nouveauPrix) {
        prix = nouveauPrix;
    }
};
#endif
