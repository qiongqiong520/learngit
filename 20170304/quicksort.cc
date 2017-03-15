 ///
 /// @file    quicksort.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-04 23:06:33
 ///
 
#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;

typedef struct{
	int *elem;
	int length;
}List;

bool CreatList(List &L)
{
	int k=0,size=0;
	L.length =0;
	printf("your list'size:\n");
	scanf("%d",&size,1);
	L.elem =(int*)malloc(sizeof(int)*size);
	printf("input the list:\n");
	for(int i=0;i<10;i++)
	{
 	 	scanf("%d",&k,1);
		if(k!=-1)
		{
  			L.elem[i]=k;
			L.length++;
		}
	}
	if(!L.length) 
		return false;
}

int QuickSortCore(List &L,int low,int high)
{
 	int pivot = L.elem[low];
	while(low<high&&L.elem[high]>=pivot)
		high--;
	L.elem[low]=L.elem[high];
	while(low<high&&L.elem[low]<=pivot)
		low++;
	L.elem[high]=L.elem[low];
	L.elem[low]=pivot;
	return low;
}

void QuickSortStack(List &L)
{
  	int low=0,high =L.length-1;
	int mid =0;
	stack<int> S;
	if(low<high)
	{
	   	mid = QuickSortCore(L,low,high);
		if(low<mid-1)
		{
	   		S.push(low);
			S.push(mid-1);
		}
		if(mid +1<high)
		{
	  		S.push(mid+1);
			S.push(high);
		}
		while(!S.empty())
		{
 	 		high=S.top();
			S.top();
			low=S.top();
			S.pop();
			mid =QuickSortCore(L,low,high);
			if(low<mid-1)
			{
				S.push(low);
				S.push(mid-1);
			}
			if(mid<high-1)
			{
				S.push(mid+1);
				S.push(high);
			}

		}
	}
}

int main()
{
	List L;
	if(CreatList(L)==false){
		printf("Creat wrong\n");
		exit(0);//在执行循环
	}
	printf("output:\n");
	QuickSortStack(L);
	for(int i=0;i<L.length;i++)
		printf("%d\n",L.elem[i]);
	return 1;
}

