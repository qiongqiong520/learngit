 ///
 /// @file    95-Unique-Binary-Search-Trees-II.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-27 20:22:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Solution{
	public:
		vector<TreeNode *>genrateTrees(int n){
			return createTree(1,n);
		}
		vector<TreeNode *>createTree(int start,int end){
			vecctor<TreeNode *>results;
			if(start>end){
				results.push_back(NULL);
				return results;
			}
			for(int k=start;k<=end;k++){
		 		vector<TreeNode *> left=createTree(start,k-1);
				vector<TreeNode *>right=createTree(k+1,end);
				for(int i=0;i<left.size();i++)
				{
					for(int j=0;j<right.size();i++)
					{
						TreeNode *root=new TreeNode(k);
						root->left = left[i];
						root->right = right[j];
						results.push_back(root);
					}
				}
		}
		return results;
}
};
