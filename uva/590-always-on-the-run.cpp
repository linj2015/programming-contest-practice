#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	int N, K;
	cin >> N;
	int scenario = 1;
	while (N != 0)
	{
		cin >> K;
		vector<vector<vector<int>>> cost(N + 1, vector<vector<int>>(N + 1, vector<int>()));
		vector<vector<int>> d(N + 1, vector<int>(N + 1, 0));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) continue;
				cin >> d[i][j];
				for (int k = 0; k < d[i][j]; k++)
				{
					int x;
					cin >> x;
					cost[i][j].push_back(x);
				}
			}
		}

		vector<vector<int>> data(K + 1, vector<int>(N + 1, -1));
		//vector<vector<int>> path(K + 1, vector<int>(N + 1, 0));
		// day 1 has to start from 1 - Paris
		// day k has to end at n - Atlantis
		// day 2-(k-1) can start from any
		data[0][1] = 0;
		for (int i = 1; i <= K; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				vector<int> v(N + 1, INT_MAX);
				for (int k = 1; k <= N; k++)
				{
					if (k == j) continue;
					int day = (i - 1) % d[k][j]; // day in schedule for the path k->j
					if (cost[k][j].at(day) != 0 && data[i - 1][k] != -1)
					{
						v[k] = cost[k][j].at(day) + data[i - 1][k];
					}
				}
				auto it = min_element(v.begin(), v.end());
				int col = distance(v.begin(), it);
				if (v[col] != INT_MAX)
				{
					data[i][j] = v[col];
					//path[i][j] = col;
				}
			}
		}
		cout << "Scenario #" << scenario++ << endl;
		if (data[K][N] == -1)
		{
			cout << "No flight possible." << endl;
		}
		else
		{
			cout << "The best flight costs " << data[K][N] << "." << endl;
		}
		cout << endl;

		cin >> N;
	}

	return 0;
}
