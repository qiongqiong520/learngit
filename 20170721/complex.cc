 ///
 /// @file    complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 23:02:25
 ///
#include<iostream>
#include<math.h>
#include "commplex.h"
complex& complex::operator+(complex& ob){
	//重载函数：复数加法运算
	complex *result=new complex(Re +ob.Re,Im+ob.Im);
	return *result;
}
complex& complex::operator-(complex& ob){
	//重载函数复数减法运算
	complex *result=new complex(Re -ob.Re,Im-ob.Im);
	return *result;
}
complex& complex::operator*(complex& ob){
	//重函数：复数惩罚运算
	complex *result=
		new complex(Re *ob.Re-Im*ob.Im,Im*ob.Re+Re*ob.Im);
	return *result;
}
complex& complex::operator/(complex&){
	//重载函数：复数出发运算
	double d=ob.Re*ob.Re+ob.Im*ob.Im;
	complex *result =new complex((Re*ob.Re+Im*ob.Im)/d,(Im*ob.Re-Re*ob.Im)/d);
	return *result;
}
friend ostream& operator<<(ostream& os,complex & ob){
	//友元函数：重载《《奖复数ob输出到输出流对象os中
	return os<<ob.Re<<(ob.Im>=0.0):"+":"-"<<fabs(ob.Im)<<"i";
}
