#include "pankkitili.h"
#include <iostream>
pankkitili::pankkitili(string &owner):omistaja(owner) {
    omistaja = owner;
    cout << "New debit account created for: "<< omistaja <<endl;
}

double pankkitili::getBalance()
{
    return saldo;
}

bool pankkitili::deposit(double moneyIn)
{
    if (moneyIn > 0 ){
        saldo = saldo + moneyIn;
        cout << moneyIn << " deposited succesfully" << endl;
        return 1;
    }
    if (moneyIn < 0){
        cout << "The value you are trying to deposit appears to be negative. Please change the value and try again." << endl;
        return 0;
    }
    else {
        cout << "Something unexpected happened. Please try again." << endl;
        return 0;
    }
}

bool pankkitili::withdraw(double moneyOut)
{
    if (moneyOut > 0 && moneyOut <= saldo){
        saldo = saldo - moneyOut;
        return 1;
    }
    if (moneyOut < 0){
        cout << "The value you are trying to withdraw appears to be negative. Please change the value and try again." << endl;
        return 0;
    }
    if (moneyOut > saldo){
        cout << "Not enough balance for this action" << endl;
        return 0;
}
    else {
        cout << "Something unexpected happened. Please try again." << endl;
        return 0;
    }
}


