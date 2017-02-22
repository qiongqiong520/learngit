 ///
 /// @file    11
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-20 15:27:20
 ///
 
#include<iostream>
#include<vector>
//容器之一
//
//
using std::cout;
using std::endl;
using std::vector;

void printCapacity(vector<int> & vec)
{
	cout<<"vec 's size="<<vec.size()<<endl;
	cout<<"vec's capicility = "<<vec.capacility<<endl;
}


int main(void)
{
	//vector 是一个动态数组，可以进行扩容
	//策略1:假设当前容量是x，先申请2x的容量
	//2.再将原来的数据拷贝过来，拷贝到新申请的空间去,
	//并且释放原来的数据所占用的空间
	//3.最后再添加新的数据
	vector<int> vecInt;
	cout<<endl;
	vecInt.reserve(5);//开辟五个数据空间
	vecInt.push_back(1);
	printCapacity(vecInt);
	vecInt.push_back(2);
	printCapacity(vecInt);
	vecInt.push_back(3);
	printCapacity(vecInt);
	vecInt.push_back(4);
	printCapacity(vecInt);
	vecInt.push_back(4);
	printCapacity(vecInt);

	for(int idx =0;idx !=vecInt.size();++idx)
	{
		cout<<vecInt[idx]<<" ";
	}

	//迭代器实现
	vector<int>::iterator it;
	for(it =vecInt.begin();it!=vecInt.end();++it){
		cout<<*it;
	}
	cout<<endl;
	for(auto& elem:vecInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
}

