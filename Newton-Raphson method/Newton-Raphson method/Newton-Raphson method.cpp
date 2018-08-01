// Newton-Raphson method.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include"stdlib.h"
#include"math.h"
double f(double w)
{
	double r = 225, c = 0.6*1e-6, l = 0.5,z=100;
	double temp1 = 1 / pow(r, 2.0) + pow(w*c - 1 / w / l, 2);
	return pow(temp1, 0.5) - 1 / z;
}
double f_prime(double w)
{
	double r = 225, c = 0.6*1e-6, l = 0.5,z=100;
	double temp1 = (w*c - 1 / w / l)*(c + 1 / pow(w, 2)/l);
	double temp2 = pow(1 / pow(r, 2) + pow(w*c - 1 / w / l, 2), 0.5);
	return temp1 / temp2;
}
void Newton_Raphson_recursive(double *x)
{
	double x0 = *x;
	*x = x0 - f(x0) / f_prime(x0);
	if (pow(pow(*x - x0, 2), 0.5) < 1e-6)
		return;
	else
		Newton_Raphson_recursive(x);
}
int _tmain(int argc, _TCHAR* argv[])
{
	double w = 100,w1;

	while (1)
	{
		w1 = w - f(w) / f_prime(w);
		if (pow(pow(w1 - w, 2), 0.5) < 1e-6)
			break;
		else
			w = w1;
	}
	printf("while loop : w=%f\n", w);

	w = 100;
	Newton_Raphson_recursive(&w);
	printf("recursive : w=%f\n", w);
	system("pause");
	return 0;
}

