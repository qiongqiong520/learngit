 ///
 /// @file    complex.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 22:53:56
 ///
#ifndef _complex_h_
#ifndef _complex_h_
#include<iostream>

class complex{
	public:
		complex(){Re =Im=0;}//不带参数的构造函数
		complex(double r){Re=r;Im=0;}//只置实部的构造函数
		complex(double r,double i){Re=r;Im=i;}//只置实部的构造函数
		double getReal(){return Re;}//取复数实部
		double getImag(){return Im;}//取复数虚部
		void setReal(double r){Re=r;}//修改复数实部
		void setImag(double i){Im=i;}//修改复数虚部
		complex& operator=(complex& ob){Re=ob.Re;Im=ob.Im;}//复数赋值
		complex& operator+(complex& ob);//重载函数，复数四则运算
		complex& operator-(complex& ob);
		complex& operator*(complex& ob);
		complex& operator/(complex& ob);
		friend ostream& operator<<(ostream& os,complex& c);//友元函数：重载<<
		private：
			double Re,Im;//复数的实部与虚部
};
#endif

//复数类complex的相关服务的实现放在c++文件complex中
//
//
