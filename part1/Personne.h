#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Personne {
protected:
    string nom;
    string prenom;
    string telephone;
public:
    Personne(string n = "", string p = "", string t = "");
    virtual ~Personne() = default;
    string getNom() const { return nom; }
    string getPrenom() const { return prenom; }
    string getTelephone() const { return telephone; }
    virtual string getRole() const = 0;
    void modifier(string n, string p, string t);
    void supprimer();
    static void ajouter(vector<shared_ptr<Personne>>& personnes, shared_ptr<Personne> personne);
    friend ostream& operator<<(ostream& os, const Personne& personne);
    friend istream& operator>>(istream& is, Personne& personne);
};
