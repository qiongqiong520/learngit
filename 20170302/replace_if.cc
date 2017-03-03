 ///
 /// @file    replace_if.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 10:37:56
 ///
 
#include <iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

//class Comp
struct Comp{//可以少写一个public关键字
	 bool operator()(int num)
	{
 		if(num<3)//修改比3 小的数据
			return true;
		else
			return false;
	}
};

bool func(int num)
{
 	if(num>3)//修改比3大的数据
		return true;
	else
		return false;
}

int main(void)
{
 	vector<int> vecInt={1,2,3,4,5,6};

	std::less<int> it;
	it(1,2);
	//默认修改比3小大额数据为7
//	replace_if(vecInt.begin(),vecInt.end(),bind2nd(it,3),7);//绑定第二个参数
//	replace_if(vecInt.begin(),vecInt.end(),bind1st(it,3),7);//绑定第一个参数，默认修改比3大的所有值
 	//replace_if(vecInt.begin(),vecInt.end(),func,7);//绑定第二个参数
	replace_if(vecInt.begin(),vecInt.end(),Comp(),7);//绑定第一个参数，默认修改比3大的所有值

	ostream_iterator<int> osi(cout," ");
	copy(vecInt.begin(),vecInt.end(),osi);
	cout<<endl;

	return 0;
}


