#include<iostream>

void my_transform(int arr[],int n,int (*f)(int))
{

    for(int i = 0;i < n;i++)
    {

        arr[i] = f(arr[i]);

    }

}
int twice(int a)
{

    return a*2;

}   
int main(void)
{

    int arr[] = {6, 4, 5, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    my_transform(arr,n,twice);
    for(int i = 0; i < n; i++)
    {

        std::cout << arr[i] << " ";

    }
    std::cout << std::endl;
    my_transform(arr,n,[](int a)
        {

            if(a % 2 == 0)
            {

                return a / 2;

            }
            else
            {

                return a * 2;

            }
        }
    )   ;
     for(int i = 0; i < n; i++)
    {

        std::cout << arr[i] << " ";

    }
    std::cout << std::endl;


    int suma = 0;
    int produkt = 1;

    auto broji = [&](int a)
    {

        suma += a;
        produkt *= a;

    };

     for(int i = 0; i < n; i++)
    {

        broji(arr[i]);


    }
    std::cout<< suma << " "<< produkt <<'\n';
    
    int prag = 4;
    int s = 0;

    auto ceska = [prag, &s](int a)
    {

        if(a > prag)
        {

            s += a;
 
        }

    };

    for(int i = 0; i < n; i++)
    {

        ceska(arr[i]);

    }
    
    std::cout << s <<'\n';

}
// ne moze se proslijediti lambda s kontekstom jer lambda s kontekstom je klasificirana kao objekt, a ne kao funkcija