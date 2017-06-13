 ///
 /// @file    base.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 18:27:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class BaseClass{
	public:
		BaseClass(){}
		void f(char *s="unkonwn"){
			cout<<"Function f() in BaseClass called from"<<s<<endl;
			h();
		}
	protected:
		void g(char *s ="unkonwn"){
			cout<<"Function g() in BaseClass called from"<<s<<endl;
		}
	private:
		void h()
		{
			cout<<"Function h() in BaseClass\n";
		}
};

class DerivedlLevel:public virtual BaseClass{
	 public:
 		 void f(char *s ="unkonwn"){
	  	cout<<"Function f() in DerivedlLevel called from"<<s<<endl;
		g("DerivedlLevel");
		h("DerivedlLevel");
		}
		void h(char *s ="unkonwn"){
	 	 	cout<<"Function h() in DerivedlLevel called from"<<s<<endl;
		}
};
class Derived2Level1:public virtual BaseClass{
	public: 
		void f(char *s ="unknown"){
		cout<<"Function f() in Derived2Level1 called from"<<s<<endl;
		g("Derived2Level1");
	//	h();//error:BaseClass::h() is not accessible
		}
	
};

class DerivedLevel2: public DerivedlLevel,public Derived2Level1{
	public:
 	 	void f(char *s ="unknown"){
	  		cout<<"Function f() in DerivedLevel2 called from "<<s<<endl;
			g("DerivedLevel2");
			DerivedlLevel::h("DerivedLevel2");
			BaseClass::f("DerivedLevel2");
		}
};

int main()
{
	BaseClass bc;
	DerivedlLevel d111;
	Derived2Level1 d112;
	DerivedLevel2 d12;
	bc.f("main(1)");
	d111.f("main(2)");
	d111.h("main(3)");
	d12.f("main(5)");

	//d12.h();//h()在baseclass中是私有，不能在派生类中访问
	return 0;
}

