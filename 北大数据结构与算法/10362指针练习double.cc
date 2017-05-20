 ///
 /// @file    10364memcpy.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:55:53
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void Double(int *p,int n)
{
	for(int i=0;i<n;++i)
		p[i]*=2;
}

int main()
{
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

	Double(a[1],6);
	for(int i=0;i<3;++i){
		for(int j=0;j<4;++j)
			cout<<a[i][j]<<",";
		cout<<endl;
	}
	return 0;
}
