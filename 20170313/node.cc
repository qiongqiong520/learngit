 ///
 /// @file    node.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-13 21:51:49
 ///
#include"node.h"
#include<math.h>
#include <iostream>
using std::cout;
using std::endl;

double NumberNode::Calc() const
{
	return _number;
}

BinaryNode::~BinaryNode()
{
	delete _left;
	delete _right;
}

UnaryNode::~UnaryNode()
{
}

double AddNode::Calc() const
{
	return _left->Calc()+_right->Calc();
}

double SubNode::Calc() const
{
	return _left->Calc()-_right->Calc();
}

double MultiplyNode::Calc() const
{
	return _left->Calc()*_right->Calc();
}

double DivideNode::Calc() const
{
	double divisior=_right->Calc();
	if(divisior!=0)
		return _left->Calc()/_right->Calc();
	else
	{
		cout<<"Error:Divide"<<endl;
		return HUGE_VAL;
	}
}

double UMinusNode::Calc() const
{
	return _child->Calc();
}



