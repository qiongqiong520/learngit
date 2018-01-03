 ///
 /// @file    1035归并与插入.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 16:36:51
 ///
 
#include <iostream>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;

void insertsort(int *sortarry,int n,int i){
	sort(sortarry,sortarry+1);
	for(int i=0;i<n-1;i++){
		cout<<sortarry[i]<<" ";
	}
	cout<<sortarry[n-1]<<endl;
}

bool issorted(int *sortarry,int k,int n){
	if(k==1)return true;
	for(int i=0;i<n;i+=k){
		if(n-i>=k){
			for(int j=i;i<i+k-1;j++)
				if(sortarry[j]>sortarry[j+1])
					return false;
		}
		else{
			for(int j=i;j<n-1;j++)
				if(sortarry[j]>sortarry[j+1])
					return false;
			
		}
	}
		return true;
}

void mergesortarry(int *sortarry,int n)
{
	int count =0 ,index=0;
	for(int i=0;i<n/2;i++){
		if(sortarry[i]>sortarry[i+1])
		{
			index = i+1;break;
		}
	}
	while(!issorted(sortarry,index,n))index/=2;
	count=n/(index*2);
	for(int i=0;i<count;i++){
		int first =i*index*2;
		int last =(i+1)*index*2;
		sort(sortarry+first,sortarry+last);
	}
	for(int i=0;i<n-1;i++){
		cout<<sortarry[i]<<" ";
	}
	cout<<sortarry[n-1]<<endl;
}
int main(int argc,char* argv[]){
	int n;
	while(cin>>n){
		int *init = new int[n];
		int *sortarry=new int[n];
		for(int i=0;i<n;i++)cin>>init[i];
		for(int i=0;i<n;i++)cin>>sortarry[i];
		bool isInsertion =true;
		int in;
		for(in =0;in<n-1;in++){
			if(sortarry[in]>sortarry[in+1]){
	 			for(int j=in+1;j<n;j++){
	 				if(init[j]!=sortarry[j]){
		 				isInsertion =false;
						break;
					}
				}
				break;
			}
		}
		if(isInsertion){
			cout<<"Insertion Sort"<<endl;
			insertsort(sortarry,n,in+2);
		}
		else{
			cout<<"Merge Sort "<<endl;
			mergesortarry(sortarry,n);
		}
	}
	return 0;
}
