#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <vector>
#include "Enemy.h"
#include "Weapon.h"
using namespace std;

class Level {
    
    vector <Enemy> neprijatelji;
    vector <Weapon> oruzja;

public:
    Level();
    int br_nepr() const;
    int br_oruz() const;
};
