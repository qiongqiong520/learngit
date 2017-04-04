 ///
 /// @file    完美数列.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 14:21:42
 ///
#include<stdio.h>
#include<algorithm>
#include <iostream>
using std::cin;
using std::string;
using std::cout;
using std::endl;


int main(int argc,char* argv[])
{
	int n;
	double p;
	while(scanf("%d %lf",&n,&p)!=EOF){
		double nums[100002];
		for(int i=0;i<n;i++)scanf("%lf",&nums[i]);
		std::sort(nums,nums+n);
		int length=0;
		for(int i=0;i<n;i++){
	 		for(int j=i+length-1;j<n;j++){
	 			if(nums[j]<=nums[i]*p){
					length=length>j-i+1?length:j-i+1;
				}
				else break;
			}
		}
		printf("%d",length);
	}
	return 0;
}
