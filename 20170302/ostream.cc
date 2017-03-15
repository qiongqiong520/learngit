 ///
 /// @file    ostream.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 22:48:03
 ///
 //输出流迭代器
#include <iostream>
#include<iterator>
#include<algorithm>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main(void)
{
	int sz[6]={1,2,3,4,5,6};

	vector<int> ob(sz,sz+6);//创建vector容器
	ostream_iterator<int,char> osi(cout," ");//创建输出咧迭代器，将osi理解为容器
	copy(ob.begin(),ob.end(),osi);//将ob复制到流中,copy是泛型算法
	cout<<endl;

	getchar();
	return 0;
}
