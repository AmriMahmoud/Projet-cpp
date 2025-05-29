#pragma once
#include "Reservation.h"
#include <memory>
#include <list>
#include <iostream>

class Service {
    list<shared_ptr<Reservation>> reservations; 

public:
    Service();
    void demarrerService();
    void terminerService();
    void ajouterReservation(shared_ptr<Reservation> res);
    Service& operator=(const Service& other);
    void modifier(const list<shared_ptr<Reservation>>& newReservations);
    void supprimer();
    static void ajouter(vector<shared_ptr<Service>>& services, shared_ptr<Service> service);
    friend ostream& operator<<(ostream& os, const Service& service);
    friend istream& operator>>(istream& is, Service& service);
    const list<shared_ptr<Reservation>>& getReservations() const ;
    list<shared_ptr<Reservation>>& getReservations() ;
    size_t getNombreReservations() const ;
    shared_ptr<Reservation> getReservation(size_t index) const ;
    void supprimerReservation(size_t index) ;
    void modifierReservation(size_t index, unsigned int nbPersonnes) ;
};
