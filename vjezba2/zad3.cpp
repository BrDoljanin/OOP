#include <iostream>
template<typename T>
inline bool ascending(T a, T b)
{
    return a > b;
}
template<typename T>
inline bool descending(T a, T b)
{
    return a < b;
}

template<typename T>
void my_sort(T arr[],int n, bool (*cmp)(T, T))
{
    T temp = 0;
    for(int i = 0; i < n - 1;i++)
    {

        for(int j = i + 1; j < n;j++)
        {

            if(cmp(arr[i], arr[j]))
            {

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 

            }

        }

    }

}

int main(void)
{

int konj[] = {6, 4, 5, 2, 3, 1};
int in = sizeof(konj) / sizeof(konj[0]);

my_sort(konj,in,ascending);

for(int i = 0; i < in; i++)
{

    std::cout << konj[i] << " ";

}
std::cout << '\n';


double pas[] = {6.2, 4.3, 5.7, 2.1, 3.3, 1.8};
int dn = sizeof(pas) / sizeof(pas[0]);
my_sort(pas,dn,ascending);


for(int i = 0; i < dn; i++)
{

    std::cout << pas[i] << " ";

}
std::cout << '\n';

char jarac[] = {'k', 'o', 'n', 'j'};
int cn = sizeof(jarac) / sizeof(jarac[0]);
my_sort(jarac,cn,descending);

for(int i = 0; i < cn; i++)
{

    std::cout << jarac[i] << " ";

}
std::cout << '\n';

}
// jer ascending i descending funkcije fiksno hvataju int vrijednosti te ga ne prevodi sa double vrijednosti