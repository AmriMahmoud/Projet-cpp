#include "Conservation.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Conservation& conservation) {
    os << "Conservation: " << conservation.getTemperatureOptimal() << "°C, "
       << conservation.getDureeConservation() << "h, "
       << conservation.getInstructionsStockage();
    return os;
}

istream& operator>>(istream& is, Conservation& conservation) {
    return is;
}