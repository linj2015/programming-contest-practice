#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

//struct Num
//{
//	double x;
//	int y;
//	Num(double _x, int _y)
//	{
//		x = _x;
//		y = _y;
//	}
//};

int main()
{
	//freopen("heads.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/* Pre-computed solution works on uDebug but doesn't work for online judge */
	//vector<Num*> vec;
	//double a = 1.0;
	//int b = 0;
	//vec.push_back(new Num(1.0, 0));
	//for (size_t i = 1; i < 9001; i++)
	//{
	//	a /= 2.0;
	//	while (a < 1.0)
	//	{
	//		a *= 10.0;
	//		b++;
	//	}
	//	vec.push_back(new Num(a, b));
	//}

	int r, n;
	cin >> r;
	for (int i = 0; i < r; i++)
	{	
		cin >> n;
		cout << "2^" << -n << " = ";
		cout << fixed << setprecision(3) << pow(10, (-n * log10(2)) - floor(-n * log10(2)));
		cout << "E" << (int)floor(-n * log10(2)) << endl;
	}

	return 0;
}
