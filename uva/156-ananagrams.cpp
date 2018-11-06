#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cstdio> // printf, scanf
#include <cctype>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	string word;
	cin >> word;
	map<string, bool> dict;
	while (word != "#")
	{
		dict.emplace(word, true);
		cin >> word;
	}

	for (auto it = dict.begin(); it != dict.end(); ++it)
	{
		string word1 = it->first;
		map<char, int> count;
		for (char c : word1)
		{
			if (count.find(tolower(c)) != count.end())
			{
				count[tolower(c)]++;
			}
			else
			{
				count.emplace(tolower(c), 1);
			}
		}

		for (auto it2 = it; it2 != dict.end(); ++it2 )
		{			
			string word2 = it2->first;
			map<char, int> count2 = count;
			if (it2 == it) continue;
			if (word1.length() != word2.length()) continue;
			for (size_t j = 0; j < word2.length(); j++)
			{
				char c = tolower(word2[j]);
				if (count2.find(c) != count2.end())
				{
					count2[c]--;
				}
			}

			bool match = true;
			for (auto p : count2)
			{
				if (p.second != 0)
				{
					match = false;
				}
			}

			if (match)
			{
				it->second = false;
				it2->second = false;
			}
		}
	}

	for (auto p : dict)
	{
		if (p.second)
			cout << p.first << endl;
	}

	return 0;
}
/* remove rediect before submitting! */
