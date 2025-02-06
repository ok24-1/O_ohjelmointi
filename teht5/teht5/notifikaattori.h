#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include "seuraaja.h"

class notifikaattori
{
public:
    notifikaattori();
    void lisaa(seuraaja *);
    void poista(seuraaja *);
    void tulosta();
    void postita(string);
private:
    seuraaja* seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
