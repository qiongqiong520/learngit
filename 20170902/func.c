 ///
 /// @file    func.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-02 14:02:47
 ///
#include"func.h"
void arr_printf(int arr[])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
//选择排序
void arr_select(int *a)
{
	int max_pos,i,j;
	for(i=N;j>1;j--)
	{
		max_pos =0;
		for(j=1;j<i;j++)
		{
			if(a[max_pos]<a[j])
				max_pos=j;
		}
			SWAP(a[max_pos],a[i-1]);
	}
}

//插入排序
void arr_insert(int *a)
{
	int i,j,k;
	int insert_value,insert_pos;
	for(i=1;i<N;i++)//你要插入那些数
	{
		for(j=0;j<i;j++)
		{
			if(a[i]<a[j])//找到要插入位置
			{
				insert_value = a[i];
				insert_pos=j;
				for(k=i-1;k>=j;k--)//移动位置
				{
					a[k+1]=a[k];
				}
				a[insert_pos]=insert_value;
				break;
			}
		}
	}
}
//快排代码
int partition(int *a,int left,int right)
{
	int i,k;
	k=left;
	for(i =left;i<right;i++)
	{
		if(a[i]<a[right])
		{SWAP(a[i],a[k]);
			k++;
		}
	}
	SWAP(a[k],a[right]);
	return k;
}

void arr_quicksort(int *a,int left,int right)
{
	int pivot;
	if(left<right)
	{
		pivot = partition(a,left,right);
		arr_quicksort(a,left,pivot-1);
		arr_quicksort(a,pivot+1,right);
	}
}

