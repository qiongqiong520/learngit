 ///
 /// @file    Noncopyable.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-19 14:41:15
 ///
 
#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

class Noncopyable
{
	protected:
		Noncopyable(){}
		~Noncopyable(){}

	private:
		Noncopyable(const Noncopyable &);
		Noncopyable & operator=(const Noncoyable &);
};

class Node:private Noncopyable
{
	public:
		virtual double Calc() const =0;
		virtual ~Node(){}
};

class NumberNode:public Node
{
	public:
		NumberNode(double number):number_(number){}
		double Calc() const;
	private:
		const double number_;
};

class BinaryNode: public Node
{
	public:
		BinaryNode(Node * left,Node * right)
			:lefr_(left),right_(right){}
		~BinaryNode();
	protected:
		Node* const left_;
		Node* const right_;
};

class UnaryNode:public Node
{
	public:
		UnaryNode(Node* chhild)
			:child_(child){}
		~UnaryNode();
	protected:
		Node* const child_;

};
class AddNode:public BinaryNode
{
	public:
		AddNode(Node* left,Node* right)
			:BinaryNode(left,right){}
		double Calc()const;
};
class SubNode:public BinaryNode
{
	public:
		SubNode(Node* left,Node* right)
			:BinaryNode(left,right){}
		double Calc()const;
};

class MultiplyNode:public BinaryNode
{
	public:
		MultiplyNode(Node* left,Node* right)
			:BinaryNode(left,right){}
		double Calc() const;
};

class DivideNode:public BinaryNode
{
	public:
		DIvideNode(Node* left,Node* right)
			:BinaryNode(left,right){}
		double Calc()const;
};

class UMinusNode:public UnaryNode
{
	public:
		UMinusNode(Node* child)
			:UnaryNode(child ){}
		double Calc()const;
};

#endif//Noncopyable_H_

