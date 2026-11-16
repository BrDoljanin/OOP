#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
using namespace std;
class Weapon {
    string ime;

public:
    Weapon(const string& oruzje);
    string get_name() const;
};
