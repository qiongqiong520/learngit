 ///
 /// @file    1-9-1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 23:43:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void d(ArrayElement x[],int n){
	int i=1;
	count++;
	do{
		x[i]+=2;count++;
		i+=2;count++;
		count++;//指针while语句
	}while(i<=n);
	i=1;
	count++;
	while(i<=(n/2)){
		count++;//针对while语句
		x[i]+=x[i+1];
		count++;
		i++;
		count++;
	}
	count++;//针对最后一次while语句
}

