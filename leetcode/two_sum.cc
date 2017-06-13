 ///
 /// @file    two_sum.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 10:59:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Solution{
	public:
		vector<int> twoSum(vector<int>& nums,int target){

public int[] twoSum(int[] nums,int target){
	Map<Integer ,Integer>map =new HashMap<>();
	for(int i=0;i<nums.length;i++){
		int complement =target-nums[i];
		if(map.containsKey(complement)){
			return new int[]{map.get(complement),i};
		}
		map.put(nums[i],i);
	}
	throw new IllegalArgumentException("No two sum solution");
}
