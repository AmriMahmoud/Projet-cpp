
#pragma once
#include <iostream>
using namespace std;
class Evaluateur {
public:
    virtual ~Evaluateur() = default;
    virtual int evaluerQualite() = 0;
    friend ostream& operator<<(ostream& os, const Evaluateur& evaluateur);
    friend istream& operator>>(istream& is, Evaluateur& evaluateur);
};




