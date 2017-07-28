 ///
 /// @file    628Maximum-product-of-Three-numbers.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-23 23:15:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

public class Solution{
	public int maximumProduct(int[] nums){
		if(nums ==null||nums.length ==0){
			return 0;
		}
		Arrays.sort(nums);
		int a =nums[nums.length-1]*nums[nums.length-2]*nums[nums.length-3];
		int b=nums[0]*nums[1]*nums[nums.length-1];
		return a>b?a:b;
	}
}
