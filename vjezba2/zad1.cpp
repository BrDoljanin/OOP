#include<pch.h>
#include<iostream>
#include<string>
#define MAX(a, b) ((a) > (b) ? (a) : (b));

inline int my_max(int a, int b)
{

	return (a > b) ? a : b;

}
template<typename T>
void max_template(T& a, T& b)
{

	std::cout << ((a > b) ? a : b )<< '\n';

}

int main()
{


	int a = MAX(3, 5);

	std::cout << a << '\n';

	int b = 2 * MAX(3, 5);

	std::cout << b << '\n';

	int c = MAX(3, 5) + 1;

	std::cout << c << '\n';

	int i = 3;

	int p = MAX(++i, 2)

	std::cout << p << '\n';

	p = my_max(++i, 2);

	std::cout << p << '\n';
	double j = 3.5, k = 2.0;
	max_template(j,k);

	const char* d = "abc";
	const char* e = "cde";
	max_template(d, e);

	std::string s1 = "KONJ";
	std::string s2 = "podrug";
	max_template(s1, s2);
}
