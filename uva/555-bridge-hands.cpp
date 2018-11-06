#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Card
{
	char suite;
	char val;
	int suiteInt;
	int valInt;

	Card(char s, char v)
	{
		suite = s;
		if (s == 'C') suiteInt = 0;
		else if (s == 'D') suiteInt = 1;
		else if (s == 'S') suiteInt = 2;
		else suiteInt = 3;

		val = v;
		if (v == 'T') valInt = 10;
		else if (v == 'J') valInt = 11;
		else if (v == 'Q') valInt = 12;
		else if (v == 'K') valInt = 13;
		else if (v == 'A') valInt = 14;
		else valInt = val - '0';
	}
};

char next(char a)
{
	if (a == 'S') return 'W';
	if (a == 'W') return 'N';
	if (a == 'N') return 'E';
	if (a == 'E') return 'S';
	return '*';
}

int main()
{
	//freopen("bridge.txt", "r", stdin); freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	while (s != "#")
	{
		unordered_map<char, vector<Card>> m;
		m.emplace('S', vector<Card>());
		m.emplace('W', vector<Card>());
		m.emplace('N', vector<Card>());
		m.emplace('E', vector<Card>());

		char d = s[0];
		string deck = "";
		cin >> s;
		deck += s;
		cin >> s;
		deck += s;
		
		for (size_t i = 0; i < deck.length() - 1; i += 2)
		{
			d = next(d);
			m[d].emplace_back(Card(deck[i], deck[i + 1]));
		}

		d = 'S';
		for (size_t j = 0; j < m.size(); j++)
		{			
			sort(m[d].begin(), m[d].end(), [](const Card& a, const Card& b) {
				if (a.suite != b.suite) return (a.suiteInt < b.suiteInt);
				else return (a.valInt < b.valInt);
			});
			cout << d << ':';
			for (const Card& card : m[d])
			{
				cout << ' ' << card.suite << card.val;
			}
			cout << endl;
			d = next(d);
		}
		cin.ignore();
		getline(cin, s);
	}

	return 0;
}
