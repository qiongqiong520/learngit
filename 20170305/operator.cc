 ///
 /// @file    operator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-05 22:30:24
 ///
 
#include <iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main(void)
{
	//成员访问运算符
	string s1="a string ",*p=&s1;
	auto n = s1.size();
	n =(*p).size();//运行p所指对象size成员
	n =p->size();//等价于(*P)>size()
	//条件运算符
	int grade;
	cin>>grade;
	string finalgrade = (grade <60)?"fail":"pass";

	//嵌套条件运算符
	
	finalgrade =(grade>60)?"high pass ":(grade<60)?"fail":"pass";

	//输出表达式中使用条件运算符
	cout<<"(grade<60):"<<((grade<60)?"fail":"pass");//输出pass或fail
	cout<<endl;
	cout<<"(grade>60&&grade<75:):"<< (grade>60&&grade<75)? "low pass":"pass";//输出0或1
	cout<<endl;

	cout<<"(grade<60):"<<(grade<60);//输出1或0
	cout? "fail" : "pass";//根据cout的值是true还是false产生对应的啊字面值
	cout<<endl;
	return 0;
}


