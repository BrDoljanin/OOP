// Vjezba 7, zadatak 4: napisite klasu Inventory iznad funkcije show.

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// ovdje napisite klasu Inventory

class Inventory
{

    vector<string> ime;
    size_t max;

public:
    Inventory(size_t kap = 0) : max(kap) 
    {
    
        ime.reserve(max);
    
    }
    Inventory& operator +=(const string& item)
    {
    
        if(ime.size() < max)
        {
            
            ime.push_back(item);
        
        }
        return *this;
    }
    string& operator[](size_t i)
    {
        
        return ime[i];
    
    }

    const string& operator[](size_t i) const
    {

        return ime[i];

    }
       
    size_t size() const
    {
    
        return ime.size();
        
    }
    explicit operator bool() const
    {
    
        return !ime.empty();

    }
};


void show(const Inventory& inv)
{
    if (!inv) {
        std::cout << "prazno\n";
        return;
    }
    for (std::size_t i = 0; i < inv.size(); ++i)
        std::cout << i << ": " << inv[i] << '\n';
}

int main()
{
    Inventory bag(3);
    show(bag);

    bag += "mac";
    bag += "stit";
    bag += "kljuc";
    bag += "baklja";          // ne stane
    show(bag);

    bag[0] = "zlatni mac";
    std::cout << bag[0] << ' ' << bag.size() << '\n';

    if (bag)
        std::cout << "ima predmeta\n";
    return 0;
}

/*
Ocekivani ispis:

    prazno
    0: mac
    1: stit
    2: kljuc
    zlatni mac 3
    ima predmeta
*/
