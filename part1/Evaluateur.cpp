
#include "Evaluateur.h"
using namespace std;

ostream& operator<<(ostream& os, const Evaluateur& evaluateur) {
    os << "Evaluateur";
    return os;
}

istream& operator>>(istream& is, Evaluateur& evaluateur) {
    return is;
}
