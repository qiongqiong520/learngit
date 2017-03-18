 ///
 /// @file    Noncopyable.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 20:28:48
 ///
 
#ifndef _WD_NONCOPYABLE_H_
#define _WD_NONCOPYABLE_H_

namespace wd
{
	class Noncopyable
	{
		protected:
			Noncopyable(){}
			~Noncopyable(){}

		private:
			Noncopyable(const Noncopyable &rhs);
			Noncopyable & operator=(const Noncopyable &rhs);
	};
}//end of namespace wd
#endif
