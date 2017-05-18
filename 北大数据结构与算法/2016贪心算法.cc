 ///
 /// @file    2016贪心算法.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-16 19:23:44
 ///
#include<stdio.h>
#include<math.h>
#include<String>
#include<map>
#include <iostream>
using tsd::cin;
using std::cout;
using std::endl;

char str[100000+10];
map<string,int>wordmap;
map<string,int>::iterator iter;
int main()
{
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);

	gets(str);
	int k,n=0,k1=0;
	scanf("%d",&k);

	string s=str,word;
	int pre =0,pos=s.find(' ',0);
	int maximum=0;
	while(pos!=string::npos)
	{
		word=s.substr(pre,pos-pre);
		n++;
		if(wordmap.find(word)!=wordmap.end())
		{
			wordmap[word]++;
		}
		else{
			wordmap[word]=1;
		}
		maximum=max(maximum,wordmap[word]);
		pre=pos+1;
		pos=s.find(' ',pre);
	}
	word =s.substr(pre,s.length()-pre);
	n++;
	if(wordmap.find(word)!=wordmap.end())
	{
		wordmap[word]++;
	}
	maximum=max(maximum,wordmap[word]);

	for(iter =wordmap.begin();iter!=wordmap.end();iter++)
	{
		if(iter->Second==maximum)
		{
			k1++;
		}
	}
	if(n>=(maximum -1)*k+k1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
