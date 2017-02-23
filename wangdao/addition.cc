 ///
 /// @file    addition.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 18:31:38
 ///
 //addition.cc
 //
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	using namespace std;
	double wages[3]={1000.0,2000.0,3000.0};
	short stacks[3]={1,2,3};

	//here has two ways to get the address
	
	double *pw =wages;//name of an array
	short *ps=&stacks[0];//or use address operator with array element

	cout<<"pw= "<<pw<<",*pw= "<<*pw<<endl;
	pw=pw+1;
	cout<<"add 1 to the pw pointer :\n";
	cout<<"pw ="<<pw<<",pw="<<*pw<<"\n\n";
	cout<<"ps ="<<ps<<",ps="<<*ps<<"\n\n";
	ps +=1;

	cout<<"access two elemts with array notation\n";
	cout<<"stacks[0]="<<stacks[0]<<",stacks[1]="<<stacks[1]<<endl;

	cout<<"access two elemts with array notation\n";
	cout<<"*stack="<<*stacks<<",*(stacks+1)="<<*(stacks+1)<<endl;

	cout<<sizeof(wages)<<"=size of wages array\n";
	cout<<sizeof(pw)<<"=size of pw pointer\n";
	return 0;
}


