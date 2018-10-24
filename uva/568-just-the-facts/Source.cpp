#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	const int size = 10001;
	/* Simple solution: Mod by 1 million seems to work */
	//vector<unsigned long long> fact(size, 1);
	//for (int i = 1; i < size; i++)
	//{
	//	// find last digit of itself
	//	int curr = i;
	//	while (curr % 10 == 0) curr /= 10;
	//	// find last 6 digits of the factorial
	//	unsigned long long f = curr * fact[i - 1];
	//	while (f % 10 == 0) f /= 10;
	//	i %= 1000000;
	//	fact[i] = f;
	//}

	/* Better solution: Use the special algorithm */
	vector<int> fact(size, 1);
	for (int i = 1; i < 10; i++)
	{
		fact[i] = i * fact[i - 1];
		while (fact[i] % 10 == 0) fact[i] /= 10;
		fact[i] %= 10;
	}
	for (int i = 10; i < size; i++)
	{
		int lastTwo = i % 100;
		int tens = (lastTwo / 10) % 10;
		if (tens % 2 != 0)
		{
			fact[i] = 4 * fact[int(floor(i / 5))] * fact[lastTwo % 10];
		}
		else
		{
			fact[i] = 6 * fact[int(floor(i / 5))] * fact[lastTwo % 10];
		}
	}

	int n;
	while (cin >> n)
	{
		string output = to_string(n) + " -> " + to_string(fact[n] % 10);
		cout << right << setw(10) << output << endl;
	}

	return 0;
}
