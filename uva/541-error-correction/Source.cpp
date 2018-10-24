#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	//freopen("input.txt", "w", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 1; // size of matrix
	cin >> n;
	while (n != 0)
	{
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		vector<int> rowSum(n, 0);
		vector<int> colSum(n, 0);
		int changeRow = 0;
		int changeCol = 0;
		int nonParityRow = 0;
		int nonParityCol = 0;

		// Read input
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				cin >> matrix[row][col];
				rowSum[row] += matrix[row][col];
				colSum[col] += matrix[row][col];
			}

			if (rowSum[row] % 2 != 0)
			{
				nonParityRow++;
				changeRow = row;
			}
		}

		for (int col = 0; col < n; col++)
		{
			if (colSum[col] % 2 != 0)
			{
				nonParityCol++;
				changeCol = col;
			}
			if (nonParityCol > 1)
			{
				break;
			}
		}

		// Output
		string result;
		if (nonParityRow + nonParityCol == 0)
		{
			result = "OK";
		}
		else if (nonParityRow == 1 && nonParityCol == 1)
		{
			result = "Change bit (" + to_string(changeRow + 1) + "," + to_string(changeCol + 1) + ")";
		}
		else
		{
			result = "Corrupt";
		}
		cout << result << endl;

		cin >> n;
	}

	return 0;
}
