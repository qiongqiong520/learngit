 ///
 /// @file    insert.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-10 23:40:25
 ///
 
#include<stdio.h>


typedef LNode *List;
typedef struct Lnode
{
	Elemtype Data[MAXSIZE];
	int Last;
};

void FindKth(Elemtype x,int i,List Ptrl)
{
	
}

List Insert(ElemType x,int i,List Ptrl)
{
	List s,p;
	if(i==1)
	{
		s=(List)malloc(sizeof(Struc LNode);
		s->Data=x;
		s->Next =PtrL;
		return s;
		}

		p=FindKth(i-1,Ptrl);
		if(p==NULL)
		{
		printf("");
		return  NULL:
		}else{
		s =(List)malloc(sizeof(struct LNode);
		s->Data =s;
		s->Next =p->Next;
		p->Next =s;
		return Ptrl;
		}
		//


