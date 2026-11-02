#include<iostream>
#include<vector>
#include<algorithm>

void input_vector(std::vector<int>& vect)
{
    int a = 982;
    while (true)
    {
        std::cout << "unesi broj: ";
        std::cin >> a;
        if(a == 0 )
        {
            break;
        }
        else
        {
            vect.push_back(a);
            std::cout << "size: " << vect.size() << '\n' << "capacity: " << vect.capacity() << '\n';
        }
    }
}


int main(void)
{

	std::vector<int> v;
    input_vector(v);

	int k;
    std::cout << "k: ";
    std::cin >> k;
	
	

	auto negat = [](int n)
	{

		return n < 0;
	
	};
	auto visekr = [k](int n)
	{
	
		return n % k == 0;
	
	};
	
	auto neg = std::count_if(v.begin(), v.end(), negat);
	
	auto kratnik = std::find_if(v.begin(), v.end(), visekr);

	auto min = std::min_element(v.begin(),v.end());

	auto max = std::max_element(v.begin(), v.end());

	std::cout << "negativni: " << neg << '\n';
	std::cout << "visekratnik broja " << k << ": " << *kratnik  << " na poziciji: " << kratnik - v.begin() << '\n';

	
	std::cout << "max: " << *max << " pozicija: " << max - v.begin() << '\n';

	std::cout << "min: " << *min << " pozicija: " <<  min - v.begin() << '\n';


	auto bez = std::remove_if(v.begin(), v.end(), visekr);
	

	
	v.erase(bez, v.end());
	
	for (int i : v)
	{

		std::cout << i << " ";

	}
	return 0;
}