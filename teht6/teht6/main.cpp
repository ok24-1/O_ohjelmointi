#include "student.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main () {
    int selection =0;
    vector<student>studentList;

    do {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"1. Add students"<<endl;
        cout<<"2. Print all students"<<endl;
        cout<<"3. Sort and print students according to Name"<<endl;
        cout<<"4. Sort and print students according to Age"<<endl;
        cout<<"5. Find and print student"<<endl;
        cin>>selection;

        string nimi;
        int ika;
        string haku;

        switch(selection){
        case 1:
            cout << "Nimi?" << endl;
            cin >> nimi;
            cout << "Ika?" << endl;
            cin >> ika;
            studentList.push_back(student(nimi,ika));
            break;


            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.

        case 2:
            for (auto student : studentList) {
                student.printStudenInfo();
            }
            break;

            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.

        case 3:
            sort(studentList.begin(), studentList.end(), [](const student &a, const student &b) {
                return a.getName() < b.getName();
            });

            for (auto student : studentList) {
                student.printStudenInfo();
            }
            break;

            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

        case 4:

            sort(studentList.begin(), studentList.end(), [](const student &a, const student &b) {
                return a.getAge() < b.getAge();
            });

            for (auto student : studentList) {
                student.printStudenInfo();
            }
            break;

            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

        case 5:{
            cout << "Hae nimella: ";
            cin >> haku;

            auto it = find_if(studentList.begin(), studentList.end(), [&haku](const student &student) {
                return student.getName() == haku;
            });

            if (it != studentList.end()) {
                it->printStudenInfo();
            } else {
                cout << "Ei loydy nimella " << haku << endl;
            }
            break;
        }
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.

        default:
            cout<< "Wrong selection, stopping..."<<endl;
            return 0;
            }

        }
    while(selection < 6);
    return 0;
}


