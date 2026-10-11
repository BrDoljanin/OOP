#include <iostream>
#include<string>


namespace geo
{

    const double pi = 3.14;

    double area (double r)
    {

        return r * r * pi;

    }
    double area(double a, double b)
    {

        return a * b;

    }
    double area(int a)
    {

        return a * a;

    }

}
void print_line(char c, int length)
{
    std::cout << "\n";
    for(int i = 0; i < length;i++)
    {

        std::cout << c;

    }
    std::cout << "\n";
}
int main()
{
    std::cout << geo::area(5);
    print_line('-',30);
    std::cout << geo::area(5.0);
    print_line('-',30);
    std::cout << geo::area(2,3);
    print_line('-',30);
    std::cout << geo::area('A');
    print_line('-',30);

}