 ///
 /// @file    map_inset.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-02 16:06:56
 ///
#include <iostream>
#include<list>
#include<vector>
#include<string>
#include<map>
#include<deque>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::list;
using std::deque;
using std::vector;

//vector和deque类的容器创建后可以通过容器名
//下标或容器名.at(序号)的形式进行重载,也支持迭代器访问
//list类容器对下标运算符不支持下标运算符[]
//无法使用[]对元素进行随机访问
int main(void)
{
#if 0
 	vector<int>  obv(10);//创建空容器，申请10个int元素初始化为0
	list<int> obl(20);//创建list型对象包含20个int型元素初始化为0
	vector<int> obl(10,8);//10个int型元素，每个都初始化为88
#endif

	//容器创建与元素访问
	//1。创建vector容器
	vector<int> obv;//创建空容器vector
	cout<<"obv的元素个数为:"<<obv.size()<<endl<<endl;//size用以返回

	//2.创建deque容器
	double sz[5] ={1,2,3,4,5};//创建double型数组
	deque<double> obD(sz,sz+5);//创建deque型容器obd，并用sz收地址和末地址为其初始化

	//2.1使用下标【】访问deque容器的元素
	for(int i=0;i<obD.size();i++)//对obD中对元素进行随机访问，下标表示法
	{
		cout<<obD[i]<<" ";
	}
	cout<<endl;
	//2.2使用迭代器访问deque容器的元素
	deque<double>::iterator id =obD.end();
	while(id!=obD.begin())
	{
 		id--;//注意，obD.end()指向的是最后一个元素的笑一个迭代器
		cout<<(*id)<<" ";
	}
	cout<<endl<<endl;
	//3.创建list容器
	list<float> obL(3,5);//创建大小为list型容器obl，其中每个元素都初始化为5

	//3.1 list不支持下标访问
	
	//3.2使用迭代器访问list容器的元素
	list<float>::iterator iter=obL.begin();//创建list型迭代器，蕾丝指针的概念，并使其指向obL的第一个元素

	while(iter!=obL.end())
		//while结构，直到iter指向obl的尾部
		{
			(*iter)+=2;
			cout<<(*iter)<<" ";//通过迭代器间接访问容器中的元素，和指针相似
			iter++;
			//指向下个元素
		}
	cout<<endl;

	//3.3在创建一个空的list容器，将其内容与obL内容进行交huan
	list<float> obL2(4,9);
	obL.swap(obL2);
//3.4 重新输出obL中的内容
for(iter =obL.begin();iter!=obL.end();iter++)
{
	cout<<(*iter)<<" ";
}
cout<<endl<<endl;


//4.
system("pause");
return 0;
}

	
