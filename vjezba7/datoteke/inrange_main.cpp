// Vjezba 7, zadatak 5: kopirajte Vec2 iz zadatka 1 i napisite klasu InRange.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// ovdje kopirajte Vec2 i operatore iz zadatka 1
// Vjezba 7, zadatak 1: napisite strukturu Vec2 i operatore iznad main.


#include <iostream>
using namespace std;

struct Vec2
{
    int x;
    int y;

    Vec2& operator+=(const Vec2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }
};

Vec2 operator+(Vec2 a, const Vec2& b)
{
    a += b;
    return a;
}

Vec2 operator-(Vec2 a, const Vec2& b)
{
    a -= b;
    return a;
}

Vec2 operator*(Vec2 v, int puta)
{
    v.x *= puta;
    v.y *= puta;
    return v;
}

Vec2 operator*(int scalar, Vec2 v)
{
    return v * scalar;
}

bool operator==(const Vec2& a, const Vec2& b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vec2& a, const Vec2& b)
{
    return !(a == b);
}

ostream& operator<<(ostream& os, const Vec2& v)
{
    return os << '(' << v.x << ", " << v.y << ')';
}


// ovdje napisite struct Enemy
struct Enemy 
{

    string name;
    Vec2 pos;

};

// ovdje napisite klasu InRange

class InRange 
{

    Vec2 sredina;
    int domet;

public:

    InRange(Vec2 s, int d) : sredina(s), domet(d) {}

    bool operator()(const Enemy& enemy)
    {
        
        Vec2 r = enemy.pos - sredina;
        return r.x * r.x + r.y * r.y <= domet * domet;

    }
};
int main()
{
    std::vector<Enemy> enemies = {
        {"Goblin", {2, 2}}, {"Troll", {6, 1}}, {"Bat", {3, 5}},
        {"Ghost", {0, 0}}, {"Slime", {7, 7}}
    };
    Vec2 player{ 3, 3 };

    InRange near(player, 2);                                           // konstruktor, 2 je domet
    std::cout << near(enemies[0]) << ' ' << near(enemies[1]) << '\n';  // operator()

    /* ovdje pozovite count_if s funkcijskim objektom */
    cout << count_if(enemies.begin(), enemies.end(), near) << '\n';
    int range = 2;

    /* ovdje pozovite count_if s lambdom */
    cout << count_if(enemies.begin(), enemies.end(), [&player, range](const Enemy& e) 
        {
        
            Vec2 r = e.pos - player;
            return r.x * r.x + r.y * r.y <= range * range;
        
        }) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    1 0
    2
    2
*/
