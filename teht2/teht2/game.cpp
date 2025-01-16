#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int n)
{
    maxNumber = n;
    cout << "PELIN RAKENTAJA: Aloitetaan peli suurimmalla numerolla "<< n << endl;
    Game::play();
}

Game::~Game()
{
    cout << "PELIN TUHOAJA: Peli tuhottu muistista" << endl;
}

void Game::play(){

    srand(time(0));
    int randomNumber = rand() % maxNumber + 1;

    cout << "Arvaa satunnainen luku valilta 1 - " << maxNumber <<endl;

    while(1){
        cin >> playerGuess;

        if (playerGuess > randomNumber){
            cout << "Lukusi on suurempi. Arvaa uusi luku:" << endl;
            numOfGuesses++;
        }
        if (playerGuess < randomNumber){
            cout << "Lukusi on pienempi. Arvaa uusi luku:" << endl;
            numOfGuesses++;
        }
        if (playerGuess == randomNumber){
            cout << "Luku " << playerGuess << " oli oikein" << endl;
            break;
        }
    }
    Game::printGameResult();
}

void Game::printGameResult()
{
    cout << "Arvauksia: " << playerGuess << endl;
}
