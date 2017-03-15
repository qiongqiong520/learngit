 ///
 /// @file    stl_heap.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-04 10:48:12
 ///
#include<vector>
#include<algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::swap;
void heapAjust(int * arr,int idx,int size)
{
	int i=idx;//
	int j=2*idx+1;//
	int temp=arr[idx];
	while(j<size)
	{
		if(j+1<size&&arr[j]<arr[j+1])
			++j;
		if(arr[j]<=temp)
			break;
		arr[i]=arr[j];
		i=j;
		j=2*i+1;
	}
	arr[i]=temp;
}
void heapSort(int * arr,int size)
{
	for(int idx=size/2-1;idx>=0;--idx)
	{
		heapAjust(arr,idx,size);
	}
	for(int idx=size-1;idx>=0;--idx)
	{
		swap(arr[idx],arr[0]);
		heapAjust(arr,0,idx);
	}
}
int main(void)
{
	int arr[10]={0,3,2,7,8,1,6,5,9,4};
	heapSort(arr,10);
	for(auto &elem:arr)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
	return 0;
}
