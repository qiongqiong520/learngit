 ///
 /// @file    insert.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-10 09:33:55
 ///
 
#include <stdio.h>
#include<vector>
using namespace std;
int main(){
	vector<int> vi;
	for(int i=1;i<=5;i++){
		vi.push_back(i);
	}
	vi.insert(vi.begin()+2,-1);
	for(int i=0;i<vi.size();i++){
		printf("%d ",vi[i]);
	}
	return 0;
}
