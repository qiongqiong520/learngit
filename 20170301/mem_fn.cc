 ///
 /// @file    mem_fn.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 11:17:29
 ///
 
#include <iostream>
#include<functional>
#include<vector>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;

class NumVal{
	 public:
	 	NumVal()
			:_ix(0)
		{
		}
		NumVal(int ix)
			:_ix(ix)
		{}
		void display()
		{
			cout<<_ix<<" ";
		}
		bool isEven()
		{
			return (bool)!(_ix%2);
		}
		bool isPrime()
		{
			for(int idx=2;idx<=_ix/2;++idx)
			{
				if(!(_ix%idx))
					return false;
			}
			return true;
		}
	private:
		int _ix;
};

int main(void)
{
	vector<NumVal> vecAcc(13);
	for(int idx =0;idx!=13;++idx)
	{
		vecAcc[idx]=NumVal(idx+1);
	}
	for_each(vecAcc.begin(),vecAcc.end(),std::mem_fn(&NumVal::display));
	cout<<endl;
	//从头到尾一趟遍历，删除素数元素·
	vecAcc.erase(remove_if(vecAcc.begin(),vecAcc.end(),std::mem_fn(&NumVal::isPrime)),vecAcc.end());
	//从新打印显示，remove不执行删除工作
	for_each(vecAcc.begin(),vecAcc.end(),std::mem_fn(&NumVal::display));
	cout<<endl;
return 0;
}
