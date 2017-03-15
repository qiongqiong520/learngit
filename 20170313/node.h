 ///
 /// @file    node.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-13 21:34:31
 ///
 
#ifndef _NODE_H_
#define _NODE_H_

class Noncopyvable
{
	protected:
		Noncopyvable(){}
		~Noncopyvable(){}
	private:
		Noncopyvable(const Noncopyvable &);
		Noncopyvable &operator =(const Noncopyvable &);
};
class Node:private Noncopyvable
{
  	public:
  		virtual double Calc() const =0;
		virtual ~Node(){}
};

class NumberNode:public Node
{
  	public:
 		NumberNode(double number):_number(number){}
		double Calc() const;
	private:
		 double const _number;
};

class BinaryNode:public Node
{
  	public:
		BinaryNode(Node* left,Node* right):_left(left),_right(right)
	{}
		~BinaryNode();
	private:
 		Node* const _left;
		Node* const _right;
};

class UnaryNode :public Node
{
 	public:
 		UnaryNode(Node* child):_child(child)
		{}
		~UnaryNode();
protected:
 		Node* const _child;
	};

class AddNode:public BinaryNode
{
 	public:
 		AddNode(Node* left,Node* right):BinaryNode(left,right){}
		double Calc() const;
};

class SubNode:public BinaryNode
{
	 public:
 		SubNode(Node* left,Node* right):BinaryNode(left,right){}
		double Calc() const;
};

class MultiplyNode:public BinaryNode
{
	public:
		MultiplyNode(Node* left,Node* right):BinaryNode(left,right){}
		double Calc() const;
};

class DivideNode:public BinaryNode
{
	public:
		DivideNode(Node* left,Node* right):BinaryNode(left,right){}
		double Calc() const;
};

class UMinusNode:public UnaryNode
{
	public:
		UMinusNode(Node* child)
			:UnaryNode(child){}
		double Calc() const;
};


#endif//_NODE_H_
