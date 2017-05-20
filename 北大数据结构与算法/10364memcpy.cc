 ///
 /// @file    10364memcpy.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:55:53
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void Memory(void *src,void * dest,int size)
{
	char * csrc=(char *) src;
	char * cdest = (char *)dest;
	if(src==dest)
		return ;
	if(cdest>csrc&&cdest<csrc+size){
		//从后往前拷贝
		for(int i=size-1;i>=0;--i)
			cdest[i]=csrc[i];
	}
	else{
		//从前往后拷贝
		for(int i=0;i<size;++i)
			cdest[i]=csrc[i];
	}
}

void Print(int * p,int size)
{
	for(int i=0;i<size;++i)
		cout<<p[i]<<",";
	cout<<endl;
}
int main()
{
	int a[10];
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	int b[10]={0};
	Memory(a,b,sizeof(a));
	Print(b,n);

	int c[10]={1,2,3,4,5,6,7,8,910};
	Memory(c,c+5,5*sizeof(int));//将c的前一半拷贝到后一半
	Print(c,10);

	char s1[10]="123456789";
	Memory(s1+5,s1+4,4);//将s1[5]开始的4个字符考到s1[1]开始的地方
	cout<<s1<<endl;

	return 0;
}
