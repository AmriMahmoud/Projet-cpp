#include "Client.h"
using namespace std;

int Client::nextId = 0;

Client::Client(string n, string p, string t)
    : Personne(n, p, t), idClient(++nextId) {}

string Client::getRole() const {
    return "Client #" + to_string(idClient);
}

int Client::getId() const {
    return idClient;
}

void Client::modifier(string n, string p, string t) {
    Personne::modifier(n, p, t);
}

void Client::supprimer() {
    Personne::supprimer();
}
void Client::ajouter(vector<shared_ptr<Client>>& clients, shared_ptr<Client> client) {
    clients.push_back(client);
}

ostream& operator<<(ostream& os, const Client& client) {
    os << "Name: " << client.getNom() << " " << client.getPrenom()
       << ", Phone: " << client.getTelephone();
    return os;
}

istream& operator>>(istream& is, Client& client) {
    is >> static_cast<Personne&>(client);
    return is;
}
