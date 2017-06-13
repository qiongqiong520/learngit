 ///
 /// @file    8180均值.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-13 20:31:27
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	 int n;
	 float sample,sum=0;
	 cin>>n;
	 if(n>0&&n<100)
		 for(int i=0;i<n;i++)
		 {
			 cin>>sample;
			 if(sample>=-1000&&sample<=1000)
				 sum+=sample;
		 }
	 else 
		 cout<<"error"<<endl;
	 printf("%.4f\n",sum/n);
	 return 0;
}
