 ///
 /// @file    B1049数列的片段和.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-15 20:28:06
 ///
 
#include <iostream>
#include<iomanip>
using namespace std;

int main(int argc,char* argv[])
{
	int n;
	while(cin>>n){
		double *nums=new double[n];
		for(int i=0;i<n;i++)cin>>nums[i];
		double sum=0;
		for(int i=0;i<n;i++)sum+=nums[i]*(i+1)*(n-i);
		cout<<fixed<<setprecision(2)<<sum<<endl;
	}
	return 0;
}
