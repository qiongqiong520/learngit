 ///
 /// @file    block.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 20:30:37
 ///
 //block.cpp
 //
#include <iostream>
using std::cout;
using std::endl;
int main(void)
{
	using namespace std;
	cout<<"The amazing account will sum and average";
	cout<<"five numbers for you.\n";
	cout<<"please enter five nmber\n";
	double number;
	double sum =0.0;
	for(int i =1;i<=5;i++)
	{//block start here 
		cout<<"value "<<i<<":";
		cin>>number;
		sum +=number;
	}//block end here
	cout<<"five exquisixte choices indeed!";
	cout<<"they sum to :"<<sum<<endl;
	cout<<"the average is:"<<sum/5<<".\n";
	return 0;
}

