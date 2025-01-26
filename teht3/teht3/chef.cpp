#include "chef.h"


Chef::Chef(string name) : chefName(name) {

    cout << "Chef " << name << " created" << endl;
}

Chef::~Chef(){
    cout << "Chef "<< chefName <<" cleaned" << endl;
}

string Chef::getName(){
    return chefName;
}

int Chef::makeSalad(int ingredients){
    int portition = ingredients / 5;
    return portition;
}

int Chef::makeSoup(int ingredients){
    int portition = ingredients / 3;
    return portition;
}
