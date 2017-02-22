 ///
 /// @file    11.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-20 15:27:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
void printCin()
{
	cout<<"cin 's badbit ="<<cin.bad()<<endl;
	cout<<"cin 's failbit ="<<cin.fail()<<endl;
	cout<<"cin 's eofbit ="<<cin.eof()<<endl;
	cout<<"cin 's goodbit ="<<cin.good()<<endl;
}

int main(void)
{
	int num;
	printCin();
	while(cin>>num)
	{
		cout<<"num ="<<num<<endl;
	}
	printCin();
	cin.clear();//重置状态
	cin.ignore(1024,'\n');//清空缓冲区
	printCin();
	cout<<"num="<<num<<endl;

	cin>>num;
	printCin();


	return 0;
}
