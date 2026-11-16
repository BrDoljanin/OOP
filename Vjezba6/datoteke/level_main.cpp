// Vjezba 6, zadatak 5: napisite klase Enemy i Level iznad main.

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// ovdje napisite klase Enemy i Level
class Enemy 
{

    string name;
    int x;
    int y;
    int health;

public:
    Enemy(string n, int posx, int posy) : name(n), x(posx), y(posy), health(100) {}

    string get_name() const { return name; }
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_health() const { return health; }

    bool is_alive() const 
    {
    
        return health > 0;
    
    }

    void move(int mx, int my)
    {
        
        x += mx;
        y += my;
    
    }
    void take_damage(int dmg)
    {
    
        health -= dmg;
        if(health < 0)
        {
            
            health = 0;
        
        }

    }
};

class Level 
{

    int rows;
    int cols;
    vector<Enemy> enemies;

public:
    Level(int r, int c) : rows(r), cols(c) {}

   

    bool add(Enemy e)
    {
    
        if(e.get_x() < 0 || e.get_x() >= cols || e.get_y() < 0 || e.get_y() >= rows)
        {
            
            return false;
        
        }
        enemies.push_back(e);
        return true;
    }
    void step(int dx, int dy)
    {
    
        for(auto& e: enemies)
        {
        
            int xx = e.get_x() + dx;
            int yy = e.get_y() + dy;
        
            if (xx >= 0 && xx < cols && yy >= 0 && yy < rows)
            {

                e.move(dx, dy);

            }

        }

    }
    void print() const 
    {
    
        for(const auto& e : enemies)
        {
        
            std::cout << e.get_name() << " (" << e.get_x() << ", " << e.get_y() << ") " << e.get_health() << '\n';
        
        }
    
    }
};
int main()
{
    Level cave(5, 10);
    cave.add(Enemy("Gnome", 1, 1));
    std::cout << cave.add(Enemy("Troll", 8, 3))
              << cave.add(Enemy("Bat", 12, 2)) << '\n';
    cave.step(1, 1);
    cave.print();
    cave.step(1, 1);
    cave.print();
    return 0;
}

/*
Ocekivani ispis:

    10
    Gnome (2, 2) 100
    Troll (9, 4) 100
    Gnome (3, 3) 100
    Troll (9, 4) 100
*/
