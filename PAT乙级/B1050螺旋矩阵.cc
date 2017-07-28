 ///
 /// @file    B1050螺旋矩阵.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-15 09:43:18
 ///
 
#include <iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
bool cmp(const int rhs1,const int rhs2){
	return rhs1>rhs2;
}
int main(int argc,char* argv[]){
	int  N;
	while(scanf("%d",&N)!=EOF){
		int m=0,n=0,min=99999;
		vector<int> nums(N);
		for(int i=0;i<=N;i++)scanf("%d",&nums[i]);
		for(int i=1;i*i<=N;i++){
			int j=N/i;
			m=j;n=i;
		}
	
	sort(nums.begin(),nums.end(),cmp);
	vector<vector<int> >print(m,vector<int>(n,0));
	int k=0,i=0,j=0,l=0,u=0;
	int max=m*n;
	while(k<max){
		for(;j<n;j++)print[i][j]=nums[k++];//right
		i++;u++;j--;if(k>=max)break;
		for(;i<m;i++)print[i][j]=nums[k++];//down
		j--;n--;i--;if(k>=max)break;
		for(;j>=u;i--)print[i][j]=nums[k++];//left
		i--;m--;j++;if(k>=max)break;
		for(;i>=u;i--)print[i][j]=nums[k++];//up
		j++;l++;i++;if(k>=max)break;
	}
	for(int i=0;i<print.size();i++){
 		for(int j=0;j<print[0].size()-1;j++){
			printf("%d",print[i][j]);
		}
		printf("%d\n",print[i][print[0].size()-1]);
	}
}
return 0;
}


