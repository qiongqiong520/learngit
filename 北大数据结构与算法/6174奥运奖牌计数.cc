 ///
 /// @file    6174奥运奖牌计数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 19:17:58
 ///
 //奥运奖牌计数，ch105/07
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n,g,s,b;
	int sg =0,ss=0,sb=0,total =0;
	
	cin >>n;
	while(n--){
		cin>>g>>s>>b;
		sg+=g;
		ss+=s;
		sb+=b;
		total +=g+s+b;
		}
	cout<<sg<<" "<<ss<<" "<<sb<<" "<<total;
	return 0;
}
