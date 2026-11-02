#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;



vector<string> split_words(const string& text) {
    vector<string> rici;
    size_t i = 0;
    
    while (i < text.length()) {
        
        while (i < text.length() && text[i] == ' ') {
            i++;
        }
        if (i >= text.length()) break;
        
        
        size_t j = text.find(' ', i);
        if (j == string::npos) {
            rici.push_back(text.substr(i));
            break;
        } else {
            
            rici.push_back(text.substr(i, j - i));
            i = j;
        }
    }
    return rici;
}

int main(void)
{
    vector<string> n;
    int nepoznate = 0;
    vector<string> rjecnik = 
    {"programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije",
    "jednostavan", "za", "pocetnike"};
    sort(rjecnik.begin(), rjecnik.end());


    string unos;
    cout << "unesi: ";
    getline(cin,unos);

    vector<string>rijeci = split_words(unos);

    for(string s : rijeci)
    {

        s.erase(remove_if(s.begin(),s.end(),
        [](char c)
        {

            return c == ',' || c == '.';

        }),s.end());

        for(char& c : s)
        {

            c = tolower(c);

        }

        bool trazi = binary_search(rjecnik.begin(),rjecnik.end(),s);
        
        if(!trazi)
        {

            nepoznate++;
            n.push_back(s);

        }
    }

    cout << "nepoznatih rijeci: " << nepoznate;
    for (const string& nr : n) {
        cout << " " << nr;
    }
    cout << endl;
}