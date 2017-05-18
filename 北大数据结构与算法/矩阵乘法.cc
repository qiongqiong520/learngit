 ///
 /// @file    矩阵乘法.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 17:36:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#define ROWS 8
#define COLS 8
int a[ROWS][COLS];
int b[ROWS][COLS];
int c[ROWS][COLS];//结果

int main()
{
	int m,n,p,q;
	cin>>m>>n;
	for(int i=0;i<m;++i)//读入矩阵a
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	cin>>p>>q;
	for(int i=0;i<p;++i)//读入矩阵b
		for(int j=0;j<q;++j)
			cin>>b[i][j];
	for(int i=0;i<m;++i){
		for(int j=0;j<q;++j){
			 c[i][j]=0;
			 for(int k=0;k<n;++k)
				 c[i][j]+=a[i][k]*b[k][j];
		}
	}
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<q;++j){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}


