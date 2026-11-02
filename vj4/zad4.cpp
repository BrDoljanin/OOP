#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct PasswordInfo
{

    int length;
    int digits;
    int uppercase;
    int special;

};

PasswordInfo analyze(const string& password)
{

    PasswordInfo pass;
    pass.length = password.length();

    pass.digits = count_if(password.begin(),password.end(),
    [](unsigned char c)
    {

        return isdigit(c);

    });

    pass.uppercase = count_if(password.begin(),password.end(),
    [](const char c)
    {

        return isupper(c);

    });

    pass.special = count_if(password.begin(),password.end(),
    [](const char c)
    {

        return ispunct(c);

    });

    return pass;
}

bool is_strong(const PasswordInfo& pass)
{

    return (pass.length >= 10 && pass.digits >= 1 && pass.uppercase >= 1 && pass.special >= 1);


}

int main(void)
{

    string pas = "pascina40!@";

    PasswordInfo p = analyze(pas);

    cout << pas << '\n' << p.length << '\n' << p.digits << '\n' << p.uppercase << '\n' << p.special << '\n' ;

    if (is_strong(p))
    {

        cout << "jaka";

    }
    else
    {

        cout << "slaba";

    }

}