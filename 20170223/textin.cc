 ///
 /// @file    textin.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 22:16:45
 ///
 //ctrl+z 模拟eof，输入字符，按ctrl+z结束挂起，按fg回显，统计字符个数
 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	 using namespace std;
	 char ch;
	 int count=0;
	 cin.get(ch);//attempt to read a char
	 while(cin.fail()==false)
	 {
		 cout<<ch;
		 ++count;
		 cin.get(ch);
	 }
	 cout<<endl<<count<<"charaters read\n";
	 return 0;
}
