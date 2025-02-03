#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"
#include <string>
using namespace std;

class luottotili : public pankkitili
{
public:
    luottotili(string &, double);
    bool deposit(double);
    bool withdraw(double);
protected:
    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
