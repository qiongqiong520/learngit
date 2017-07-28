 ///
 /// @file    1-8.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 23:34:51
 ///
 
#include <iostream>
#define arraySize 100
#define MAxInt 0x7ffffff

int calc(int T[],int n){
	int ,i,value=1;
	if(n!=0){
		int edge =MaxInt/n/2;
		for(i=1;i<n;i++){
			value *=i*2;
			if(value>edge)return 0;
		}
		value*=n*2;
	}
	T[n]=value;
	cout<<"A[}<<n<<"]="T[n]<<endl;
	return 1;
	}
void main(){
	int A[arraySize];
	int i;
	for(i=0;i<arraySize;i++)
		if(!calc(A,i)){
		cout<<"failed at"<<i<<"."<<endl;
		break;
		}
}

