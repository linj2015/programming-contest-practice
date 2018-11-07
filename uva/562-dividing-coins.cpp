#include <iostream>
#include <vector>
#include <algorithm>

// Practicing coding a DP solution bug-free
// I have read and understood https://discuss.codechef.com/questions/52911/uva-562-dividing-coins
// because in competition one person might write up a solution algorithm while
// another team member who is good at writing bug-free code implements it.

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int N = 0; N < n; N++)
	{
		int m;
		cin >> m;
		vector<int> v(m + 1, 0);
		vector<int> w(m + 1, 0);
		int W = 0;
		for (int j = 1; j <= m; j++)
		{
			cin >> v[j];
			W += v[j];
			w[j] = W;
		}

		int half = W / 2;
		int a = 0;
		vector<vector<int>> data(m + 1, vector<int>(half + 1, 0));
		for (int i = 1; i <= m; i++)
		{
			for (int w = 0; w <= half; w++)
			{
				if (v[i] > w)
				{
					data[i][w] = data[i - 1][w];
				}
				else
				{
					data[i][w] = max({ v[i] + data[i - 1][w - v[i]], data[i - 1][w] });
				}
				if (data[i][w] > a && data[i][w] <= half)
				{
					a = data[i][w];
				}
			}
		}
		int b = W - a;
		cout << abs(b - a) << endl;
	}

	return 0;
}
