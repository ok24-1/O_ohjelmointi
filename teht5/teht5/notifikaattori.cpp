#include "notifikaattori.h"
#include <iostream>

notifikaattori::notifikaattori() : seuraajat(nullptr) {
    cout << "Notifikaattori luotu" << endl;
}

void notifikaattori::lisaa(seuraaja * seuraaja)
{
    cout << "Notifikaattori lisasi seuraajan " << seuraaja->getNimi() << endl;
    if (seuraajat == nullptr) {
        seuraajat = seuraaja;
    }
    else {
        seuraaja -> next = seuraajat;
        seuraajat = seuraaja;
    }
}

void notifikaattori::poista(seuraaja * seuraaja)
{
    cout << "Notifikaattori poisti seuraajan " << seuraaja->getNimi() << endl;
    if  (seuraajat == nullptr){
        return;
    }
    if (seuraajat == seuraaja){
        seuraajat = seuraajat->next;
    }
    else {
        seuraajat ->next = seuraaja ->next;
    }
}

void notifikaattori::tulosta()
{   seuraaja* i = seuraajat;
    cout << "Notifikaattorin seuraajat:" << endl;

    while (i) {
        cout << "Seuraaja "<< i->getNimi() << " valmiina" << endl;
        i = i->next;
    }
}

void notifikaattori::postita(string viesti)
{
    cout << "Notifikaattori postittaa viestin: "<< viesti << endl;

    seuraaja* i = seuraajat;

    while (i) {
        i->paivitys(viesti);
        i = i->next;
    }
}
