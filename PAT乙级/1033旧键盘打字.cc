 ///
 /// @file    旧键盘打字.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 15:18:33
 ///
 
#include <iostream>
#include<string>
#include<unordered_set>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc,char* argv[])
{
	string st,line;
	getline(cin,st);
	cin>>line;
	std::unordered_set<char> hash;
	bool canC=true;
	for(int i=0;i<st.size();i++)
	{
		hash.insert(st[i]);
	}
	if(hash.find('+')!=hash.end())canC=false;
	string ret;
	for(int i=0;i<line.size();i++){
	if(canC){
	if(line[i]>='A'&&line[i]<='Z'){
		if(hash.find(line[i])==hash.end())
			ret.push_back(line[i]);
			}
			else if (line[i]>='a'&&line[i]<='z'){
			if(hash.find(line[i]-32)==hash.end())
			ret.push_back(line[i]);
			}
			else{
			if(hash.find(line[i])==hash.end())
			ret.push_back(line[i]);
			}
		}
		else{
		if(line[i]>='A'&&line[i]<='Z'){
		}
		else if(line[i]>='a'&&line[i]<='z'){
			if(hash.find(line[i]-32)==hash.end())
				ret.push_back(line[i]);
		}
		else{
			if(hash.find(line[i])==hash.end())
				ret.push_back(line[i]);
			}
		}
		}
		cout<<ret<<endl;
		return 0;
	
}

