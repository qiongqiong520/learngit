 ///
 /// @file    1036和奥巴马一起编程.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 19:53:03
 ///
 
#include <iostream>
#include<string>
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(int argc,char* argv[])
{
	int n;
	char c;
	while(cin>>n>>c){
		int m;
		if(n%2==0)m=n/2;
		else m=n/2+1;
		for(int i =0;i<n;i++)cout<<c;
		cout<<endl;
		for(int i=1;i<m-1;i++){
			for(int j=0;j<n;j++){
				if(j==0||j==n-1)cout<<c;
				else cout<<" ";
			}
			cout<<endl;
		}
		for(int i=0;i<n;i++)cout<<c;
		cout<<endl;
	}
}
