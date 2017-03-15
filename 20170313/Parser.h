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
		double Calculate() const;
	private:
		Scanner& _Scanner;
};

#endif //_PARSER_H_
