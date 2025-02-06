#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>

using namespace std;


int main()
{
    notifikaattori no;

    seuraaja a("eka");
    seuraaja b("toka");
    seuraaja c("kolmas");

    no.lisaa(&a);
    no.lisaa(&b);
    no.lisaa(&c);

    no.tulosta();
    no.postita("Tama viesti 1");

    no.poista(&b);
    no.tulosta();

    no.postita("Tama viesti 2");


}

