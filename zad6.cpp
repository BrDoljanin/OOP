#include<iostream>
#include<string>

struct Fraction
{

    int numerator;
    int denominator;


    int djelitelj(int a, int b)
    {
        int i;
        if(a > b)
        {
            i = b;
        }
        else
        {
            i = a;
        }

        while(i > 0)
        {
            if(a % i == 0 && b % i == 0)
            {

                return i;

            }
            i--;
          
        }
        return 1;
    }
    void reduce()
    {

        int djel = djelitelj(numerator,denominator);
        numerator /= djel;
        denominator /= djel;


    }
    double value()
    {

        return (numerator * 1.0) / denominator;

    }
    void print()
    {

        std::cout << numerator << "/" << denominator; 

    }

};
Fraction sum(const Fraction& a, const Fraction& b)
{

    Fraction rez;
    rez.numerator = ((a.numerator * b.denominator) + (b.numerator * a.denominator));
    rez.denominator = (a.denominator * b.denominator);

    rez.reduce();
    return rez;

}
int main()
{

    Fraction f1 = {2, 4};
    Fraction f2 = {5, 9};

    f1.print();
    std::cout << "\n";
    
    f1.reduce();
    f1.print();
    std::cout << "\n";

    Fraction zbroj = sum(f1,f2);
    zbroj.print();
    

}