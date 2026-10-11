#include <iostream>
#include <string>
int& find_max(int arr[], int n)
{

    int max, pos;
    for(int i = 0; i < n; i++)
    {

        if(i == 0)
        {

            max = arr[i];

        }
        else
        {

            if(arr[i] > max)
            {

                max = arr[i];
                pos = i;
            }

        }
        
        
    }
    return arr[pos];

}
int main()
{

    int numbers[] = {4, -7, 12, 0, 9, -3};
    size_t minjaj = 0;
    for (int i : numbers)
    {

        if(i < 0)
        {

            numbers[minjaj] = abs(i);

        }
        

        minjaj++;
    }

    find_max(numbers,sizeof(numbers) / sizeof(numbers[0])) = 0;
    for (int x : numbers) 
    {

        std::cout << x << " ";
        
    }

    return 0;
}