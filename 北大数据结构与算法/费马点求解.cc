///
/// @file    费马点求解.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-08-27 13:45:49
///
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 1005
#define eps 1e-8     //搜索停止条件阀值
#define INF 1e99     
#define delta 0.98   //温度下降速度
#define T 100        //初始温度

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};  //上下左右四个方向

struct Point
{
	double x, y;
};

Point p[N];

double dist(Point A, Point B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double GetSum(Point p[], int n, Point t)
{
	double ans = 0;
	while(n--)
		ans += dist(p[n], t);
	return ans;
}

//其实我觉得这玩意儿根本不叫模拟退火
double Search(Point p[], int n)
{
	Point s = p[0];    //随机初始化一个点开始搜索
	double t = T;      //初始化温度
	double ans = INF;  //初始答案值
	while(t > eps)
	{
		bool flag = 1;
		while(flag)
		{
			flag = 0;
			for(int i = 0; i < 4; i++)    //上下左右四个方向
			{
				Point z;
				z.x = s.x + dx[i] * t;
				z.y = s.y + dy[i] * t;
				double tp = GetSum(p, n, z);
				if(ans > tp)
				{
					ans = tp;
					s = z;
					flag = 1;
				}
			}
		}
		t *= delta;
	}
	return ans;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		printf("%.0lf\n", Search(p, n));
	}
	return 0;
}


