 ///
 /// @file    1008数组元素循环右移问题.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-01 17:38:00
 ///
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void swap(int *list,int i,int j){
	int temp =list[i];
	list[i]=list[j];
	list[j]=temp;
}
int main(int argc,char* argv[]){
	int n,k;
	while(cin>>n>>k){
		int *list=new int[n];
		for(int i=0;i<n;i++)cin>>list[i];
		k=k%n;
		for(int i=0;i<(n-k)/2;i++)
			swap(list,i,n-k-i-1);
		for(int i=0;i<k/2;i++)
			swap(list,n-k+i,n-i-1);
		for(int i=0;i<n/2;i++)
			swap(list,i,n-i-1);
		for(int i=0;i<n-1;i++)
			cout<<list[i]<<' ';
		cout<<list[n-1]<<endl;
	}
	return 0;
}
