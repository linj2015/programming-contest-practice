#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	// COMMENT THIS OUT WHEN SUBMITTING
	//freopen("roman.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	map<string, int> digraph(
		{
			{"IV", 4},
			{"IX", 9},
			{"XL", 40},
			{"XC", 90},
			{"CD", 400},
			{"CM", 900}
		});
	map<char, int> single(
		{
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		});
	map<int, string> convert({
			{1, "I"},
			{4, "IV"},
			{5, "V"},
			{9, "IX"},
			{10, "X"},
			{40, "XL"},
			{50, "L"},
			{90, "XC"},
			{100, "C"},
			{400, "CD"},
			{500, "D"},
			{900, "CM"},
			{1000, "M"}
		});

	string number;
	getline(cin, number);
	while (!cin.fail())
	{
		bool valid = true;

		int ans = 0;

		for (size_t i = 0; i < number.length(); i++)
		{
			char c = number[i];
			if (single.find(c) == single.end())
			{
				valid = false;
				break;
			}
			char next = '#';
			if (i < number.length() - 1)
			{
				next = number[i + 1];
			}

			// check if it's digraph
			string d = "";
			d += c;
			d += next;
			int num = 0;
			if (digraph.find(d) != digraph.end())
			{
				num = digraph[d];
				i++;
			}
			else
			{
				num = single[c];
			}
			ans += num;
		}

		if (ans >= 4000)
		{
			valid = false;
		}
		else
		{
			string str = "";
			int ans_copy = ans;
			for (auto it = convert.rbegin(); it != convert.rend(); ++it)
			{
				int x = it->first;
				while (ans_copy >= x)
				{
					ans_copy -= x;
					str += it->second;
				}
			}
			if (str != number)
			{
				valid = false;
			}
		}

		if (!valid)
		{
			cout << "This is not a valid number" << endl;
		}
		else
		{
			cout << to_string(ans) << endl;
		}
		getline(cin, number);
	}

	return 0;
}
