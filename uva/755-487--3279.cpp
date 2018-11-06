#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	//freopen("phone.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	map<char, char> convert;
	char c = 'A';
	char p = '2';
	for (int i = 2; i < 10; i++)
	{
		convert.emplace(c++, p);
		if (c == 'Q') c++;
		convert.emplace(c++, p);
		convert.emplace(c++, p++);
	}

	int D;
	cin >> D;
	cin.ignore();
	string dummy;
	for (int i = 0; i < D; i++)
	{
		getline(cin, dummy);
		int N;
		cin >> N;
		cin.ignore();
		map<string, int> dir;
		for (int j = 0; j < N; j++)
		{
			string str;
			getline(cin, str);
			string str2 = "";
			for (size_t k = 0; k < str.length(); k++)
			{
				if (convert.find(str[k]) != convert.end())
				{
					str2 += convert[str[k]];
				}
				else if (str[k] != '-')
				{
					str2 += str[k];
				}
			}
			if (dir.find(str2) != dir.end())
			{
				dir[str2]++;
			}
			else
			{
				dir.emplace(str2, 1);
			}
		}
		bool print = false;
		for (auto pair : dir)
		{
			if (pair.second != 1)
			{
				print = true;
				string phone = pair.first;
				cout << phone.substr(0, 3) << "-" << phone.substr(3, 6) << " " << to_string(pair.second) << endl;
			}
		}
		if (!print)
		{
			cout << "No duplicates." << endl;
		}
		if (i != D - 1) cout << endl;
	}

	return 0;
}
