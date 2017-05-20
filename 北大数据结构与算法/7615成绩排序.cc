 ///
 /// @file    7615成绩排序.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 17:58:16
 ///
 
#include <iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

struct Student{
	char name[30];
	int score;
}students[30];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>students[i].name>>students[i].score;
	for(int i=n-1;i>=0;--i)
		for(int j=0;j<i;++j)
			if(students[j].score<students[j+1].score||
					students[j].score==students[j+1].score &&
			 		strcmp(students[j].name,students[j+1].name)>0){
				Student tmp;
				tmp =students[j];
				students[j]=students[j+1];
				students[j+1]=tmp;
			}
	for(int i=0;i<n;++i)
		cout<<students[i].name<<" "<<students[i].score<<endl;
	return 0;
}
