#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
using namespace std;

struct WordCount 
{

	string word;
	int count;

};

string clean(const string& rijec) 
{

	string s;
	for(char c: rijec)
	{
	
		if(isalpha(c))
		{
		
			s.push_back(tolower(c));

		}
	
	}
	return s;
}
int main()
{

	ifstream in("tekst.txt");

	map<string, int	> freq;

	string ric;

	while (in >> ric)
	{
	
		string r = clean(ric);
		if(r.empty())
		{
			
			continue;
			
		}
		++freq[r];
	}

	vector<WordCount> w;
	w.reserve(freq.size());
	for(const auto& i : freq)
	{
	
		w.push_back({ i.first,i.second });
	
	}

	sort(w.begin(), w.end(), [](const WordCount& a, const WordCount& b)
		{

			if (a.count != b.count)
			{

				return a.count > b.count;

			}
			return a.word < b.word;

		});

	cout << "razlicitih rijeci: " << freq.size() << '\n';
	cout << "alice: " << freq["alice"] << '\n';

	for(size_t i = 0; i < w.size() && i < 5; i++)
	{
	
		cout << w[i].word << ": " << w[i].count << '\n';
	
	}
}