#include<iostream>
#include<vector>
using namespace std;

void izvjestaj()
{

    int n;
    cout << "dani: ";
    cin >> n;

    vector<double> temperatura(n);
    for(int i = 0; i < n; i++)
    {

        cin >> temperatura[i];

    }
    vector<double> promjene;
    for(auto iter = temperatura.begin() + 1;iter != temperatura.end();iter++)
    {

        promjene.push_back(*iter - *(iter - 1));

    }    
    cout << "Promjene:";
    for (double a : promjene) {
        cout << " " << a;
    }
    cout << "\n";

    double kraj = temperatura.back();

    temperatura.resize(7,kraj);


    cout << "Izvjestaj:";
    for (double t : temperatura) {
       cout << " " << t;
    }
}
int main(void)
{

 izvjestaj();

}
/*std::vector<int> a(5) ima 5 elemenata, svi postavljeni na 0, a std::vector<int> b{5} ima jedan elemenet postavljen na 5*/