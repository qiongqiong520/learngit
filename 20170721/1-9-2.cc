 ///
 /// @file    1-9-2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 23:47:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void d(ArrayElement x[],int n){
	int i=1;
	do{
		count+=3;i+=2;
	}while(i<=n);
	i=1;
	while(i<=(n/2)){
		count+=3;i++;
	}
	count+=3;
}

