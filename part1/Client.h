
#pragma once
#include "Personne.h"
#include <vector>
#include <memory>
#include <iostream>

class Client : public Personne {
    int idClient;
    static int nextId;
public:
    Client(string n = "", string p = "", string t = "");
    string getRole() const override;
    int getId() const;
    static void ajouter(vector<shared_ptr<Client>>& clients, shared_ptr<Client> client);
    void modifier(string n, string p, string t);
    void supprimer();
    friend ostream& operator<<(ostream& os, const Client& client);
    friend istream& operator>>(istream& is, Client& client);
};
