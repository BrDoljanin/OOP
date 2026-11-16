// Vjezba 6, zadatak 3: napisite klasu LogFile i funkciju log_songs iznad main.

#define _CRT_SECURE_NO_WARNINGS    // za Visual Studio: dopusta std::fopen
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// ovdje napisite klasu LogFile i funkciju log_songs
class LogFile 
{

    FILE* fp;


public:
    LogFile(const string ime_dat)
    {
    
        fp = std::fopen(ime_dat.c_str(), "a");

    
    }


    ~LogFile() 
    {
    
        if(fp)
        {
        
            fclose(fp);

        }
    }

    void write(const string& line) 
    {
    
        if(fp)
        {
        
            fputs(line.c_str(), fp);
            fputs("\n", fp);
        
        }
       
    
    }

    LogFile(const LogFile&) = delete;
    
};
int log_songs(const vector<string>& titles)
{

    LogFile file("played.log");
    int cc = 0;

    for (const auto& n : titles)
    {

        if (n == "STOP")
        {

            break;

        }
        file.write(n);
        cc++;
    }
    return cc;

}

int main()
{
    std::remove("played.log");     // brise datoteku iz prethodnog pokretanja
    int n = log_songs({"Superhero", "Sports", "STOP", "Matador"});
    std::cout << n << '\n';
    std::cout << log_songs({"One Rizla"}) << '\n';

    // ispis sadrzaja datoteke
    std::FILE* f = std::fopen("played.log", "r");
    char line[100];
    while (std::fgets(line, sizeof line, f))
        std::cout << line;
    std::fclose(f);
    return 0;
}

/*
Ocekivani ispis:

    2
    1
    Superhero
    Sports
    One Rizla
*/
