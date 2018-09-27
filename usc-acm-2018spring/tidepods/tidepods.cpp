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
	string filename = "tidepods";
	ifstream inFile(filename + ".in");
	ofstream outFile(filename + ".out");
	int K;
	inFile >> K;
	for (int i = 0; i < K; i++)
	{
		/* input */
		// t: number of traits
		// n: number of model people
		int t, n;
		inFile >> t >> n;
		vector<vector<int>> traits(n, vector<int>(t, -1));
		vector<int> scores(n, -1);
		vector<int> indiv(t, -1);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < t; k++)
			{
				inFile >> traits[j][k];
			}
			inFile >> scores[j];
		}
		// the individual
		for (int k = 0; k < t; k++)
		{
			inFile >> indiv[k];
		}

		/* calculation */
		int maxScore = INT_MIN;
		int minScore = INT_MAX;
		vector<int> share(n, 0);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < t; k++)
			{
				if (traits[j][k] == 1 && indiv[k] == 1)
				{
					share[j]++;
				}
			}
			int comp = share[j] * scores[j];
			if (comp > maxScore) maxScore = comp;
			if (comp < minScore) minScore = comp;
		}
		
		/* output */
		outFile << "Data Set " << i + 1 << ": " << endl;
		outFile << maxScore - minScore << endl;
		outFile << endl;
	}
}