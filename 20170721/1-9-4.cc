 ///
 /// @file    1-9-4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 23:51:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void d(ArrayElement x[],int n){
	int i=1;
	do{
		x[i]+=2;
		i+=2;
	}while(i<=n);
	i=1;
	while(i<=(n/2)){
		x[i]+=x[i+1];
		i++;
	}
}
