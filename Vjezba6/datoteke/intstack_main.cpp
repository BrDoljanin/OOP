// Vjezba 6, zadatak 1: napisite klasu IntStack iznad main.

#include <iostream>
using namespace std;
class IntStack 
{

	int* niz;
	size_t br_elem;
	size_t kapacitet;

public:

	
	IntStack(size_t kap = 2) : niz(new int[kap]), br_elem(0),kapacitet(kap) {}

	~IntStack() 
	{
	
		delete[] niz;

	}

	IntStack(const IntStack& other) : niz(new int[other.kapacitet]), br_elem(other.br_elem), kapacitet(other.kapacitet) {
		for (std::size_t i = 0; i < br_elem; ++i)
			niz[i] = other.niz[i];
	}

	void push(int x)
	{
	
		if (br_elem == kapacitet)
		{
		
			size_t kapacitet2 = kapacitet * 2;
			int* novi_niz = new int[kapacitet2];
			for(size_t i = 0; i < kapacitet; i++)
			{
			
				novi_niz[i] = niz[i];

			
			}
			delete[] niz;
			niz = novi_niz;
			kapacitet = kapacitet2;
		
		}
		
		niz[br_elem++] = x;

	}

	void pop()
	{
	
		if(br_elem > 0)
		{
		
			--br_elem;
		
		}
	
	}

	

	bool empty()
	{
	
		return (br_elem == 0);
	
	}

	int top()
	{
		
		return	niz[br_elem - 1];

	}
	int size() 
	{
		
		return br_elem;
	
	}
	int capacity() 
	{
	
		return kapacitet;
	
	}

};

int main()
{
    IntStack s;
	for (int i = 1; i <= 5; ++i) {
		s.push(i * 10);
	}
	int a = 0 ;
    std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
    IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
    c.pop();
    c.push(99);
    std::cout << s.top() << ' ' << c.top() << '\n';
    while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
    std::cout << '\n';
    return 0;
}

/*
Ocekivani ispis:

    5 8 50
    50 99
    50 40 30 20 10
*/
