 ///
 /// @file    for_each.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 23:04:10
 ///
 //for_each用法示例
#include <iostream>
#include<algorithm>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

typedef vector<int> VI;
typedef  VI::iterator VIP;

void func(VI::value_type v)
{
	cout<<v<<" ";
}

int main(void)
{
	int sz[6]={1,2,3,4,5,6};
	VI ob(sz,sz+6);
	for_each(ob.begin(),ob.end(),func);//对ob中多有元素执行func操作
	cout<<endl;

	getchar();
	return 0;
}

