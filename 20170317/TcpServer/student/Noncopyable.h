/*********************************
 *@fileName: Noncopyable.h
 *@author  : lemon
 *@email   : haohb13@gmail.com
 *@created : 2015-05-08 11:00:46
**********************************/

#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class Noncopyable//禁用值语义
{
public:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &rhs);
	void operator=(const Noncopyable &rhs);
};


#endif

