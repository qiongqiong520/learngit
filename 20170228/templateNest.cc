///
/// @file    templateNest.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-28 21:35:35
///

#include <iostream>
using std::cout;
using std::endl;

template <typename O>
class Outside
{//嵌套类定义
 	public:
 		template<typename I>
	 		class Inside
			{
	 			public:
	 				Inside(I i)
						:_i(i)
					{}
					void display()
					{
						cout<<"Inside."<<_i<<endl;
					}
				private:
					I _i;
			};
	public:
 		Outside(O o)
			:_in(o)
		{}
		void display()
		{
	 		cout<<"Outside.";
			_in.display();
		}
	private:
		Inside<O>_in;
};

int main(void)
{
	Outside<int>::Inside<double> inside(3.5);
	inside.display();

	Outside<int> outside(1);
	outside.display();

	return 0;
}
