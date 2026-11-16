// Vjezba 5: klasa Clip ne radi ispravno.
// Ispravite je tako da program ispise: Concrete (Shame): 180 s

#include <iostream>
#include <string>

class Clip {
    int start;
    int end;
    int length;
    std::string name;
    const int max_length;
public:
    Clip(const std::string& name, int s, int e)
        : start(s), end(e), length(end - start), max_length(600)
    {
        this->name = name;
    }
    void print() const {
        std::cout << name << ": " << length << " s\n";
    }
};

int main()
{
    Clip c("Concrete (Shame)", 10, 190);
    c.print();
    return 0;
}

// 1. const varijable moraju dobiti vrijednost pri nastanku
// 2. varijabla unutar funkcije se zove isto kao varijabla iz klase, this-> je pointer koji poziva varijablu name iz objekta kako bi ih mogli razlikovati
// 3. int start i int end moraju biti deklarirani prije int length kako bih ispravno radio kod
