 ///
 /// @file    5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 16:22:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;
struct test{
	int a:2;
	int b:2;
	int c:1;
};
int main(int argc,char** argv){
	test t;
	t.a=1;
	t.b=3;
	t.c=1;
	cout<<t.a<<endl;
	cout<<t.b<<endl;
	cout<<t.c<<endl;
	return 0;
}

