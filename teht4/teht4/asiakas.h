#ifndef ASIAKAS_H
#define ASIAKAS_H
#include "pankkitili.h"
#include "luottotili.h"
#include <string>
using namespace std;

class asiakas {
public:
    asiakas(string,double);
    string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tiliSiirto (double, asiakas&);
private:
    string nimi;
    pankkitili kayttotili;
    luottotili luottotili;
};

#endif // ASIAKAS_H
