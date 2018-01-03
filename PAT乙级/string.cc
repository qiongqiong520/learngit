 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-10 09:55:09
 ///
 
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string str[3]={"bbbb","cc","aaa"};
	sort(str,str+3);
	for(int i=0;i<3;i++){
		cout<<str[i]<<endl;
	}
	return 0;
}
