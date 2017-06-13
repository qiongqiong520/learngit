 ///
 /// @file    8219判断数正负.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-11 23:55:03
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(){
	int N;
	cin>>N;
	if(N>=-1000000000&&N<=1000000000)
	{
		if(N>0)
			cout<<"positive"<<endl;
		else if(N==0)
			cout<<"zero"<<endl;
		else
			cout<<"negative"<<endl;
	}
	else
		cout<<"error"<<endl;
	return 0;
}
