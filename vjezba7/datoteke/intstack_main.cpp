// Vjezba 7, zadatak 3: kopirajte klasu IntStack iz vjezbe 6 iznad main i dopunite je.

#include <iostream>
#include <utility>
using namespace std;
class IntStack
{
    int* niz;
    size_t br_elem;
    size_t kapacitet;

public:
    IntStack(size_t kap = 2)
        : niz(new int[kap]), br_elem(0), kapacitet(kap)
    {
    }

    ~IntStack()
    {
        delete[] niz;
    }

    IntStack(const IntStack& other)
        : niz(new int[other.kapacitet]), br_elem(other.br_elem), kapacitet(other.kapacitet)
    {
        cout << "copy konstruktor\n";
        for (size_t i = 0; i < br_elem; ++i) {
            niz[i] = other.niz[i];
        }
    }

    IntStack& operator=(const IntStack& other)
    {
        cout << "copy assignment\n";
        if (this == &other) {
            return *this;
        }

        int* novi_niz = new int[other.kapacitet];
        for (size_t i = 0; i < other.br_elem; ++i) {
            novi_niz[i] = other.niz[i];
        }

        delete[] niz;
        niz = novi_niz;
        br_elem = other.br_elem;
        kapacitet = other.kapacitet;
        return *this;
    }

    IntStack(IntStack&& other) : niz(other.niz), br_elem(other.br_elem), kapacitet(other.kapacitet)
    {
        cout << "move konstruktor\n";
        other.niz = nullptr;
        other.br_elem = 0;
        other.kapacitet = 0;
    }

    IntStack& operator=(IntStack&& other)
    {
        cout << "move assignment\n";
        if (this == &other) {
            return *this;
        }

        delete[] niz;
        niz = other.niz;
        br_elem = other.br_elem;
        kapacitet = other.kapacitet;

        other.niz = nullptr;
        other.br_elem = 0;
        other.kapacitet = 0;
        return *this;
    }

    void push(int x)
    {
        if (br_elem == kapacitet) {
            size_t kapacitet2 = kapacitet * 2;
            int* novi_niz = new int[kapacitet2];
            for (size_t i = 0; i < kapacitet; i++) {
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
        if (br_elem > 0) {
            --br_elem;
        }
    }

    bool empty() 
    {
        return (br_elem == 0);
    }

    int top() 
    {
        return niz[br_elem - 1];
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
    IntStack a;
    a.push(10);
    a.push(20);
    a.push(30);

    IntStack b = a;              // ispis: copy konstruktor
    b = a;                       // ispis: copy assignment
    IntStack c = move(a);   // ispis: move konstruktor
    b = std::move(c);            // ispis: move assignment

    std::cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    copy konstruktor
    copy assignment
    move konstruktor
    move assignment
    0 0 3 30
*/
