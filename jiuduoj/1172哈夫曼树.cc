 ///
 /// @file    1172哈夫曼树.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-18 22:21:43
 ///
 
#include <iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(int argc,char* argv[])
{
 	int n;
	while(cin>>n){
	vector<int>nums;
	int ans=0;
	for(int i=0;i<n;i++){
		int a ;
		cin>>a;
		nums.push_back(a);
	}
	sort(nums.begin(),nums.end());
	int m=nums.size()-1;
	for(int i=0;i<m;i++)
	{
	 	 int curr=*nums.begin()+*(nums.begin()+1);
		ans+=curr;
		nums.erase(nums.begin());
		nums.erase(nums.begin());
		bool isfind =false;
		int size=nums.size();
		for(int i=0;i<size;i++){
	 		if(nums[i]>curr){
	 		 	nums.insert(nums.begin()+i,curr);
				isfind =true;
				break;
			}
		}
		if(!isfind)nums.push_back(curr);
	}
	cout<<ans<<endl;
}
return 0;
}

