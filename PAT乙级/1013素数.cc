 ///
 /// @file    1013素数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 17:18:34
 ///
 
#include <iostream>
#include<math.h>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool isPrime(int n)
{
	if(n<2)return false;
	for(int i=2;i<(int)sqrt((double)n) +1;i++){
		if(n%i==0)return false;
	}
	return true;
}

int main(int argc,char* argv[])
{
	int n,m;
	while(cin>>n>>m){
		int count=0;
		vector<int> p;
		int i=0;
		while(1){
			if(isPrime(i)){
				p.push_back(i);
				if(p.size()==m)break;
			}
			i++;
		}
		for(int i=n-1;i<m;i++){
			if(count==9||i==m-1){
				count =0;
				cout<<p[i]<<endl;
			}
			else{
				count++;
				cout<<p[i]<<" ";
			}
		}
	}
	return 0;
}
