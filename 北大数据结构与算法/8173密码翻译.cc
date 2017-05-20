 ///
 /// @file    8173密码翻译.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:17:24
 ///
 
#include <iostream>
#include<cstdio>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

char line[100];
int main()
{
	cin.getline(line,90);
	for(int i=0;line[i];++i)
	{
		if(line[i]>='a'&&line[i]<='y'||line[i]>='A'&&line[i]<='Y')
			++line[i];
		else if(line[i]=='z')
			line[i]='a';
		else if(line[i]=='Z')
			line[i]='A';
	}
	cout<<line;
	return 0;
}

