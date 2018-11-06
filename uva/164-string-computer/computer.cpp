#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>

using namespace std;

struct Command
{
	char dir;
	char c;
	int pos;
};

int main()
{
	//freopen("computer.txt", "r", stdin); freopen("output.txt", "w", stdout);
	string input, target;
	cin >> input;
	vector<char> ops = { 'I', 'D', 'C' };
	while (input != "#")
	{
		cin >> target;
		string a = target;
		string b = input;
		vector<vector<int>> opt(a.length() + 1, vector<int>(b.length() + 1, 0));
		vector<vector<char>> dir(a.length() + 1, vector<char>(b.length() + 1, 0));
		for (size_t i = 1; i <= a.length(); i++)
		{
			opt[i][0] = i;
			dir[i][0] = 'I';
		}
		for (size_t j = 1; j <= b.length(); j++)
		{
			opt[0][j] = j;
			dir[0][j] = 'D';
		}
		for (size_t i = 1; i <= a.length(); i++)
		{
			for (size_t j = 1; j <= b.length(); j++)
			{
				vector<int> v = { opt[i - 1][j] + 1,
					opt[i][j - 1] + 1,
					opt[i - 1][j - 1] + ((a[i-1] == b[j-1]) ? 0 : 1) };
				auto result = min_element(v.begin(), v.end());
				int d = distance(v.begin(), result);
				opt[i][j] = v[d];

				if (ops[d] == 'C') dir[i][j] = ((a[i-1] == b[j-1]) ? '@' : 'C');
				else dir[i][j] = ops[d];
			}
		}

		int r = a.length();
		int c = b.length();
		stack<Command> st;
		while (dir[r][c] != 0)
		{
			char buf[5];
			buf[0] = 0;
			if (dir[r][c] == 'C')
			{
				st.push(Command{ dir[r][c], a[r - 1], c });
				r--; c--;
			}
			else if (dir[r][c] == 'D')
			{
				st.push(Command{ dir[r][c], b[c - 1], c });
				c--;
			}
			else if (dir[r][c] == 'I')
			{
				st.push(Command{ dir[r][c], a[r - 1], r });
				r--;
			}
			else if (dir[r][c] == '@')
			{
				r--; c--;
			}
		}

		int offset = 0;
		while (!st.empty())
		{
			Command& com = st.top();
			cout << com.dir << com.c;
			cout << setfill('0') << setw(2);
			if (com.dir == 'I')
			{
				cout << com.pos;
				offset++;
			}
			else if (com.dir == 'D')
			{				
				cout << com.pos + offset;
				offset--;
			}
			else
			{
				cout << com.pos + offset;
			}
			
			st.pop();
		}
		cout << "E" << endl;
		cin >> input;
	}

	return 0;
}
