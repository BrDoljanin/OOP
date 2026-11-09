// vjezba 5, zadatak 1: napisite klasu volume iznad main.

#include <cassert>
#include <iostream>

// ovdje napisite klasu volume

class volume
{

	int vol;
	int temp;
	bool valid() const { return vol >= 0 && vol <= 100; }

public:
	volume(int l) : vol(granice(l)), temp(granice(l)) {}

	volume() : volume(50) {}

	static int granice(int l)
	{
		
		if (l < 0) { return 0; }
		if (l > 100) { return 100; }
		return l;
	
	}

	void up(int step = 10)
	{

		vol = vol + step;
		vol = granice(vol);
		assert(valid());

	}
	void down(int step = 10)
	{

		vol = vol - step;
		vol = granice(vol);
		assert(valid());

	}
	void mute()
	{
		temp = vol;
		vol = 0;
		assert(valid());

	}
	void unmute()
	{

		vol = temp;
		assert(valid());

	}

	int get() const
	{

		return vol;

	}
};


int main()
{

	volume v;

	std::cout << v.get() << '\n';
	v.up();
	v.up(60);
	std::cout << v.get() << '\n';
	v.mute();
	std::cout << v.get() << '\n';
	v.unmute();
	std::cout << v.get() << '\n';
	volume w(-20);
	w.down();
	std::cout << w.get() << '\n';
	return 0;
}

/*
ocekivani ispis:

	50
	100
	0
	100
	0
*/
