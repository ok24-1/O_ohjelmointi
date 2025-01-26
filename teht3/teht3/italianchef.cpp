#include "italianchef.h"

ItalianChef::ItalianChef(string name):Chef(name){
    cout << "ItalianChef " << name << " created" << endl;
}

ItalianChef::~ItalianChef(){
    cout << "ItalianChef "<< chefName <<" cleaned" << endl;
};

bool ItalianChef::askSecret(string userPassword, int flour, int water){
    if (userPassword != password){
        cout << "No pizza for you!" << endl;
        return false;
    }
    if (userPassword == password) {
        if (flour < 5 && water < 5){
            cout << "Not enough ingredients for a pizza" << endl;
            return false;
        }
    }
    int pizzasMade = makepizza(flour, water);
    cout << pizzasMade << " pizzas made"  << endl;
    return true;
}
int ItalianChef::makepizza(int flour, int water){
    cout << "Lets make a pizza with "<<flour<<" flour and "<<water<<" water" <<endl ;

    int flourMax, waterMax;
    flourMax = flour / 5;
    waterMax = water / 5;
    int pizzaMax = min(flourMax, waterMax);
    return pizzaMax;
}
