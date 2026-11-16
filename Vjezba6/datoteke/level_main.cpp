// Vjezba 6, zadatak 6: napisite klasu RecentlyPlayed iznad main.

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

// ovdje napisite klasu RecentlyPlayed
class RecentlyPlayed 
{

    string* dat;
    int kapacitet;
    int broj;
    int sljedeci;

public:
    RecentlyPlayed(int k) : kapacitet(k), broj(0), sljedeci(0)
    {

        assert(kapacitet > 0);
        dat = new string[kapacitet];
    }

    ~RecentlyPlayed() 
    {
    
        delete[] dat;
    
    }

    RecentlyPlayed(const RecentlyPlayed& a) : kapacitet(a.kapacitet), broj(a.broj), sljedeci(a.sljedeci)
    {

        dat = new string[kapacitet];
        for (int i = 0; i < kapacitet; ++i) 
        {

            dat[i] = a.dat[i];

        }

    }

    void play(const string& title)
    {
    
        dat[sljedeci] = title;
        sljedeci = (sljedeci + 1) % kapacitet;
        if(broj < kapacitet)
        {
        
            broj++;
        
        }
    
    }

    int size() const
    {
    
        return broj;
    
    }

    int capacity() const 
    {
    
        return kapacitet;
    
    }
    string get(int i) const 
    {
    
        int id = (sljedeci - 1 - i + kapacitet) % kapacitet;
        return dat[id];
    
    }
    void print() const
    {
    
        for(int i = 0; i < broj; i++)
        {
        
            cout << get(i);
            if(i < broj - 1)
            {
            
                cout << ", ";
            
            }
        
        }
        cout << '\n';
    
    }
};


int main()
{
    RecentlyPlayed recent(3);
    recent.play("Heroes");
    recent.play("Literary Mind");
    std::cout << recent.size() << ' ' << recent.capacity() << '\n';
    recent.play("Sports");
    recent.print();
    recent.play("Henry Don't Got Love");     // buffer je pun: prepisuje se najstarija
    recent.print();

    RecentlyPlayed copy = recent;             // copy konstruktor
    recent.play("Guided by Angels");
    recent.print();
    copy.print();
    std::cout << copy.get(0) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    2 3
    Sports, Literary Mind, Heroes
    Henry Don't Got Love, Sports, Literary Mind
    Guided by Angels, Henry Don't Got Love, Sports
    Henry Don't Got Love, Sports, Literary Mind
    Henry Don't Got Love
*/
