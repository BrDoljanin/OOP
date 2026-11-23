// Vjezba 8, zadatak 2: napisite klase Enemy, Goblin, Bat, Ghost i Level iznad main.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// ovdje napisite klase
class Enemy 
{
protected:
	string name;
	int health;

public:

	Enemy(const string& s, int hp) : name(s), health(hp) {}

	virtual ~Enemy()
	{

		cout << name << " nestaje" << '\n';

	}

	virtual int take_damage(int d)
	{
	
		health -= d;
		if( health < 0 )
		{
		
			health = 0;
		
		}
		return health;
	
	}

	void print()
	{
	
		cout << name << " " << health << '\n';
	
	}

	bool dead()
	{
	
		return health == 0;
	
	}
};

class Goblin : public Enemy
{

public: Goblin() : Enemy("Goblin", 20) {}

};

class Bat : public Enemy
{

	int hits = 1;
public:

	Bat() : Enemy("Bat", 15) {}

	
		int take_damage(int d)
		{
		
			if (hits % 2 == 1)
			{
			
				health -= d;
				hits++;

				cout << name << " " << health;

			}
			else
			{
			
				cout << name << " izbjegne udarac \n";
				hits++;
			}

			return health;
		}
	

};
class Ghost : public Enemy
{
public:
	Ghost() : Enemy("Ghost", 30) {}

	int take_damage(int d) 
	{
	
		health = health - (d / 2);
	
		return health;
	}

};
class Level
{

	vector<Enemy*> enemies;

public:
	Level() = default;

	~Level()
	{
	
		for(Enemy* e : enemies)
		{
		
			delete e;
		
		}
	
	}

	void add(Enemy* e)
	{
	
		enemies.push_back(e);
	
	}

	void explode(int d)
	{
	
		for( Enemy* a : enemies)
		{
			
			a->take_damage(d);
		
		}
	
	}

	void print()
	{
	
		for(Enemy* a : enemies)
		{
		
			a->print();

		}
	
	}

	void remove_dead()
	{
		
		for (Enemy *a : enemies)
		{

			if (a->dead())
			{

				enemies.erase(enemies.begin(), enemies.begin());

			}
		}
	
	}
	
	size_t size() const
	{
	
		return enemies.size();

	}
};
int main()
{
    Level cave;
    cave.add(new Goblin);            // od sada je cave vlasnik neprijatelja
    cave.add(new Bat);
    cave.add(new Ghost);
    cave.add(new Goblin);
    std::cout << cave.size() << '\n';

    cave.explode(10);                // bomba pogodi sve neprijatelje
    cave.print();
    std::cout << "---\n";
    cave.explode(10);
    cave.print();
    std::cout << "---\n";
    cave.remove_dead();
    std::cout << cave.size() << '\n';
    std::cout << "--- kraj ---\n";
    return 0;                        // destruktor klase Level brise preostale neprijatelje
}

/*
Ocekivani ispis:

    4
    Goblin 10
    Bat 5
    Ghost 25
    Goblin 10
    ---
    Bat izbjegne udarac
    Goblin 0
    Bat 5
    Ghost 20
    Goblin 0
    ---
    Goblin nestaje
    Goblin nestaje
    2
    --- kraj ---
    Bat nestaje
    Ghost nestaje
*/
