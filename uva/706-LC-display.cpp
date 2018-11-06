#include <iostream>
#include <string>
#include <vector>

using namespace std;

int s, h, w, offset;
vector<string> vec;

// horizontal strokes h1, h2, h3
// vertical strokes l1, l2, r1, r2
void printh1()
{
	for (int i = 1; i < w - 2; i++)
	{
		vec[0][offset + i] = '-';
	}
}
void printh2()
{
	for (int i = 1; i < w - 2; i++)
	{
		vec[s + 1][offset + i] = '-';
	}
}
void printh3()
{
	for (int i = 1; i < w - 2; i++)
	{
		vec[h - 1][offset + i] = '-';
	}
}
void printl1()
{
	for (int i = 1; i < s + 1; i++)
	{
		vec[i][offset] = '|';
	}
}
void printl2()
{
	for (int i = s + 2; i < h - 1; i++)
	{
		vec[i][offset] = '|';
	}
}
void printr1()
{
	for (int i = 1; i < s + 1; i++)
	{
		vec[i][offset + w - 2] = '|';
	}
}
void printr2()
{
	for (int i = s + 2; i < h - 1; i++)
	{
		vec[i][offset + w - 2] = '|';
	}
}
// 1 7 
// 5 6 
// 3 9 8
// 4
// 2
// 0

int main()
{
	//freopen("display.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int num;
	string n;
	cin >> s >> n;
	while (s != 0)
	{
		w = s + 2 + 1;
		h = 2 * s + 3;
		num = n.length();
		vector<string> vec2(h, string(num * w, ' '));
		vec = vec2;
		for (int i = 0; i < num; i++)
		{
			offset = i * w;
			char d = n[i];
			if (d == '1' || d == '7')
			{
				printr1();
				printr2();
				if (d == '7') printh1();
			}
			else if (d == '5' || d == '6')
			{
				printh1();
				printh2();
				printh3();
				printl1();
				printr2();
				if (d == '6') printl2();
			}
			else if (d == '3' || d == '9' || d == '8')
			{
				printh1();
				printh2();
				printh3();
				printr1();
				printr2();
				if (d == '9' || d == '8')
				{
					printl1();
					if (d == '8') printl2();
				}
			}
			else if (d == '4')
			{
				printl1();
				printh2();
				printr1();
				printr2();
			}
			else if (d == '2')
			{
				printh1();
				printh2();
				printh3();
				printr1();
				printl2();
			}
			else
			{
				printh1();
				printh3();
				printl1();
				printl2();
				printr1();
				printr2();
			}
		}
		for (size_t i = 0; i < vec.size(); i++)
		{
			cout << vec[i].substr(0, vec[i].length() - 1) << endl;
		}
		cout << endl;
		cin >> s >> n;
	}

	return 0;
}
