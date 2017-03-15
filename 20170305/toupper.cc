 ///
 /// @file    toupper.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-05 21:47:33
 ///
 
#include <iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
using std::iterator;
using std::string;

int main()
{
	vector<int>::iterator it;//it 能读写vector的元素
	vector<int> s(10);
	string::iterator it2;//it2能读写string对象中的字符

	vector<int>::const_iterator it3;//ot3只能读写元素，不能写元素
	string::const_iterator it4;//it4只能读写字符，不能写字符
	
	for(auto it =s.begin();it!=s.end()&&!isspace(*it);++it)
	{
		*it = toupper(*it);//将当前字符改为大写形式
	}
	cout<<*it<<endl;

	//运算对象的啊求值顺序和优先级和结合顺序无关
	//
	
#if 0
	//begin和end运算符
	vector<int> v;
	const <veactor> cv;
	auto it1=v.begin();//
	auto it2= cv.begin();

#endif

	vector<int> v;
	for(auto & i:v)
		i*=i;
	for(auto &i:v)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}

