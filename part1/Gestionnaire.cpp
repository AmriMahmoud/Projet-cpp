#include "Gestionnaire.h"
#include<iostream>
using namespace std;

ostream& operator<<(ostream& os, const Gestionnaire& gestionnaire) {
    os << "Gestionnaire";
    return os;
}

istream& operator>>(istream& is, Gestionnaire& gestionnaire) {
    return is;
}