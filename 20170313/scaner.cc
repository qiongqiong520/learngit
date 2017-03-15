 ///
 /// @file    scaner.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-13 22:14:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

Scanner
{
	public:
		using string _buf;
		void Accept();
		double Number();
		EToken Token();
		void SkipWhite();
	private:
		string _buf;
		double _number;
		unsigned int _curPos;
		EToken _token;
