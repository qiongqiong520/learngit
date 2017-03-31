 ///
 /// @file    1012数字分类.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 16:52:54
 ///
#include<iostream>
#include<iomanip>
#include<vector>
using std::cin;
using std::vector;

using namespace std;

int main(int argc,char* argv[])
{
	int n;
	while(cin>>n)
	{
		vector<int> num;
		int temp;
		for(int i=0;i<n;i++)
		{
			cin >> temp;
			num.push_back(temp);
		}
		int A1=0,A1c=0,A2=0,A2c=0,A3=0,A3c=0,A4c=0,A5=0;
		float A4=0;
		for(int i=0;i<num.size();i++){
		 	if(num[i]%5==0&&num[i]%2==0){
		 		A1 +=num[i];
				A1c++;
			}
			if(num[i]%5==1){
				if(A2c%2==0)A2+=num[i];
				else A2+=-num[i];
				A2c++;
			}
			if(num[i]%5==2)A3c++;
			if(num[i]%5==3){
				A4+=num[i];
				A4c++;
			}
			if(num[i]%5==4)A5=A5>num[i]?A5:num[i];
		}

		if(A4c!=0)A4/=A4c;
		if(A1c!=0)cout<<A1<<" ";else cout<<"N"<<" ";
		if(A2c!=0)cout<<A2<<" ";else cout<<"N"<<" ";
		if(A3c!=0)cout<<A3c<<" ";else cout<<"N"<<" ";
		if(A4c!=0)cout<<fixed<<setprecision(1)<<A4<<" ";else cout<<"N"<<" ";
		if(A5!=0)cout<<A5;else cout<<"N";
		cout<<endl;
	}
	return 0;
}
