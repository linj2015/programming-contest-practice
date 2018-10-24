#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <unordered_map>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	unordered_map<char, int> map = { pair<char, int>(' ', 0) };
	for (int i = 0; i < 26; i++)
	{
		map.emplace('A' + i, i + 1);
	}

	// read in dictionary
	set<string> dict;
	string word;
	while (word != "#")
	{
		cin >> word;
		dict.insert(word);
	}
	// read in encrypted text
	string encrypted;
	getline(cin, encrypted);
	if (encrypted.empty())
	{
		getline(cin, encrypted);
	}
	// find most matches
	int maxMatch = -1;
	int bestK = 0;
	for (int k = 0; k < 27; k++)
	{
		string str = encrypted;
		for (char& c : str)
		{
			c = map[c];
			c -= k;
			if (c < 0) c += 27;

			if (c == 0) c = ' ';
			else c += ('A' - 1);
		}

		stringstream ss(str);
		string w;
		int match = 0;
		while (ss >> w)
		{
			if (dict.find(w) != dict.end())
			{
				match++;
			}
		}

		if (match > maxMatch)
		{
			maxMatch = match;
			bestK = k;
		}
	}
	// decrypt
	for (char& c : encrypted)
	{
		c = map[c];
		c -= bestK;
		if (c < 0) c += 27;

		if (c == 0) c = ' ';
		else c += ('A' - 1);
	}
	// special output format
	string output = "";
	stringstream ss(encrypted);
	string w;
	while (ss >> w)
	{
		if (output.length() + 1 + w.length() > 60)
		{
			cout << output << endl;
			output.clear();
		}
		if (!output.empty())
		{
			output += " ";
		}
		output += w;
	}
	cout << output << endl;

	return 0;
}
