#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
/*	*//*Fraction a(1, 2);
	Fraction b(2, 3);
	Fraction c(-1, 2);
	Fraction d(-2050, 400);
	Fraction f(3, -5);
	Fraction e(5, 1);
	Fraction g(1, 5);
	Fraction i(5, 1);
	Fraction j(-5, 1);
	Fraction l(10, 2);
	Fraction k(36, 6);
	cout << (e == i) << endl;
	cout << (e == j) << endl;
	cout << (e == 5) << endl;
	cout << (l == 5) << endl;
	cout << (e != i) << endl;
	cout << (e != g) << endl;
	cout << (e >= k) << endl;
	cout << (e <= 5) << endl;
	cout << (k <= 6) << endl;
	cout << (e <= g) << endl;
	cout << (e >= i) << endl;
	cout << (e > 4) << endl;
	cout << (e > 8) << endl;
	cout << (e < 8) << endl;*/

	const Fraction d1(1, -2), d2(1, 2);
	cout << d1+d2 << endl;
	cout << d1 - d2 << endl;
	cout << d1 * d2 << endl;
	cout << d1 / d2 << endl;
	cout << 1 + d2 << endl;
	cout << 1 - d2 << endl;
	cout << 1 * d2 << endl;
	cout << 1 / d2 << endl;
	const Fraction a(-1, 2);

	cout << -a << endl;
	Fraction b;
	cin >> b;
	cout << b;
	return 0;
}