#include<iostream>
#include<array>
#include<algorithm>


constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours)
{

    double suma = 0.0;
    for(double a : hours)
    {

        suma += a;

    }
    return suma;

}
int best_day(const std::array<double, DAYS>& hours)
{

    int a = 0;
    for(int i = 0; i < DAYS; i++)
    {

        if(hours[i] > hours[a])
        {

            a = i;

        }

    }
    return a + 1;

}

int main(void)
{

    std::array<double, DAYS> tj;

    for (int i = 0; i < DAYS; i++) {
        std::cin >> tj[i];
    }

    std::cout << "broj sati: " << total(tj) << '\n';
    std::cout << "najvise ucenja: " << best_day(tj) << '\n';


    std::array<double, DAYS> tj2;

    tj2.fill(1.5);

    if(tj == tj2)
    {

        std::cout << "isti su \n";

    }
    else
    {

        std::cout << "razliciti su \n";
        
    }

    if(tj < tj2)
    {

        std::cout << "prvi je manji \n";

    }
    else
    {

        std::cout << "drugi je manji \n";

    }

    tj.swap(tj2);

    std::cout << "broj sati: " << total(tj) << '\n';
    std::cout << "najvise ucenja: " << best_day(tj) << '\n';
}
/* broj elemenata u std::array mora biti poznat tijekom compile-anja. std::vector samo mijenja pointer tijekom swap-a, a std::array mora prebaciti cijelu tablicu*/