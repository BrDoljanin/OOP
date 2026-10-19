#include<iostream>
#include<string>
using namespace std;
    struct Student
    {

        string ime;
        string jmbag;
        int godina_studija;
        int ects;
        double prosjek;

    };

void filter_students(Student s[],int n, void(*action)(Student&), bool(*cond)(const Student&))
{

    for(int i = 0; i < n; i++)
    {

        if(cond(s[i]))
        {

            action(s[i]);

        }

    }

}
void ispis(Student& s)
{

    cout << s.ime << '\n' << s.jmbag << '\n' << s.godina_studija << '\n' << s.ects << '\n' << s.prosjek << '\n';

}
void povecaj(Student& s)
{

    s.godina_studija += 1;
    ispis(s);

}
int main(void)
{

    Student studenti[] = 
    {
        {"Ana Anic", "0036123456", 1, 30, 4.2},   // 1. godina, ima ECTS -> proći će uvjet za 1. zadatak
        {"Ivan Ivic", "0036654321", 1, 0, 2.5},    // 1. godina, ali nema ECTS (0 bodova)
        {"Marko Maric", "0036987654", 2, 55, 3.8},  // 2. godina, ima 55 ECTS (>45) i prosjek > 3.5
        {"Petra Petrovic", "0036111222", 3, 48, 4.7},// 3. godina, ima 48 ECTS (>45) i visok prosjek
        {"Luka Lukic", "0036999888", 1, 15, 3.1}    // 1. godina, ima 15 ECTS, prosjek manji od 3.5
    };
    int n = sizeof(studenti) / sizeof(studenti[0]);

    filter_students(studenti,n,ispis,[](const Student& s)
    {

        return (s.godina_studija == 1 && s.ects > 0);

    });
    cout << '\n';

   filter_students(studenti,n,ispis,[](const Student& s)
    {

        return (s.prosjek > 3.5);

    }); 
    cout << '\n';

    filter_students(studenti,n,povecaj,[](const Student& s)
    {

        return (s.ects > 45);

    });;
    
}   
