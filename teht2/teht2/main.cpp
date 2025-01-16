#include <game.h>
#include <iostream>

using namespace std;

int main()
{
    int maxnum;
    cout << "Syota suurin satunnainen numero:" << endl;
    cin >> maxnum;
    Game peli(maxnum);
    return 0;
}
