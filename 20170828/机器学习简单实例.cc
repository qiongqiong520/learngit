 ///
 /// @file    机器学习简单实例.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-28 13:04:21
 ///
 
#include <iostream>
using namespace std;
void input(int &oper,const bool meth)
{//meth为true则只为判断1，为false则判断为1或0
	while(true){
		cin>>oper;
		if(meth&&oper==1)
			break;
		else if(oper==0||oper==1)
			break;
		cout<<"输入错误，请重新输入."<<endl;//判断参数
	cin.sync();//避免极端输入导致死循环
	cin.clear();
	}
}
int main(void){
	cout<<"1+1=2吗？那要看你怎么教我了，不要惊讶我会学习的"<<endl;
	int ladd,radd,aprs,rcnt(0),wcnt(0);//定义输入与结果，正确次数与错误次数
	cout<<"开始学习......"<<endl;
	for(int i=0;i!=10;++i)
	{
		cout<<"参数1（必须是1）:"<<flush;//提示输入参数
		input(ladd,true);
		cout<<"参数2（必须是1):"<<flush;
		input(radd,true);
		cout<<"结果:"<<(ladd+radd)<<endl;//输出结果
		cout<<"您对这满意吗（满意输入1，不满意输入0):"<<flush;//评价等级
		if(aprs)//判断用户评价
			++rcnt;
		else
			++Wcnt;
		cout<<"正确次数:"<<rcnt<<"错误次数:"<<wcnt<<endl;//错误次数
		}
	if(rcnt>wcnt)//判断学习结果
		cout<<"主人请告诉我1+1=2"<<endl;
	else
		if(rcnt<wcnt)
			cout<<"主任请告诉我1+1!=2"<<endl;
		else
			cout<<"我不明白主人时什么意思"<<endl;
	int term;//退出部分
	cout<<"您对我现在的表现满意吗？满意请输入1不满意请输入0:"<<flush;
	input(term,false);
	if(term)
		cout<<"谢谢你我会继续努力学习"<<endl;
	else
		cout<<"谢谢我会继续努力学习D"<<endl;
	return 0;
}
