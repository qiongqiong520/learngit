 ///
 /// @file    10421从字符串中取数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 17:59:20
 ///
 
#include <iostream>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;

double GetDoubleFromString(char * str)
{
	static char * p;
	if(str)
		p=str;
	double num=0;
	while(*p&&!(*p>='0'&&*p<='9'))
		++p;
	if(*p==0)
		return -1;
	while(*p>='0'&&*p<='9'){
		num =num*10+*p-'0';
		++p;
	}
	if(*p=='.'){
		++p;
		double i=10;
		while(*p>='0'&&*p<='9'){
			num+=(*p-'0')/i;
			++p;
			i*=10;
		}
	}
	return num;
}

int main()
{
	char line[300];
	while(cin.getline(line,280)){
		double n;
		n =GetDoubleFromString(line);
		while(n>0){
			cout<<std::fixed<<std::setprecision(6)<<n<<endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}

