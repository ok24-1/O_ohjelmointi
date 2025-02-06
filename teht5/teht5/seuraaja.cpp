#include "seuraaja.h"
#include <iostream>

seuraaja::seuraaja(string nimi) : nimi(nimi) {
    cout << "Node " << nimi << " created" << endl;
}

string seuraaja::getNimi() {
    return nimi;
}

void seuraaja::paivitys(string viesti) {
    cout << "Seuraaja " << nimi << " sai viestin: " << viesti << endl;
}
