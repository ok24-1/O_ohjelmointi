#include "luottotili.h"
#include "pankkitili.h"
#include <iostream>
#include <cmath>

luottotili::luottotili(string& omistaja, double creditLimit) : pankkitili(omistaja), luottoRaja(creditLimit)
{
    luottoRaja = creditLimit;
    cout << "New credit account created for: "<< omistaja <<endl;
}



bool luottotili::deposit(double moneyIn)
{
    if (moneyIn > 0 && moneyIn + saldo <= 0 ){
        saldo = saldo + moneyIn;
        return 1;
    }
    if (moneyIn + saldo > 0){
        cout << "Your deposit value is too high. You can only deposit a maximum of " << abs(saldo - 0) << endl;
        return 0;
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




bool luottotili::withdraw(double moneyOut)
{
    if (moneyOut > 0 && saldo + luottoRaja >= moneyOut ){
        saldo = saldo - moneyOut;
        return 1;
    }
    if (moneyOut < 0){
        cout << "The value you are trying to withdraw appears to be negative. Please change the value and try again." << endl;
        return 0;
    }
    else {
        cout << "Something unexpected happened. Please try again. [DEBUG: Luottotili else]" << endl;
        return 0;
    }
}

