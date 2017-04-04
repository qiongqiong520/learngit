 ///
 /// @file    人口普查.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 13:37:12
 ///
 
#include <iostream>
#include<string>
using namespace std;
using std::cout;
using std::endl;

int main(int argc,char * argv[])
{
	string name[10000];
	string birthday[100000];
	string oldday = "2014/09/06",youngday ="1814/09/06";
	int n;
	int i=0;
	int max =-1,min =-1;
	int count=0;
	while(cin>>n){
		for(i =0;i<n;i++){
            cin>>name[i]>>birthday[i];
        }
        for(i =0;i<=n;i++){
            if((birthday[i]>="1814/09/06")&&(birthday[i]<="2014/09/06")){
                count++;
                if(birthday[i]>=youngday){
                    youngday =birthday[i];
                    min =i;
                }
                if(birthday[i]<=oldday){
                    oldday =birthday[i];
                    max=i;
                }
            }
        }
			
		if(count>0)
		{
			cout<<count<<' '<<name[max]<<' '<<name[min]<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
