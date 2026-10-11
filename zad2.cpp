#include<iostream>
#include<string>

int main()
{
    int god;
    size_t slovo;

    std::cout << "godina rodenja: ";
    std::cin >> god;
    std::cin.ignore();

    std::string ime;
    std::cout << "upisi puno ime: ";
    std::getline(std::cin,ime);

    size_t i = 0;
    for(char c : ime)
    {

        if(c == ' ')
        {

            slovo = i + 1;
            

        }
        std::cout << c;
        i++;
    }

    std::cout << "\n" << ime[0] << "."<< ime[slovo]<<"." << "\n";

    std::cout << "ove godine navrsava " << 2026 - god << " godina. \n";
    return 0;   

}