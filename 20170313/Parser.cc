 ///
 /// @file    Parser.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-19 15:38:44
 ///
#include<stdio.h> 
#include"Parser.h"

#include"Scanner.h"
#include"Node.h"

#include<cassert>
#include<iostream>
using std::cout;
using std::endl;

Parser::Parser(Scanner& scanner):scanner_(scanner),tree_(0)
{
}
void Parser::Parse()
{
	tree_=Expr();
}
Node* Parser::Expr()
{
	Node* node=Term();
	EToken token=scanner_.Token();
#if 0
	if(token ==TOKEN_PLUS)
	{
	 	scanner_.Accept();
		Node* nodeRight =Expr();
		node =new AddNode(node,nodeRight);
	}
#endif
	if(token==TOKEN_PLUS || token == TOKEN_MINUS)
	{
	 //Expr :=Ter,{('+'|'-")Term}
	 MultipleNode* multipleNode =new SumNode(node);
	 do{
		scanner_.Accept();
		Node* nextNode =Term();
		multipleNode->AppendChild(nextNode,(token==TOKEN_PLUS));
		token =scanner_.Token();
	 }while(token ==TOKEN_PLUS||token== TOKEN_MINUS);
	 node =multipleNode;

	}
	return node;
}

Node* Parser::Term()
{
	Node* node=Factor();
	EToken token = scanner_.Token();
#if 0
	if(token == TOKEN_MULTIPLY)
	{
		scanner_.Accept();
		Node* nodeRight =Term();
		node =new MultiplyNode(node,nodeRight);
	}
#endif

   if(token==TOKEN_MULTIPLY||token ==TOKEN_DIVIDE)
	{
		//Term:=Factor{('*'|'/')Factor
		MultipleNode* multipleNode =new ProductNode(node);
		do{
			scanner_.Accept();
			Node* nextNode = Factor();
			multipleNode->AppendChild(nextNode,(token==TOKEN_MULTIPLY));
			token =scanner_.Token();
		}while(token ==TOKEN_MULTIPLY|token==TOKEN_DIVIDE);

		node=multipleNode;
	}
#if 0
	return node;
	

		scanner_.Accept();
		Node* nodeRight =Term();
		node = new DivideNode(node,nodeRight);
	}
#endif
	return node;
}

Node* Parser::Factor()
{
	Node* node=0;
	EToken token = scanner_.Token();
	if(token == TOKEN_LPAENTHESIS)
	{
	 	scanner_.Accept();
		node = Expr();
		if(scanner_.Token() == TOKEN_RPARENTHESIS)
		{
			scanner_.Accept();
		}else
		{
		 	status_=STATUS_ERROR;
			//Todo:抛出异常
			cout<<"	missing parenthesis"<<endl;
			node=0;
		}
	}
	else if (token ==TOKEN_NUMBER)
	{
	 	node=new NumberNode(scanner_.Number());
		scanner_.Accept();
	}
	else if(token ==TOKEN_MINUS)
	{
		 scanner_.Accept();//accept minus
		node =new UMinusNode(Factor());
	}
	else
	{
	 	status_=STATUS_ERROR;
		//Todo抛出异常
		cout<<"not a valid expression"<<endl;
		node =0;
	}
	return node;
}
double Parser::Calculate() const
{
	assert(tree_!=0);
	return tree_->Calc();
}
