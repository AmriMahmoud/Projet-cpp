#pragma once
#include <iostream>
using namespace std;
class Gestionnaire {
public:
    virtual ~Gestionnaire() = default;
    virtual void gererSysteme() = 0;
    friend ostream& operator<<(ostream& os, const Gestionnaire& gestionnaire);
    friend istream& operator>>(istream& is, Gestionnaire& gestionnaire);
};
