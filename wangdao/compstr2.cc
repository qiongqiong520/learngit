 ///
 /// @file    compstr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 21:16:56
 ///
 //for 循环测试条件
 //显示一个单词知道匹配为止
#include <iostream>
#include<cstring>
using std::cout;
using std::endl;

int main(void)
{
	using namespace std;
	char word[5]="?ate";
	for(char ch ='a';word!="mate";ch++)
	{
		cout<<word<<endl;
		word[0]=ch;
	}
	cout<<"After loop ends,word is "<<word<<endl;
	return 0;
}

