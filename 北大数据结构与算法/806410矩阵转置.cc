 ///
 /// @file    806410矩阵转置.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 09:10:50
 ///
 
#include <iostream>
#include<iomanip>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

const int MX=110;
short a[MX][MX];
short b[MX][MX];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;++j){
			b[j][i]=a[i][j];
		}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
