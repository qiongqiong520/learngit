 ///
 /// @file    ostream.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 22:48:03
 ///
 //输入流迭代器，结束字符为非数字字符
#include <iostream>
#include<iterator>
#include<algorithm>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::cin;
int main(void)
{
 	//int sz[6]={1,2,3,4,5,6};

	vector<int> ob;//创建vector容器
	istream_iterator<int,char> isi(cin);//创建输出咧迭代器，将osi理解为容器
	copy(isi,istream_iterator<int,char>(),back_inserter(ob));
	for(vector<int>::iterator it =ob.begin();it!=ob.end();it++)//遍历输出ob中的元素
	cout<<*it<<" ";
	cout<<endl;
	getchar();
		return 0;
}
