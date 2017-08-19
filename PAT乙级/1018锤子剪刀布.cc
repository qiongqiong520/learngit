 ///
 /// @file    1018锤子剪刀布.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 11:33:36
 ///
 
#include<iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;

int main()
{
 	int n;
	char hand[3]={'B','C','J'};
	cin>>n;
	int count1[3]={0};
	int count2[3]={0};
	int p1[3]={0};
	int p2[3]={0};
	char a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
	if(a=='C'&&b=='C'){
		p1[1]++;p2[1]++;
	}
	if(a=='C'&&b=='J'){
		count1[1]++;p1[0]++;
	 	p2[2]++;
	}
	if(a=='C'&&b=='B'){
		count2[0]++;p1[2]++;p2[0]++;
	}
	if(a=='J'&&b=='C'){
		count2[1]++;
		p1[2]++;
		p2[0]++;
	}
	if(a=='J'&&b=='J'){
		p1[1]++;
		
			if(a=='J'&&b=='C'){
			count2[1]++;
			p1[2]++;
            p2[0]++;
		}
		if(a=='J'&&b=='J'){
			p1[1]++;
			p2[1]++;
		}
		if(a=='J'&&b=='B'){
			count1[2]++;
			p1[0]++;
			p2[2]++;
		}
		if(a=='B'&&b=='C')
		{
			count1[0]++;
			p1[0]++;
			p2[2]++;
		}
		if(a=='B'&&b=='J'){
			count2[2]++;
			p1[2]++;
			p2[0]++;
		}
		if(a=='B'&&b=='B')
		{
			p1[1]++;
			p2[1]++;
		}
	}
	if(a=='J'&&b=='B'){
		count1[2]++;
		p1[0]++;
		p2[2]++;
	}
	if(a=='B'&&b=='C'){
		count1[0]++;
		p1[0]++;
		p2[2]++;
	}
	if(a=='B'&&b=='J'){
		count2[2]++;
		p1[2]++;
		p2[0]++;
	}
	if(a=='B'&&b=='B'){
		p1[1]++;
		p2[1]++;
	}
	}
	cout<<p1[0]<<' '<<p1[1]<<' '<<p1[2]<<endl;
	cout<<p2[0]<<' '<<p2[1]<<' '<<p2[2]<<endl;
	int max1=0,max2=0;
	for(int i=0;i<3;i++){
		if(count1[max1]<count1[i])max1=i;
		if(count1[max1]<count1[i])max1=max1<i?max1:i;

		if(count2[max2]<count2[i])max2=i;
		if(count2[max2]==count2[i])max2=max2<i?max2:i;
	}
	cout<<hand[max1]<<' '<<hand[max2]<<endl;
	return 0;
}
	
