// Lab_05_3.cpp
// Обухова Віктора
// Лабораторна робота No 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 0.7

#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

using namespace std;
double k(const double x);
int main()
{
	SetConsoleOutputCP(1251);

	double zp, g, zk;
	int n;
	cout << "zp = "; cin >> zp;
	cout << "zk = "; cin >> zk;
	cout << "n = "; cin >> n;
	cout << fixed;

	cout << "-------------------------------" << endl;
	cout << "|    " << "Результати обчислень" << "     |" << endl;
	cout << "-------------------------------" << endl;
	cout << "|" << setw(8) << "k" << "      |"
		<< setw(8) << "S" << "      |" << endl;
	cout << "-------------------------------" << endl;

	double dz = (zk - zp) / n;
	double z = zp;
	

	while (z <= zk)
	{
		g = k(z * z + 1) - k(z *z - 1) + 2 * k(z);
		cout << "|" << setw(8) << setprecision(0) << k << "      |"
			<< setw(10) << setprecision(5) << g << "    |" << endl;

		z += dz;
	}
	return 0;
}
double k(const double x)
{
	if (abs(x) >= 1)
		return (exp(x) + sin(x)) / (sin(x) * sin(x) + 1);
	else
	{
		double A = 1/exp(x) ;
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = pow(x, i) / i;
			a *= R;
			S += a;
		} while (i < 5);
		S *= A;
		return S;
	}
}