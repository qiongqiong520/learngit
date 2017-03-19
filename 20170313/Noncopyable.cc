 ///
 /// @file    Noncopyable.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-19 15:13:13
 ///
 
#include "Noncopyable.h"
#include<math.h>
#include<iostream>
using std::cout;
using std::endl;

double NumberNode:Calc() const
{
	return number_;
}

BinaryNode::~BinaryNode()
{
	delete left_;
	delete right_;
}

UnaryNode:~UnaryNode()
{
}

double AddNode::Cacl() const
{
	return left_->Calc()+right_->Calc();
}

double SubNode::Calc() const
{
	return left_->Calc()+right_->Calc();
}

double MultipliNode::Calc() const
{
	return left_->Calc()+right_->Calc();
}
double DivideNode::Calc() const
{
	double dividor =right_->Calc();
	if(divisor!=0.0)
		return left_->Calc()/divisor;
	else
	{
		cout<<"Error :Divisor by zero"<<endl;
		return HUGE_VAL;
	}
}

double UMinusNode::Calc() const
{
	return child_->Calc();
}
