#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	double x, y;

	Point()
	{
		x = 0.0;
		y = 0.0;
	}

	Point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}

	Point operator+(Point B)
	{
		return Point(x + B.x, y + B.y);
	}

	Point operator-(Point B)
	{
		return Point(x - B.x, y - B.y);
	}

	Point operator*(double n)
	{
		return Point(x * n, y * n);
	}

	double cross(Point v)
	{
		return x * v.y - y * v.x;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);

	int N, Q;
	cin >> N >> Q;
	vector<Point> vertex;
	Point center;
	for (int n = 0; n < N; n++)
	{
		int x, y;
		cin >> x >> y;
		Point pt(x, y);
		vertex.push_back(pt);
		center = center + pt;
	}
	center = center * (1.0 / N);

	for (int q = 0; q < Q; q++)
	{
		int x, y;
		cin >> x >> y;
		Point pt(x, y);
		bool isInside = true;

		for (int i = 0; i < N; i++)
		{
			Point u;
			if (i == N - 1)
			{
				u = vertex[0] - vertex[i];
			}
			else
			{
				u = vertex[i + 1] - vertex[i];
			}
			// vector to the center
			Point v1 = center - vertex[i];
			// vector to the point
			Point v2 = pt - vertex[i];

			// check if the point is on the edge
			if (u.cross(v2) == 0)
			{
				isInside = true;
				break;
			}
			// check if cross product have different sign
			if (u.cross(v1) * u.cross(v2) < 0)
			{
				isInside = false;
				break;
			}
		}

		if (isInside)
		{
			cout << "D" << endl;
		}
		else
		{
			cout << "F" << endl;
		}
	}

	return 0;
}

