 ///
 /// @file    月饼.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 15:09:34
 ///
 
#include <iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;

class MoonPie{
	public:
		float amount;
		float price;
		float per;
};
bool cmp(const MoonPie &rhs1,const MoonPie &rhs2){
	return rhs1.per<rhs2.per;
}
int main(int argc,char* argv[])
{
	int n,max;
	while(cin>>n>>max)
	{
		MoonPie *pie =new MoonPie[n];
		float profit =0;
		for(int i=0;i<n;i++)cin>>pie[i].amount;
		for(int i=0;i<n;i++){
			cin>>pie[i].price;
			pie[i].per=pie[i].price/pie[i].amount;
		}
		std::sort(pie,pie+n,cmp);
		for(int i=n-1;i>0;i--){
			if(max>=pie[i].amount){
				max-=pie[i].amount;
				profit+=pie[i].price;
			}else{
				profit +=max*pie[i].per;
				break;
			}
		}
		cout<<std::fixed<<std::setprecision(2)<<profit<<endl;
	}
	return 0;
}
