 ///
 /// @file    insert2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 22:24:06
 ///
 
#include <iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
int main(void)
{
 	pair<int ,string>sz[4]={
		pair<int,string>(1,"a"),
		pair<int,string>(2,"G"),
		pair<int,string>(3,"C"),pair<int,string>(5,"X")};
	pair<int,string>t(1,"X");

	cout<<"希望将x插入map中,结果:"<<endl;
	map<int,string>obM(sz,sz+4);
	map<int,string>::iterator p = obM.begin();
	p++;
	map<int,string>::iterator q=obM.insert(p,t);
	map<int,string>::iterator itM;
	for(itM=obM.begin();itM!=obM.end();itM++)
	{
		cout<<(*itM).first<<" "<<(*q).second<<endl;
	
	}
	cout<<"返回"<<(*q).first<<" "<<(*q).second<<endl;
return 0;	
}
