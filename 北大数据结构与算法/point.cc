 ///
 /// @file    point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-26 16:45:06
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int *p1,*p2;//地址p1为100
	int n=4;//地址p2为200
	char * pc1,*pc2;
	//输出25，因为200-100/sizeof（int）=100/25=4
	p1=(int *)100;//地址为pc1为100
	p2=(int*)200;//地址为pc2为200
	cout<<"1)"<<p2-p1<<endl;
	//输出-100，因为100-200/sizeof(int)=-100
	pc1=(char*)p1;//输出29
	pc2=(char *) p2;//p2+n是一个指针,可以用它给p3赋值
	cout<<"2)"<<pc1-pc2<<endl;//输出29
	cout<<"3)"<<(p2+n)-p1<<endl;//输出90
	int * p3=p2+n;
	cout<<"4)"<<p3-p1<<endl;
	cout<<"5)"<<(pc2-10)-pc1<<endl;
	return 0;
}
	
