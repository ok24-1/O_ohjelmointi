#include "chef.h"
#include "italianchef.h"
using namespace std;


int main()
{
    //general chef for salads and soups
    string genChef;
    cout << "Insert the chef's name?" << endl;
    cin >> genChef;
    Chef aChef(genChef);

    //salad
    int forSalad, forSoup;
    cout << "How many ingredients for salad?" << endl;
    cin >> forSalad;
    int salad = aChef.makeSalad(forSalad);
    cout << salad << " portition with " << forSalad << " ingredients" << endl;

    //soup
    cout << "How many ingredients for soup?" << endl;
    cin >> forSoup;
    int soup = aChef.makeSoup(forSoup);
    cout << soup << " portition with " << forSoup << " ingredients" << endl;

    //italian chef for pizza
    cout << "Insert the italian chef's name?" << endl;
    cin >> genChef;

    ItalianChef bChef(genChef);

    //pizza and magic word
    string password;
    int flour, water;
    cout << "How much flour for pizzas?" << endl;
    cin >> flour;
    cout << "How much water for pizzas?" << endl;
    cin >> water;
    cout << "Whats the magic word?" << endl;
    cin >> password;

    if (bChef.askSecret(password, flour, water)){
        cout << "Pizza served!" << endl;
    }
    else {
        cout << "Pizza not made!" << endl;
    }


    return 0;
}
