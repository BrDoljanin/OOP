#include <iostream>

double add(double a, double b)
{

    return a + b;

}
double subtract(double a, double b)
{

    return a - b;

}
double multiply(double a, double b)
{

    return a * b;

}
double divide(double a, double b)
{

    return a / b;

}

int main(void)
{

    double (*fp[4])(double, double) = {add, subtract,multiply,divide};
    
    double a,b;
    int red;

    std::cin >> a;
    std::cout << '\n';
    std::cin >> b;
    std::cout << '\n';
    std::cin >> red;
    std::cout << '\n';

    double rez = fp[red](a,b);
    if(red == 3 && b == 0)
    {

        std::cout << "kakocu sa nulon dijelit reci ti meni";

    }
    else
    {

    std::cout << rez;

    }

}