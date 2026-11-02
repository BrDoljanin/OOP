// Vjezba 5, zadatak 1: napisite klasu Volume iznad main.

#include <cassert>
#include <iostream>

// ovdje napisite klasu Volume

class Volume
{

	int vol;
	static int g;
	bool valid() const { return vol > 0 && vol < 100; }

public:


	Volume(int l)
	{

		if (l < 0)
		{

			l = 0;

		}
		if (l > 100)
		{

			l = 100;

		}


	}
	Volume(int l) : Volume() { vol = 50;  };
	Volume() = default;

	static int granice() { return g > 0 || g < 100; }
	int temp;

	void up (int step = 10)
	{
		
		vol = vol + step;

		if (!granice)
		{
		
			vol -= step;

		}
		assert(valid());

	}
	void down(int step = 10)
	{

		vol = vol - step;

		if (!granice)
		{

			vol += step;

		}
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

	int get()
	{
	
		return vol;

	}
};

int main()
{

	Volume v();

	std::cout << v.get() << '\n';
	v.up();
	v.up(60);
	std::cout << v.get() << '\n';
	v.mute();
	std::cout << v.get() << '\n';
	v.unmute();
	std::cout << v.get() << '\n';
	Volume w(-20);
	w.down();
	std::cout << w.get() << '\n';
	return 0;
}

/*
Ocekivani ispis:

	50
	100
	0
	100
	0
*/
