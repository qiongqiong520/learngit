 ///
 /// @file    dictionary.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-23 23:01:08
 ///
 
#ifndef _CPP_DICTIONARY_H_
#define _CPP_DICTIONARY_H_

#include<iostream>
#include<map>
#include<string>
using std::string;

#include<fstream>

using std::endl;
using std::cout;
using std::map;

namespace wd
{
	class Dictionary
	{
		public:

		private:
			map<string,int> _dict;//定义map进行单词存储管理,统计单词词频
			string word;//单词
			int freq;//单词在辞典中出现的词频
	};
}//end of namespace wd

