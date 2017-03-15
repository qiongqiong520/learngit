 ///
 /// @file    scanner.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-13 22:22:17
 ///
#include"scanner.h"

#include <iostream>
using std::cout;
using std::endl;
using std::string;

Scanner::Scanner(const string& buf):_buf(buf),_curPos(0)
{
	Accept();
}

double Scanner::Number() const
{
	return _number;
}

EToken Scanner::Token() const
{
	return _token;
}

void Scanner::SkipWhite()
{
	while(isspace(_buf[_curPos]))
		++_curPos;
}

void Scanner::Accept()
{
	 SkipWhite();
	switch(_buf[_curPos])
	{
	 	case'+':
			 _token=TOKEN_PLUS;
				++_curPos;
			break;
		case'-':
		 	_token=TOKEN_MINUS;
			++_curPos;
			break;
		case'*':
	 		_token=TOKEN_MULTIPLY;
			++_curPos;
			break;
		case'/':
			_token=TOKEN_DIVIDE;
			++_curPos;
			break;
		case'(':
			_token=TOKEN_LPAENTHESIS;
			++_curPos;
			break;
		case')':
			_token=TOKEN_RPARENTHESIS;
			++_curPos;
			break;
		case'0':case'1':case'2':case'3':case'4':
		case'5':case'6':case'7':case'8':case'9':
		case'.':
			 _token=TOKEN_NUMBER;
			char *p;
			_number = strtod(&_buf[_curPos],&p);
			_curPos = p-&_buf[0];
			break;
		case'\0':case'\n':case'\r':case EOF:
							   _token=TOKEN_ERROR;
							   break;
		default:
							   _token = TOKEN_ERROR;
							   break;
	}
}

int main(void)
{
	return 0;
}
