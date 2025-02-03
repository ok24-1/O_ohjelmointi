#include "asiakas.h"
#include <iostream>
#include <luottotili.h>

asiakas::asiakas(string nimi, double luottoRaja): nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja) {

}

string asiakas::getNimi()
{
    return nimi;
}

void asiakas::showSaldo()
{
    cout << "Balance of debit account: " << kayttotili.getBalance() << endl;
    cout << "Balance of credit account: " << luottotili.getBalance() << endl;
}

bool asiakas::talletus(double inDebit)
{
    return kayttotili.deposit(inDebit);
}

bool asiakas::nosto(double outDebit)
{
    return kayttotili.withdraw(outDebit);
}

bool asiakas::luotonMaksu(double inCredit)
{
    return luottotili.deposit(inCredit);
}

bool asiakas::luotonNosto(double outCredit)
{
     return luottotili.withdraw(outCredit);
}

bool asiakas::tiliSiirto(double toRecipient, asiakas & toClient)
{
    if (kayttotili.withdraw(toRecipient)){
            toClient.talletus(toRecipient);
        return 1;
}
    return 0;
    }

