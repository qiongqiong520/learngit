 ///
 /// @file    9485左边i位取反.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 15:53:32
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int bitManipulation3(int n,int i){
	return n^(~0<<(32-i));
}

int main()
{
	int t,n,i;
	cin>>t;
	while(t--){
		cin>>n>>i;
		cout<<bitManipulation3(n,i)<<endl;
	}
	return 0;
}

