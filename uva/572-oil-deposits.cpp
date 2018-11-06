#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n;

vector<pair<int, int>> adj(int r, int c)
{
	vector<pair<int, int>> vec;
	if (r > 0)
	{
		vec.emplace_back(r - 1, c);
		if (c > 0) vec.emplace_back(r - 1, c - 1);
		if (c < n - 1) vec.emplace_back(r - 1, c + 1);
	}
	if (r < m - 1) 
	{
		vec.emplace_back(r + 1, c);
		if (c > 0) vec.emplace_back(r + 1, c - 1);
		if (c < n - 1) vec.emplace_back(r + 1, c + 1);
	}
	if (c > 0) vec.emplace_back(r, c - 1);
	if (c < n - 1) vec.emplace_back(r, c + 1);
	return vec;
}

int main()
{
	//freopen("oil.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> m >> n;
	cin.ignore();
	while (m != 0)
	{
		vector<string> pocket;
		string s;
		for (int i = 0; i < m; i++)
		{
			getline(cin, s);
			pocket.emplace_back(s);
		}
		vector<vector<bool>> visit(m, vector<bool>(n, false));
		queue<pair<int, int>> q;
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visit[i][j] == false && pocket[i][j] == '@')
				{
					count++;
					q.push(make_pair(i, j));
					while (!q.empty())
					{
						int r = q.front().first;
						int c = q.front().second;
						q.pop();
						if (visit[r][c] == false && pocket[r][c] == '@')
						{
							visit[r][c] = true;
							auto vec = adj(r, c);
							for (auto pair : vec)
							{
								q.push(pair);
							}
						}

					}
				}
			}
		}
		cout << count << endl;
		cin >> m >> n;
		cin.ignore();
	}

	return 0;
}
