#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
#include "Level.h"
using namespace std;
class Player {
    string name;
    Level level;

public:
    Player(const string& ime);
    void print() const;      // ime i stanje levela u kojem je igrac
};
