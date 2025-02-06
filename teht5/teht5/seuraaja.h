#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <string>
using namespace std;

class seuraaja
{
public:
    seuraaja(string);
    seuraaja* next = nullptr;
    string getNimi();
    void paivitys(string);
private:
    string nimi;
};

#endif // SEURAAJA_H
