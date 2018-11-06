#include <iostream>
#include <string>

using namespace std;

int main()
{
	//freopen("reverse.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;

		string rs1(200, '0');
		string rs2(200, '0');
		string ans;
		for (size_t j = 0; j < s1.length(); j++)
		{
			rs1[rs1.length() - 1 - j] = s1[j];
		}
		for (size_t j = 0; j < s2.length(); j++)
		{
			rs2[rs2.length() - 1 - j] = s2[j];
		}

		int carry = 0;
		for (size_t j = 0; j < 200; j++)
		{
			// start from end
			int k = 199 - j;

			int a, b;
			a = stoi(to_string(rs1[k] - '0'));
			b = stoi(to_string(rs2[k] - '0'));

			int sum = a + b + carry;
			if (sum > 9)
			{
				carry = sum / 10;
				ans += to_string(sum % 10);
			}
			else
			{
				carry = 0;
				ans += to_string(sum);
			}
		}
		if (carry != 0)
		{
			ans += to_string(carry);
		}

		// remove leading and trailing zeros
		size_t start = ans.find_first_not_of('0');
		ans = ans.substr(start);
		size_t end = ans.find_last_not_of('0');
		ans = ans.substr(0, end + 1);

		cout << ans << endl;
	}

	return 0;
}
