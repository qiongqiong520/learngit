 ///
 /// @file    2017-06-20-442-八皇后问题.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-20 18:42:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//代码4.8皇后类
struct Queen{//皇后类
	int x,y;//皇后在棋盘上的位置坐标
	Queen(int xx=0,int yy=0):x(xx),y(yy){};
	bool operator==(Queen const& q)const{//重判等操作符,以检测不同皇后之间的冲突
		return (x==q.x)//行冲突(这一情况其实不会发生，可能略
			||(y==q.x)//列冲突
			||(x+y==q.x+q.y)//沿对角线冲突
			||(x-y==q.x-q.y);//沿对角线冲突
	}
	bool operator!=(Queen const& q)const{return !(*this==q);}//重载不等操作符
};
//4.9N皇后算法
void placeQueens(int N){//N皇后算法（迭代版):采用试探会所策略，借助栈记录查找结果
	Stack<Queen> solu;//存放部分解的栈
	Queen q(0,0);//从原点位置出发
	do{
		//反复试探回朔
		if(N<=solu.size()||N<=q.y){//若已出界，则
			q=solu.pop();q.y++;//回溯哦一行，并继续试探下一行
		}else{//否则继续试探下一行
			while((q.y<N)&&(0<=solu.find(q)))//通过与已有N皇后对比
			{q.y++;nCheck++;}//尝试找到可摆正下一皇后的列
				if(N>q.y){//若存在可摆放的列,则
					solu.push(q);//摆上当前皇后，并
					if(N<=solu.size())nSolu++;//若部分分解已成为全局解，则通过全局变量nSolu计数
					q.x++;q.y=0;//转入下一行，从第0列开始,试探下一皇后
				}
		}
	}while((0<q.x)||(q.y<N));//所有分支均已或穷举剪枝之后,算法结束
}

