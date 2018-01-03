 ///
 /// @file    1004成绩排名.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 15:12:47
 ///
 
#include<iostream>
#include<string>
using namespace std;
class student{
	public:
		string name;
		string num;
		int grade;
};

int main(void){
 	int n;
	while(cin>>n){
 		student *stu=new student[n];
		for(int i=0;i<n;i++){
			cin>>stu[i].name>>stu[i].num>>stu[i].grade;
		}

		int h=0,l=0;
		int hi =0,lo=0;
		for(int i=0;i<n;i++)
		{
		 	if(stu[i].grade>=hi){
				hi =stu[i].grade;
				h=i;
			}
			if(stu[i].grade<=lo){
				lo=stu[i].grade;
				l=i;
			}
		}
		cout<<stu[h].name<<' '<<stu[h].num<<endl;
		cout<<stu[l].name<<' '<<stu[l].num<<endl;
	}
	return 0;
}
