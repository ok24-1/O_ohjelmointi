#include <iostream>
#include <cstdlib>
#include <ctime>

int game(int);

using namespace std;

int main(){

    int maxnum;

    cout << "Syota pelin ylaraja lukuna." << endl;
    cin >> maxnum;
    cout << "Arvaa satunnainen luku valilta 1 - " << maxnum <<endl;
    int score = game(maxnum);
    cout <<"Arvauten maara:  "<< score + 1 << endl;
}

int game(int maxnum){

    srand(time(0));
    int randomNumber = rand() % maxnum + 1;

    int userinput;
    int userinputCounter;

    while(1){
        cin >> userinput;

        if (userinput > randomNumber){
            cout << "Lukusi on suurempi. Arvaa uusi luku:" << endl;
            userinputCounter++;
        }
        if (userinput < randomNumber){
            cout << "Lukusi on pienempi. Arvaa uusi luku:" << endl;
            userinputCounter++;
        }
        if (userinput == randomNumber){
            cout << "Lukusi on oikein." << endl;
            break;
        }
    }
    return userinputCounter;
}
