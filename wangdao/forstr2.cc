 ///
 /// @file    forstr2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 20:50:58
 ///
 //两次使用都好运算符，将一个string类对象的内容反转
 //，输入字符串长大小受字符串大小限制
#include <iostream>
#include<string>
using std::cout;
using std::endl;

int main(void)
{
	using namespace std;
	cout<<"enter a word"<<endl;
	string word;
	cin>>word;

	char temp;
	int i,j;
	for(j=0,i=word.size()-1;j<i;--i,++j)
	{
		temp = word[i];
		word[i]=word[j];
		word[j]=temp;
	}
	cout<<word<<"\nDone\n"<<endl;
	return 0;
}
//在字符串反转方面，string提供更为简洁的方式
