#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Sample
{
	int id;
	int carriedBy;
	int health;
	vector<int> costs;
	double ratio;

	Sample(int id, int carriedBy, int health, int costA, int costB, int costC, int costD, int costE)
	{
		this->id = id;
		this->carriedBy = carriedBy;
		this->health = health;
		costs.push_back(costA);
		costs.push_back(costB);
		costs.push_back(costC);
		costs.push_back(costD);
		costs.push_back(costE);
		ratio = (double)health / (double)accumulate(costs.begin(), costs.end(), 0);
	}
};

bool comp(Sample* a, Sample* b)
{
	return (a->ratio > b->ratio);
}

/**
 * Bring data on patient samples from the diagnosis machine to the laboratory with enough molecules to produce medicine!
 **/
int main()
{
	int projectCount;
	cin >> projectCount; cin.ignore();
	for (int i = 0; i < projectCount; i++) {
		int a;
		int b;
		int c;
		int d;
		int e;
		cin >> a >> b >> c >> d >> e; cin.ignore();
	}

	int maxSamples = 1; // carry how many samples at a time
	int size = 0;

	// game loop
	while (1) {
		string module;
		vector<int> storage(5, 0);
		bool sentAction = false;
		for (int i = 0; i < 2; i++) {
			string target;
			int eta;
			int score;
			int storageA;
			int storageB;
			int storageC;
			int storageD;
			int storageE;
			int expertiseA;
			int expertiseB;
			int expertiseC;
			int expertiseD;
			int expertiseE;
			cin >> target >> eta >> score >> storageA >> storageB >> storageC >> storageD >> storageE >> expertiseA >> expertiseB >> expertiseC >> expertiseD >> expertiseE; cin.ignore();
			if (i == 0)
			{
				module = target;
				storage[0] = storageA;
				storage[1] = storageB;
				storage[2] = storageC;
				storage[3] = storageD;
				storage[4] = storageE;
			}
			cerr << "Player " << i + 1 << " target=" << target << " score=" << score << " holding: " << storageA << "A " << storageB << "B " << storageC << "C " << storageD << "D " << storageE << "E" << endl;
		}
		int availableA;
		int availableB;
		int availableC;
		int availableD;
		int availableE;
		cin >> availableA >> availableB >> availableC >> availableD >> availableE; cin.ignore();
		int sampleCount;
		cin >> sampleCount; cin.ignore();
		cerr << "Sample count: " << sampleCount << endl;
		vector<Sample*> samples;
		Sample* curr = nullptr;
		for (int i = 0; i < sampleCount; i++) {
			int sampleId;
			int carriedBy;
			int rank;
			string expertiseGain;
			int health;
			int costA;
			int costB;
			int costC;
			int costD;
			int costE;
			cin >> sampleId >> carriedBy >> rank >> expertiseGain >> health >> costA >> costB >> costC >> costD >> costE; cin.ignore();
			cerr << sampleId << " carried by " << carriedBy << " health=" << health << " cost: " << costA << " " << costB << " " << costC << " " << costD << " " << costE << endl;

			if (carriedBy == -1)
			{
				samples.push_back(new Sample(sampleId, carriedBy, health, costA, costB, costC, costD, costE));
			}
			else if (carriedBy == 0)
			{
				curr = new Sample(sampleId, carriedBy, health, costA, costB, costC, costD, costE);
			}
		}

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;
		if (module == "DIAGNOSIS")
		{
			if (curr != nullptr)
			{
				cout << "GOTO MOLECULES" << endl;
			}
			else
			{
				sort(samples.begin(), samples.end(), comp);
				int i = 0;
				for (int i = 0; i < samples.size(); i++)
				{
					if (samples[i]->carriedBy == -1)
					{
						curr = samples[i];
					}
				}
				cout << "CONNECT " << samples[i]->id << endl;
			}
		}
		else if (module == "MOLECULES")
		{
			for (int i = 0; i < 5; i++)
			{
				if (storage[i] < curr->costs[i])
				{
					char a = 65 + i;
					cout << "CONNECT " << a << endl;
					sentAction = true;
					break;
				}
			}
			if (sentAction == false)
			{
				cout << "GOTO LABORATORY" << endl;
			}
		}
		else if (module == "LABORATORY")
		{
			if (curr != nullptr)
			{
				cout << "CONNECT " << curr->id << endl;
				curr = nullptr;
			}
			else
			{
				cout << "GOTO DIAGNOSIS" << endl;
			}
		}
		else if (module == "START_POS")
		{
			cout << "GOTO DIAGNOSIS" << endl;
		}
		else
		{
			cout << "GOTO DIAGNOSIS" << endl;
		}
	}
}