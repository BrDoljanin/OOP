#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Song {

    string title;
    string artist;
    int year;
    int plays;

};

void print_song(const Song& s) {

    cout << s.title << ", "
         << s.artist << ", "
         << s.year << ", "
         << s.plays << endl;
}

int main(void)
{

    vector<Song> pisme = 
    {

        {"Dreamers never sleep", "Jay Reeve", 2025, 380000},
        {"SLEEPLESS","Avi8", 2026, 150000},
        {"Fade Away","Avi8", 2024, 250000},
        {"Memories","Refuzion", 2025, 1300000}

    };

    sort(pisme.begin(), pisme.end(),[](const Song& a, const Song& b)
    {

        if (a.year != b.year) {
            return a.year < b.year;
        }
        return a.title < b.title;

    });

    // for (const auto& s : pisme) {
    //     print_song(s);
    // }
    // cout << endl;
    
    string izv;
    cout << "Unesi ime: ";
    getline(cin, izv);

    // int count = 0;
    // Song najstarija;
    // bool prva = false;

    // for (const auto& s : pisme) {
    //     if (s.artist == izv) {
    //         if (!prva) {
    //             najstarija = s;
    //             prva = true;
    //         }
    //         count++;
    //     }
    // }

    // if(prva)
    // {

    //     cout << "broj pisama: " << count << endl
    //     << "najstarija: ";
    //     print_song(najstarija);
    //     cout << endl;

    // }

    sort(pisme.begin(),pisme.end(),[](const Song& a, const Song& b)
    {

        return a.plays > b.plays;

    });

    print_song(pisme[0]);
}

