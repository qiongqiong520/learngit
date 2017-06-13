 ///
 /// @file    7533甲流疫情死亡率.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-31 23:30:04
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int diagnosis_data,death;
	double death_rate;
	scanf("%d%d",&diagnosis_data,&death);
	if(diagnosis_data!=0)
	{
		death_rate =(double)death/(double)diagnosis_data;
		printf("%.3f%\n",death_rate*100);
	}
	else
		cout<<"error"<<endl;
	return 0;
}
