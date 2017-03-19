 ///
 /// @file    scanner.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-13 22:17:09
 ///
 

#ifndef _SCANNER_H_
#define _SCANNER_H_
#include<string>
enum EToken
{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_DIVIDE,
	TOKEN_MULTIPLY,
	TOKEN_LPAENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN
};

class Scanner
{
  	public:
 	 	Scanner(const std::string& buf);
		void Accept();
		double Number() const;
		EToken Token() const;
	private:
	   	void SkipWhite();
		const std::string buf_;
		unsigned int curPos_;
		EToken token_;
		double number_;
};
#endif //_SCANNER_H_



