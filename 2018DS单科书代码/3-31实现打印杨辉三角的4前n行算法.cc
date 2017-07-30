 /// @date    2017-07-30 20:04:31
 ///
#include<stdio.h>
#include<iostream>
#include"queue.h"

void YANGVI(int n){
	//分行打印二项式展开式的系数，在程序中利用一个队列，在输出上一行系数时
	//将其下一行的系数与县仿如队列，在各行系数之间插入一个0
	Queue q(n+1);//建立队列对象并初始化
	int i=1,j,s=k=0,t,u;//计算下一行系数时用到的工作单元
	q.EnQueue(i);q.EnQueue(i);//预先放入地1行两个系数
	for(i=1;i<=n;i++){//逐行处理
		cout<<endl;
		q.EnQueue(k);//各行间插入一个0
		for(j=1;j<=i+2;j++){//处理第i行的i+2ge系数
			q.DeQueue(t);//读取一个系数
			u=s+t;q.EnQueue(u);//计算下一行系数，并进入队列
			s=t;
			if(j!=i+2)cout<<s<<' ';//打印一个系数，第i+2个是0
		}
	}
};

void YANGVI(int n){
	//分行打印二项式展开是系数，在程序中利用了一个队列，在输出上一行系数时
	//将其下一行的系数与县仿如队列中，在各行系数之间插入一个0
	Queue q(n+1);//建立队列对象并初始化
	int i=1,j,s=k=0,t,u;//计算下一行系数时公道的工作单元
	q.EnQueue(i);q.EnQueue(i);//预先放入第一行系数
	for(i=1;i<=n;i++){//逐行处理
		cout<<endl;//换一行
		q.EnQueue(k);//各行间插入一个0
		for(j=1;j<=i+2;j++){//处理第i行的i+2ge系数
			q.DeQueue(t);//读取一个系数
			u=s+t;q.EnQueue(u);//计算下一行系数，并经入队列
			s=t;//
			if(j!=i+2)cout<<s<<' ';//打印一个系数，第i+2个是0
		}
	}
};

void YANGVI(int n){
	//分行打印二项式展开式系数，在程序中利用了一个队列，在输出上一行系数时
	//将其下一行的系数与县仿如队列中，在各行系数之间插入一个0
	Queue q(n+1);//建立队列对象并初始化
	int i=1,j,s=k=0,t,u;//计算下一行系数时用到的单元
	q.EnQueue(i);q.EnQueue(i);//预先放入地1行的两个系数
	for(i=1;i<=n;i++){//逐行处理
		cout<<endl;
		q.EnQueue(k);//各行间插入一个0
		for(j=1;j<=i+2;j++){//处理地i行的i+2个系数，包括一个0
			q.DeQueue(t);//读取一个系数
			u=s+t;q.EnQueue(u);//计算下一行系数，并进入队列
			s=t;
			if(j!=i+2)cout<<s<<' ';//打印一个系数，地i+2个是0
		}
	}
};
