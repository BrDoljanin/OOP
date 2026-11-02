#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool starts_with(const std::string& s, const std::string& prefix)
{

    return equal(prefix.begin(),prefix.end(),s.begin());

} 

bool ends_with(const std::string& s, const std::string& suffix)
{

    return equal(suffix.rbegin(),suffix.rend(),s.rbegin());

}
int main(void)
{
    vector<string> dat{"vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md", "vjezba04.h", "notes.txt", "vjezba03.cpp"};

    int count = 0;
    for(const auto& d : dat)
    {

        if(ends_with(d,".cpp"))
        {

            count++;

        }

    }
    cout << count << endl;

    dat.erase(remove_if(dat.begin(),dat.end(),
    [](const string& s)
    {

        return starts_with(s,"vjezba");  

    }), dat.end());

    for(size_t i = 0; i < dat.size(); i++)
    {

        cout << dat[i] << " ";

    }


}