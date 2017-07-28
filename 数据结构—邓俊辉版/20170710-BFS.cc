 ///
 /// @file    20170710-BFS.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-10 14:35:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;
while(!Q.empty()){//反复的
	int v=Q/dequeue();dTime(v)=++clock;//取出队首顶点，并
	for(int u=firstNthr(v);-1<u;u=nextNthr(v,u))//考察
		if(UNDISCOVERED==ststus(u)){//若u尚未被发现，则
			status(u)=DISCOVERED;Q.enqueue(u);//发现该顶点
			status(v,u)=TRUE;parent(u)=v;//引入树边
		}else//若u已被发现（正在队列中），或者甚至一访问完毕（已出队)
			status(v,u)=CROSS;//将(v,u)归类与跨边
	status(v)=VISITED;//这种版本简化完毕
}

