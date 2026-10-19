#include<iostream>
#include<vector>
using namespace std;
void input_vector(vector<int>& vect)
{
	int a = 982;
	while (true)
	{
		cout << "unesi broj: ";
		cin >> a;
		if(a == 0 )
		{
			break;
		}
		else
		{
			
			vect.push_back(a);
			cout << "size: " << vect.size() << '\n' << "capacity: " << vect.capacity() << '\n';
		
		}
		
		
	}

	
}
void print_vector(vector<int>& v)
{

	for (auto x = v.begin(); x != v.end(); x++)
	{

		cout << *x << " ";


	}
	cout << '\n';
}
int main(void)
{

	vector<int> v;
	vector<int> vr;
	input_vector(v);
	print_vector(v);

	vr.reserve(100);
	input_vector(vr);
	vr.shrink_to_fit();
	print_vector(vr);
	cout << "capacity: " << vr.capacity();
	
	return 0;
}