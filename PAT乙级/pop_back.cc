 ///
 /// @file    pop_back.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-10 09:27:54
 ///
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	vector<int> vi;
	for(int i=1;i<=3;i++){
		vi.push_back(i);//将1，2，3一次插入末尾
	}
	vi.pop_back();//删除vi的为元素
	for(int i=0;i<vi.size();i++){//size函数会给vi中元素个数
		printf("%d ",vi[i]);
	}
	return 0;
}
