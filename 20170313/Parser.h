 ///
 /// @file    Parser.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-13 23:47:29
 ///
 
#ifndef _PARSER_H_//未定义，当且仅当变量定义为真时执行后续操作，遇到endif时结束执行
#define _PARSER_H_

class Scanner;
class Node;

enum STATUS
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};
class Parser
{
  	public:
  		Parser(Scanner& scanner);
		void Parse();
		Node* Expr();
		Node* Term();
		Node* Factor();
		double Calculate() const;//const_cast<double>用于去除const属性，在全局中该定义为const属性，在某些时刻有需要去除const属性，集科研使用该方法
	private:
		Scanner& scanner_;
		Node* tree_;
		STATUS status_;
};

#endif //_PARSER_H_
