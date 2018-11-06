#include <iostream>
#include <string>
#include <vector>
#include <set> // std::queue caused TLE
#include <sstream>
#include <cstdio>

using namespace std;

int row, col;

vector<pair<int, int>> adj(int r, int c)
{
	vector<pair<int, int>> vec;
	if (r > 0)
	{
		vec.emplace_back(r - 1, c);
		if (c > 0) vec.emplace_back(r - 1, c - 1);
		if (c < col - 1) vec.emplace_back(r - 1, c + 1);
	}
	if (r < row - 1)
	{
		vec.emplace_back(r + 1, c);
		if (c > 0) vec.emplace_back(r + 1, c - 1);
		if (c < col - 1) vec.emplace_back(r + 1, c + 1);
	}
	if (c > 0) vec.emplace_back(r, c - 1);
	if (c < col - 1) vec.emplace_back(r, c + 1);
	return vec;
}

int main()
{
	//freopen("monkey.txt", "r", stdin); freopen("output.txt", "w", stdout);
	string line;
	getline(cin, line);
	while (!line.empty())
	{
		// read input
		vector<vector<char>> matrix;
		while (line != "%")
		{
			stringstream ss(line);
			char c;
			vector<char> row;
			while (ss >> c)
			{
				row.push_back(c);
			}			
			matrix.emplace_back(row);
			getline(cin, line);
			if (line.empty()) break;
		}
		// bfs
		row = matrix.size();
		col = matrix[0].size();
		vector<vector<int>> visit(row, vector<int>(col, 0));
		vector<size_t> maxWidth(col, 1);
		int id = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (visit[i][j] == 0)
				{
					id++;
					char tree = matrix[i][j];
					set<pair<int, int>> q;
					q.insert(make_pair(i, j));
					while (!q.empty())
					{
						auto it = q.begin();
						int r = it->first;
						int c = it->second;
						q.erase(it);
						if (matrix[r][c] == tree)
						{
							visit[r][c] = id;
							if (to_string(id).length() > maxWidth[c])
							{
								maxWidth[c] = to_string(id).length();
							}

							auto adjVec = adj(r, c);
							for (auto p : adjVec)
							{
								if (visit[p.first][p.second] == 0)
								{
									q.insert(p);
								}
							}
						}
					}
				}
			}
		}
		// output
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				string str = "%";
				str += to_string(maxWidth[j]);
				str += 'd';
				if (j != col - 1) str += ' ';
				fprintf(stdout, str.c_str(), visit[i][j]);
			}
			cout << endl;
		}
		cout << "%" << endl;
		getline(cin, line);
	}

	return 0;
}
/* remove rediect before submitting! */
