#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


long double f(long double &y) {
	return 1.0 - sin(y) / 2.0; // ������� ����������� x �� �������� �������
}

long double g(long double &x) {
	return 0.7 - cos(x - 1.0); // ������� ����������� y �� �������� �������
}

pair<long double, long double> simpleIt() {
	long double x0, y0;
	long double x = 0.001;
	long double y = 0.001;
	float eps = 0.00001f;
	
	do {
		x0 = x;
		y0 = y;

		x = f(y0);
		y = g(x0);
	} while (fabs(x - x0) >= eps && fabs(y - y0) >= eps);
	return make_pair(x, y);
}


int main() {
    cout << "SIMPLE ITERATIONS" << endl;
	auto result = simpleIt();
	cout << result.first << ' ' << result.second << endl;
    cout << endl;

	return 0;
}