///
/// @file    最小包含球问题求解.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-08-27 13:50:59
///
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
//给定三位空间的n点，找出一个半径最小的球吧这些点全部包围住
#define N 55
#define eps 1e-7
#define T 100
#define delta 0.98
#define INF 1e99

using namespace std;

struct Point
{
	double x, y, z;
};

Point p[N];

double dist(Point A, Point B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) + (A.z - B.z) * (A.z - B.z));
}

double Search(Point p[], int n)
{
	Point s = p[0];
	double t = T;
	double ans = INF;
	while(t > eps)
	{
		int k = 0;
		for(int i = 0; i < n; i++)
			if(dist(s, p[i]) > dist(s, p[k]))
				k = i;
		double d = dist(s, p[k]);
		ans = min(ans, d);
		s.x += (p[k].x - s.x) / d * t;
		s.y += (p[k].y - s.y) / d * t;
		s.z += (p[k].z - s.z) / d * t;
		t *= delta;
	}
	return ans;
}

int main()
{
	int n;
	while(cin >> n && n)
	{
		for(int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y >> p[i].z;
		double ans = Search(p, n);
		printf("%.5lf\n", ans);
	}
	return 0;
}

