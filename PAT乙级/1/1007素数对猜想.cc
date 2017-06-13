 ///
 /// @file    1007素数对猜想.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-01 17:30:55
 ///
 
#include <iostream>
#include<set>
#include<vector>
#include<math.h>
using std::cin;
using std::vector;
using std::set;
using std::cout;
using std::endl;
bool isPrime(int n){
	if(n==2)return true;
	for(int i=2;i<=(int)sqrt((double)n)+1;i++){
		if(n%i==0)return false;
	}
	return true;
}
int main(int argc,char* argv[]){
	int num;
	while(cin>>num){
		set<int>set;
		vector<int> curr;
		for(int i=2;i<=num;i++){
			if(isPrime(i))set.insert(i);
		}
		int count=0;
		int n=set.size();
		while(!set.empty()){
			int k=*set.begin();
			if(set.find(k+2)!=set.end())count++;
			set.erase(k);
		}
		printf("%d\n",count);
	}
	return 0;
}
