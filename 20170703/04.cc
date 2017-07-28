 ///
 /// @file    04.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-03 21:08:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;
template<typename T>
class XXX{
	public:
		void put(const T &e){//添加元素
			Q1.enqueue(e);
		}
		T remove(){//删除元素
			while(Q1.size()>1){
				Q2.enqueue(Q1.dequeue());
			}
			T tmp=Q1.dequeue();
			while(!Q2.empty()){
				Q1.enqueue(Q2.dequeue());
			}
			return tmp;
		}
	private:
		Queue<T> Q1,Q2;//私有队列
};//class XXX

int main()
{
	XXX x;
	for(in
	x.put(2);
	x.put(3);
	x.remove();
	x.put(5);
	x.put(7);
	x.remove();
	x.put(11);
	x.remove();
	x.remove();
	return 0;
}
