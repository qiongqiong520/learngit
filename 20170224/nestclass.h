 ///
 /// @file    nestclass.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-24 16:33:52
 ///
#ifndef __WD_NESTCLASS_H__
#define __WD_NESTCLASS_H__

#include <iostream>
using std::cout;
using std::endl;
//c++的一种惯用模式：PIMLPL
//作用：1.实现信息隐藏
//2.在升级库的时候能够平滑升级，做到最小的成本来更新
//库的版本，（二进制的兼容性

class Line
{
	class LineImpl;
	public:
		Line(int x1,int y1,int x2,int y2);
		~Line();
		void printLine();
private:
		LineImpl * _pImpl;
};

#endif
