 ///
 /// @file    1011A+B和C.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-02 22:42:46
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int n;
	while(cin>>n){
		double a,b,c;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			if(a+b>c)
				cout<<"Case #"<<i+1<<": true"<<endl;
			else
				cout<<"Case #"<<i+1<<": false"<<endl;
		}
	}
	return 0;
}
