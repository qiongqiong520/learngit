 ///
 /// @file    8.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 16:45:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class A{
	public:
		static void Test1(){cout<<m_iStatic<<endl;
		}
		void Test2(){cout<<"Test"<<endl;
		}
		void Test3(int iTest){
			cout<<iTest<<endl;
		}
		void Test4(){
			cout<<m_iTest<<endl;
		}
	private:
		static int m_iStatic;
		int m_iTest;
};
int A::m_iStatic =0;
int main()
{
	A*pNull =NULL;
	//pNull->Test2();
	//pNull->Test3(13);
	//pNull->Test1();
	pNull->Test4();

	return 0;
}
