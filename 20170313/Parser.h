 ///
 /// @file    Parser.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-13 23:47:29
 ///
 
#ifndef _PARSER_H_
#define _PARSER_H_

class Scanner;

class Parser
{
	public:
		Parser(Scanner& scanner);
		void Parse();
		double Calculate() const;//const_cast<double>用于去除const属性，在全局中该定义为const属性，在某些时刻有需要去除const属性，集科研使用该方法
	private:
		Scanner& _Scanner;
};

#endif //_PARSER_H_
