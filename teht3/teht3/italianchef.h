#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include  "chef.h"

class ItalianChef : public Chef {
public:
    ItalianChef(string name);
    ~ItalianChef();
    bool askSecret(string, int, int);
private:
    int makepizza(int, int);
    string password = "pizza";
    int flour;
    int water;

};
#endif // ITALIANCHEF_H
