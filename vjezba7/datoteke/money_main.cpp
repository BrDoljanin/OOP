// Vjezba 7, zadatak 2: napisite klasu Money i operatore iznad main.
// Datoteka racun.txt mora biti u mapi iz koje se program pokrece.

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// ovdje napisite klasu Money i operatore
class Money
{

    int centi;

public:
    Money(int eur = 0, int cent = 0) : centi(eur * 100 + cent) {}

    int koliko() const
    {
        
        return centi;   
    
    }

    Money& operator+=(const Money& other)
    {

        centi += other.centi;
        return *this;

    }

    
};

Money operator+(Money a, const Money& b)
{
    a += b;
    return a;
}

bool operator<(const Money& a, const Money& b)
{
    return a.koliko() < b.koliko();
}

ostream& operator<< (ostream& os, const Money& m)
{

    int c = m.koliko();
    int eur = c / 100;
    int cent = c % 100;
    os << eur << '.';
    if(cent < 10)
    {
    
        os << '0' << cent << " EUR";
    
    }
    else 
    {
    
        os << cent << " EUR";
    
    }
    return os;

}

istream& operator>>(istream& is, Money& m)
{
    int euri = 0; 
    char sep = '\0';
    int cents = 0;

    if (!(is >> euri >> sep >> cents)) {
        return is;
    }

    if (sep != '.') {
        is.setstate(ios::failbit); 
        return is;
    }

    m = Money(euri, cents); // dodano: postavlja procitani iznos u objekt m
    return is;
}



int main()
{
    Money a(1, 5);
    Money b(0, 95);
    std::cout << a << " + " << b << " = " << a + b << '\n';

    std::ifstream in("racun.txt");
    if (!in) {
        std::cout << "Datoteka racun.txt ne postoji\n";
        return 1;
    }

    std::string item;
    Money price;
    Money total;
    Money max_price;
    std::string max_item;
    int count = 0;
    while (in >> item >> price) {
        total += price;
        if (max_price < price) {
            max_price = price;
            max_item = item;
        }
        ++count;
    }
    if (!in.eof())
        std::cout << "Neispravan zapis: " << item << '\n';

    std::cout << "Stavki: " << count << '\n';
    std::cout << "Ukupno: " << total << '\n';
    std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
    return 0;
}

/*
Ocekivani ispis:`

    1.05 EUR + 0.95 EUR = 2.00 EUR
    Neispravan zapis: Sok
    Stavki: 5
    Ukupno: 17.23 EUR
    Najskuplje: Kava 7.99 EUR
*/
