#include <iostream>

inline bool ascending(int a, int b)
{
    return a > b;
}

inline bool descending(int a, int b)
{
    return a < b;
}


void my_sort(int arr[],int n, bool (*cmp)(int, int))
{
    int temp = 0;
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

int arr[] = {6, 4, 5, 2, 3, 1};
int n = sizeof(arr) / sizeof(arr[0]);

for(int i = 0; i < n; i++)
{

    std::cout << arr[i] << " ";

}
std::cout << '\n';


my_sort(arr,n,ascending);

for(int i = 0; i < n; i++)
{

    std::cout << arr[i] << " ";

}
std::cout << '\n';

my_sort(arr,n,descending);

for(int i = 0; i < n; i++)
{

    std::cout << arr[i] << " ";

}
std::cout << '\n';

}