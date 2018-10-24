#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
	// generate list of prime numbers (Sieve of Eratosthenes)
	const int SIZE = 1000001;
	vector<bool> vec(SIZE, true);
	// 1 is not a prime number
	vec[0] = false;
	vec[1] = false;
	int p = 2;
	while (p < SIZE)
	{
		// find the next prime number
		while (p < SIZE && vec[p] == false)
		{
			p++;
		}
		// remove its multiples in the list
		int m = p + p;
		while (m < SIZE)
		{
			vec[m] = false;
			m += p;
		}
		p++;
	}

	set<int> prime;
	for (int i = 3; i < SIZE; i++)
	{
		if (vec[i] == true)
		{
			prime.insert(i);
		}
	}

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	while (n != 0)
	{
		for (auto it = prime.begin(); it != prime.end(); it++)
		{
			int a = *it;
			int b = n - a;
			if (prime.find(b) != prime.end())
			{
				cout << n << " = " << a << " + " << b << endl;
				break;
			}
		}
		cin >> n;
	}

	return 0;
}
