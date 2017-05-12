 ///
 /// @file    7542正常血压.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 21:22:01
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n;
	int low,high;
	cin>>n;
	int t=0;
	int maxT=0;
	while(n--){
		cin>>high>>low;
		if(high>=90&&high<=140&&low<=90&&low>=60){
			++t;
		if(t>maxT)
			maxT=t;
	}
	else
		t=0;

}
cout<<maxT;
return 0;
}
