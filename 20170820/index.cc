 ///
 /// @file    index.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-20 22:46:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int index(SString S,SSTring T){
	int i=1,j=1;
	while(i<=S[0]&&j<=T[0]){
		if(S[i]==T[j])
		{++i;++j;}//继续比较后序字符
		else
		{i=i-j+2;j=1;}//指针后退重新开始匹配
	}
	if(j>T[0])return i-T[0];
	else return 0;
}
