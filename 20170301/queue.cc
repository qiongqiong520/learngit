 /// @date    2017-03-02 20:03:58
 ///
#include<stdio.h>
#include <iostream>
using namespace std;

#define Maxsize 10

template<class T>
class CStack
{
	private:
		T data[Maxsize];
		int top;
	public:
		CStack():top(-1)
	{
	}
	void Push(void);
	void Pop(void);
	bool ifEmpty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	bool ifFull()
	{
		if(top==Maxsize-1)
			return true;
		else
			return false;
	}
	T getTop(void)
	{
		if(ifEmpty())
		{
			cout<<"栈为空，不能取栈顶!"<<endl;
			return -1;
		}else
			return this->data[top];
	}
};
template<class T>
void CStack<T>::Push(void)
{
	if(ifFull())
	{
		cout<<"栈已满，不能入栈!"<<endl;
		return ;
	}
	T a;
	cin>>a;
	this->data[++top]=a;
	cout<<"元素"<<a<<"入栈"<<endl;
}

template<class T>
void CStack<T>::Pop(void)
{
 	if(ifEmpty())
	{
		cout<<"栈为空,不能出栈!"<<endl;
		return ;
	}
	T temp=this->data[--top];
	cout<<"元素"<<temp<<"出栈!"<<endl;
}
int  main(void)
{
   	CStack<int> s1;//可以自己更换
	int i;
	do
	{
  		cout<<"\t=====================\n";
		cout<<"\t****顺序栈类模板*****\n";
		cout<<"\t    1.入栈           \n";
		cout<<"\t    2.出栈           \n";
		cout<<"\t    3.取栈顶         \n";
		cout<<"\t    0.退出           \n";
		cout<<"\t*********************\n";
		cout<<"\t=====================\n";
		do{
	 		cout<<"\tplease input your operator"<<endl;
			cin>>i;
			//system("cls");
		}while(i!=1&&i!=2&&i!=3&&i!=0);
		switch(i)
		{
	 		case 1:
	 			s1.Push();
				system("pause");
			//	system("cls");
				break;
			case 2:
		 		s1.Pop();
				system("pause");
			//	system("cls");
				break;
			case 3:
				if(-1 ==s1.getTop())
				{
					system("pause");
					//system("cls");
					break;
				}else
		 			cout<<"栈顶元素为:"<<s1.getTop()<<endl;
					system("pause");
				//	system("cls");
					break;
		}
	}while(i!=0);
	return 0 ;
}


