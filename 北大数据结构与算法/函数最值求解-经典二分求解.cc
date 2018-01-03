///
/// @file    函数最值求解-经典二分求解.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-08-27 13:58:10
///
//给出方程，其中，输入，求的最小值。
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define ITERS 10
#define T 100
#define eps 1e-8
#define delta 0.98
#define INF 1e99

using namespace std;

double x[ITERS];

int Judge(double x, double y)
{
	if(fabs(x - y) < eps) return 0;
	return x < y ? -1 : 1;
}

double Random()
{
	double x = rand() * 1.0 / RAND_MAX;
	if(rand() & 1) x *= -1;
	return x;
}

double F(double x, double y)
{
	return 6 * x * x * x * x * x * x * x + 8 * x * x * x * x * x * x + 7 * x * x * x + 5 * x * x - y * x;
}

void Init()
{
	for(int i = 0; i < ITERS; i++)
		x[i] = fabs(Random()) * 100;
}

double SA(double y)
{
	double ans = INF;
	double t = T;
	while(t > eps)
	{
		for(int i = 0; i < ITERS; i++)
		{
			double tmp = F(x[i], y);
			for(int j = 0; j < ITERS; j++)
			{
				double _x = x[i] + Random() * t;
				if(Judge(_x, 0) >= 0 && Judge(_x, 100) <= 0)
				{
					double f = F(_x, y);
					if(tmp > f) 
						x[i] = _x;
				}
			} 
		}
		t *= delta;
	}
	for(int i = 0; i < ITERS; i++)
		ans = min(ans, F(x[i], y));
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		double y;
		scanf("%lf", &y);
		srand(time(NULL));
		Init();
		printf("%.4lf\n", SA(y));
	}
	return 0;
}

