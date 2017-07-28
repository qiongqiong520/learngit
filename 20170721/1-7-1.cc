 ///
 /// @file    1-7-1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 23:22:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		c[i][j]=0.0;
		for(int j=1;k<=n;k++)
			c[i][j]=c[i][j]+a[i][j]*b[k][j];
	}

x=0;y=0;
for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
		for(int k=1;k<=j;k++)
		x=x+y;


int i=1,j=1;
while(i<=n&&j<=n){
	i=i+1;j=j+i;
}

int i=1;
do{
	for(int j=1;j<=n;j++)
		i=j+i;
}while(i<100+n);

