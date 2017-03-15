 ///
 /// @file    equal.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 21:06:44
 ///
 //赋值进行正确的循环
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	using namespace std;
	int quiz[10]=
	{20,20,20,20,20,19,20,18,20,20};
	cout<<"Doing it right:\n"<<endl;

	int i;
	 for(i =0;quiz[i]==20;i++)
		cout<<"quiz"<<i<<"is a 20\n";

	 cout<<"Doing it dangerous wrong\n";
	 for(i=0;quiz[i]==20;i++)
		 cout<<"quiz"<<i<<"is a 20\n";

	 return 0;
}

