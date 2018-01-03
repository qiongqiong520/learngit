 ///
 /// @file    size.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-10 09:30:29
 ///
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	vector<int> vi;
	for(int i=1;i<=3;i++){
		vi.push_back(i);//
	}
	printf("%d\n",vi.size());
	return 0;
}
