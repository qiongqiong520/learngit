 ///
 /// @file    multimap.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-23 20:42:38
 ///
 //学生成绩录入
 //
#include <iostream>
#include<map>//使用map和mutilmap时许使用此头文件
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;

struct StudentInfo
{
	int id;
	char name[20];
};
struct Student{
	int score;
	StudentInfo info;
};
typedef std::multimap<int,StudentInfo>MAP_STD;

int main()
{
	MAP_STD mp;
	Student st;
	char cmd[20];
	while(cin>>cmd){
		if(cmd[0]=='A'){
			cin>>st.info.name>>st.info.id>>st.score;
			mp.insert(std::make_pair(st.score,st.info));
		}//make_pair生成一个pair<int ,Student>
		else if(cmd[0]=='Q'){
			int score;
			cin>>score;
			MAP_STD::iterator p =mp.lower_bound(score);

		if(p!=mp.begin()){
			--p;
			score=p->first;
			MAP_STD::iterator maxp=p;
			int maxId = p->second.id;
			for(;p!=mp.begin()&&
					p->first ==score;--p){
				if(p->second.id>maxId){
					maxp=p;
					maxId=p->second.id;
				}
			}
			if(p->first ==score){
				if(p->second.id>maxId){
					maxp=p;
					maxId=p->second.id;
				}
			}
			cout<<maxp->second.name<<" "
				<<maxp->second.id<<" "
				<<maxp->first<<endl;
		}
		else cout<<"Nobody"<<endl;
		}
	}
	return 0;
}
