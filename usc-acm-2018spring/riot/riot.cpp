#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
	string filename = "riot";
	ifstream inFile(filename + ".in");
	ofstream outFile(filename + ".out");
	int K;
	inFile >> K;
	for (int i = 0; i < K; i++)
	{
		/* input */
		// n: number of people
		int n;
		inFile >> n;
		vector<int> t(n, 0);
		for (int i = 0; i < n; i++)
		{
			inFile >> t[i];
		}

		/* calculation */
		int riot = 0;
		sort(t.begin(), t.end());
		for (int i = 0; i < n; i++)
		{
			if (riot >= t[i])
			{
				riot++;
			}
		}

		/* output */
		outFile << "Data Set " << i + 1 << ": " << endl;
		outFile << riot << endl;
		outFile << endl;
	}
}