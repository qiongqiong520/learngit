 ///
 /// @file    1-two-sum.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-23 23:23:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Solution{
	public:
		vector<int> twoSum(vector<int> &numberx,int target){
			int i,sum;
			vector<int> results;
			map<int,int> hmap;
			for(i =0;i<numbers.size();i++){
				if(!hmap.count(numbers[i])){
					hmap.insert(pair<int,int>(numbers[i],i));
				}
				if(hmap.count(target-numbers[i])){
					int n=hmap[target-numbers[i]];
					if(n<i){
						results.push_back(n+1);
						results.push_back(i+1);
						cout<<n+1<<", "<<i+1<<endl;
						return results;
					}
				}
			}
			return results;
		}
};
