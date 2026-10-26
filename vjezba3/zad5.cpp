#include<iostream>
#include<string>

std::string with_separators(std::string digits)
{

    int j = 0;

    for(int i = digits.length() - 1; i >= 0; i--)
    {

        j++;
        
        if(j == 3 && i > 0)
        {

            digits.insert(i,1,'.');

            j = 0;

        }


    }
    return digits;
}
std::string without_separators(std::string text) {
    size_t a = text.find('.');
    while (a != std::string::npos) {

        text.erase(a, 1);

        a = text.find('.', a);

    }


    return text;
}


int main() {
    
    std::string broj = "1234567890";
    
    std::string tocke = with_separators(broj);
    std::cout << tocke << "\n";
    
    std::string nema = without_separators(tocke);
    std::cout << nema << "\n";

    return 0;
}
/* da smo umetali tocku od pocetka stringa, morali bi i nju uracunati jer se ona umece u indeks nakon  */