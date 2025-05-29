#include "Service.h"
using namespace std;

Service::Service() {}

void Service::demarrerService() {
    cout << "Service demarre\n";
}

void Service::terminerService() {
    reservations.clear();
    cout << "Service termine\n";
}

void Service::ajouterReservation(shared_ptr<Reservation> res) {
    reservations.push_back(res);
}

Service& Service::operator=(const Service& other) {
    if (this != &other) {
        reservations.clear();
        for (const auto& res : other.reservations) {
            if (res) {
                reservations.push_back(res);
            }
        }
    }
    return *this;
}

void Service::modifier(const list<shared_ptr<Reservation>>& newReservations) {
    reservations = newReservations;
}

void Service::supprimer() {
    reservations.clear();
}

void Service::ajouter(vector<shared_ptr<Service>>& services, shared_ptr<Service> service) {
    services.push_back(service);
}

ostream& operator<<(ostream& os, const Service& service) {
    os << "Reservations:\n";
    for (const auto& reservation : service.getReservations()) {
        if (reservation) {
            os << *reservation << endl;
        }
    }
    return os;
}

istream& operator>>(istream& is, Service& service) {
    cout << "Ce service ne peut pas etre saisi directement." << endl;
    return is;
}
const list<shared_ptr<Reservation>>& Service::getReservations() const {
    return reservations;
}

list<shared_ptr<Reservation>>& Service::getReservations() {
    return reservations;
}

size_t Service::getNombreReservations() const {
    return reservations.size();
}

shared_ptr<Reservation> Service::getReservation(size_t index) const {
    if (index >= reservations.size()) return nullptr;

    auto it = reservations.begin();
    advance(it, index);
    return *it;
}

void Service::supprimerReservation(size_t index) {
    if (index >= reservations.size()) return;
    auto it = reservations.begin();
    advance(it, index);
    reservations.erase(it);
    cout << "Reservation supprimee.\n";
}

void Service::modifierReservation(size_t index, unsigned int nbPersonnes) {
    if (index >= reservations.size()) return;
    cout << "Nouveau nombre de personnes: ";
    cin >> nbPersonnes;
    auto it = reservations.begin();
    advance(it, index);
    (*it)->setNbPersonnes(nbPersonnes);
    cout << "Reservation modifiee.\n";
}
