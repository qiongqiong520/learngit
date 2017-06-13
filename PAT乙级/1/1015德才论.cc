 ///
 /// @file    1015德才论.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-02 23:10:05
 ///
 
#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
class student{
	public:
		int ID;
		int fgrade;
		int sgrade;
		int total;
	public:
		bool operator<(const student &rhs)const{
			if(rhs.total!=total)return total>rhs.total;
			else{
				if(rhs.fgrade!=fgrade)return fgrade>rhs.fgrade;
				else return ID<rhs.ID;
			}
		}
};
int main(int argc,char* argv[]){
 	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	vector<student> s1;
	vector<student> s2;
	vector<student> s3;
	vector<student> s4;
	student temp;
	for(int i=0;i<n;i++){
	 	scanf("%d %d %d",&temp.ID,&temp.fgrade,&temp.sgrade);
		temp.total=temp.fgrade+temp.sgrade;
		int f=temp.fgrade;
		int s=temp.sgrade;
	if(f>=l&& s>=1){
	 	if(f>=h&&s>=h)
			s1.push_back(temp);
		else if(f>=h&& s<h)
			s2.push_back(temp);
		else if(f<h&&s<h&&f>=s)
			s3.push_back(temp);
		else
 			s4.push_back(temp);
        }
	}
sort(s1.begin(),s1.end());
sort(s2.begin(),s2.end());
sort(s3.begin(),s3.end());
sort(s4.begin(),s4.end());

int ans=s1.size()+s2.size()+s3.size()+s4.size();
printf("%d\n",ans);
for(int i=0;i<s1.size();i++)printf("%d %d %d\n",s1[i].ID,s1[i].fgrade,s1[i].sgrade);
for(int i=0;i<s2.size();i++)printf("%d %d %d\n",s2[i].ID,s2[i].fgrade,s2[i].sgrade);
for(int i=0;i<s3.size();i++)printf("%d %d %d\n",s3[i].ID,s3[i].fgrade,s3[i].sgrade);
for(int i=0;i<s4.size();i++)printf("%d %d %d\n",s4[i].ID,s4[i].fgrade,s4[i].sgrade);
return 0;
}


