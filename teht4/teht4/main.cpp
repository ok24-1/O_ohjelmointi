#include "asiakas.h"
#include <iostream>


using namespace std;

int main()
{
    asiakas client2("John", 500);

    string newCustomer;
    double creditLimit;
    cout << "Input the name of the new customer:"<<endl;
    cin >> newCustomer;
    cout << "Input the credit limit of the new customer:"<<endl;
    cin >> creditLimit;
    asiakas client1(newCustomer, creditLimit);

    int ammount;
    int choise;
    string recipient;
    do{
        cout << "Menu" << endl;
        cout << "1. Show balance" << endl;
        cout << "2. Deposit to debit account" << endl;
        cout << "3. Withdraw from debit account" << endl;
        cout << "4. Deposit to credit account" << endl;
        cout << "5. Withdraw from credit account" << endl;
        cout << "6. Transfer money to John" << endl;
        cout << "7. Peep John's balance" << endl;
        cout << "8. Exit" << endl;

        cin >> choise;

        switch (choise){
            case 1:
                client1.showSaldo();
                break;
            case 2:
                cout << "How much would you like to deposit to the debit account?" << endl;
                cin >> ammount;
                client1.talletus(ammount);
                break;
            case 3:
                cout << "How much would you like to withdraw from the debit account?" << endl;
                cin >> ammount;
                client1.nosto(ammount);
                break;
            case 4:
                cout << "How much would you like to deposit to the credit account?" << endl;
                cin >> ammount;
                client1.luotonMaksu(ammount);
                break;
            case 5:
                cout << "How much would you like to withdraw from the credit account?" << endl;
                cin >> ammount;
                client1.luotonNosto(ammount);
                break;
            case 6:
                cout << "Who much would you like to transfer?" << endl;
                cin >> ammount;
                client1.tiliSiirto(ammount, client2);
                break;
            case 7:
                cout << "John's balance: " << endl;
                client2.showSaldo();
                break;
            case 8:
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

    }

    while (choise !=8);

    return 0;
}
