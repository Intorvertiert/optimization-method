#include <iostream>
#include <cmath>
#include <math.h>
using std::cout;
using std::endl;
using std::cin;
#define EXP 2.718281828459045
/*
f(x) = x + (4.0 / (x*x));
a,b E [1,4]
exp = 0.0001;
Метод деления пополам
Метод золотого сечения +
Mетод Фибоначчи +
*/

double func(double x)
{
	return ((-log(x)-1)/x);
}

void GoldenMethod(double a, double b, double e)
{
	long nIter = 1;
	double min = 0;

	double t = (sqrt(5) - 1) * 0.5;
	double x1 = b - t * (b - a);
	double x2 = a + t * (b - a);
	while (e <= fabs(b - a))
	{
		cout << "Iteration : " << (nIter++) << std::endl;
		cout << "a "<< nIter << " iteration ="<< x1 << endl;
		cout << "b "<< nIter << " iteration ="<< x2 << endl;
		cout << "f(a) " << func(x1) << endl;
		cout << "f(b) " << func(x2) << endl;
		if (func(x2) < func(x1))
			a = x1;
		else
			b = x2;
		x1 = b - t * (b - a);
		x2 = a + t * (b - a);
		std::cout << std::endl;
	}
	std::cout << "min =  " << (min = (a + b) * 0.5) << std::endl;
	std::cout << "f(min) " << func(min) << std::endl;

	

}

int F(int n)
{
	int f, f1(1), f2(1), m(0);
	while (m < n - 1)
	{
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		++m;
	}
	return f1;
}

void Fib(double a, double b, double eps)
{
	cout << "\n\n\n\tМетод Фибоначчи:\n\n";
	double x1, x2, _x, xf1, xf2;
	int k(0);
	int N(0);
	double fn1(1), fn2(1), fn, f = (b - a) / eps;
	while (fn1 < f)
	{
		fn = fn1 + fn2;
		fn1 = fn2;
		fn2 = fn;
		++N;
	}
	x1 = a + (double)F(N - 2) / F(N) * (b - a) - (N & 1 ? -1 : 1) * eps / F(N);
	x2 = a + (double)F(N - 1) / F(N) * (b - a) + (N & 1 ? -1 : 1) * eps / F(N);
	xf1 = func(x1);
	xf2 = func(x2);
P:
	++k;
	if (xf1 >= xf2)
	{
		a = x1;
		x1 = x2;
		xf1 = xf2;
		x2 = a + (double)F(N - k - 1) / F(N - k) * (b - a) + ((N - k) & 1 ? -1 : 1) * eps / F(N - k);
		xf2 = func(x2);
	}
	else
	{
		b = x2;
		x2 = x1;
		xf2 = xf1;
		x1 = a + (double)F(N - k - 2) / F(N - k) * (b - a) - ((N - k) & 1 ? -1 : 1) * eps / F(N - k);
		xf1 = func(x1);
	}
	cout << "Iteration # " << k << '\n'
		<< "a = " << x1 << "\t\tF(a) = " << xf1
		<< "\nb = " << x2 << "\t\tF(b) = " << xf2
		<< '\n' << std::endl;
	if (fabs(b - a) <= eps)
	{
		_x = (a + b) / 2;
		cout << "Result:\nx = " << _x << "\t\tF(x) = " << func(_x) <<
			"\n Num of iteration: " << k;
	}
	else
		goto P;
}

void Dicho(long double a, long double b, double eps)
{
	int IterCounter = 0;
	double c = 0;
	while (!(abs(b - a)/2.0 <= eps)) {
		++IterCounter;
		c = (a + b) / 2;
		if (func(c - eps) > func(c + eps)) {
			a = c;
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
		}
		else {
			b = c;
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
		}
		printf("%d Iteration: \n", IterCounter);
		cout << "x = " << (a + b) / 2 << endl;
		cout << "f(x) = " << func((a+b)/2) << endl;
		std::cout << std::endl;
	}
}

int main(int argc, char** argv)
{
	double eps = 0.00001;
	double a = EXP;
	double b = pow(EXP,3);
	int num;
	while (true)
	{
		cout <<
			"1. Golden method \n2. Fib method \n3. Dicho method \n";
		cin >> num;
		switch (num)
		{
		case 1:
			GoldenMethod(a, b, eps);
			std::cout << std::endl;
			break;
		case 2:
			Fib(a, b, eps); 
			std::cout << std::endl;
			break;
		case 3:
			Dicho(a, b, eps);
			std::cout << std::endl;
			break;
		default:
			break;
		}
	}
	
	system("pause >> NULL");
	return 0;
}