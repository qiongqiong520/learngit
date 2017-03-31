 ///
 /// @file    personal.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 22:38:41
 ///
#include"personal.h"
#include<iostream>
using std::cout;
using std::endl;
Personal::Personal():namelen(10),citylen(10){
	name =new char[namelen+1];
	city =new char[citylen+1];
}
Personal::Personal(char *ssn,char* n,char *c,int y,long s):namelen(10),citylen(10){
	name =new char[namelen+1];
	city=new char[citylen+1];
	strcpy(SSN,ssn);
	strcpy(name,n);
	year =y;
	salary =s;
}
void Personal::writeToFile(fstream& out)const{
	out.write(SSN,9);
	out.write(name,namelen);
	out.write(city,citylen);
	out.write(reinterpret_cast<const char*>(&year),sizeof(int));
	out.write(reinterpret_cast<const char*>(&salary),sizeof(int));
}
void Personal::readFromFile(fstream& in){
	in.read(SSN,9);
	in.read(name,namelen);
	in.read(city,citylen);
	in.read(reinterpret_cast<char *>(&year),sizeof(int));
	in.read(reinterpret_cast<char *>(&salary),sizeof(int));
}

void Personal::readKey(){
	char s[80];
	cout<<"Enter SSN:";
	cin.getline(s,80);
	strncpy(SSN,s,9);
}
ostream& Personal::writeLegibly(ostream& out){
	SSN[9]=name[namelen]=city[citylen]='\0';
	out<<"SSN="<<SSN<<", name= "<<name
		<<",city = "<<city<<",year="<<year
		<<", salary= "<<salary;
	return out;
}
istream& Personal::readFromConsole(istream& in){
	SSN[9] =name[namelen]=city[citylen]='\0';
	char s[80];
	cout<<"SSN:";
	in.getline(s,80);
	strncpy(SSN,s,9);
	cout<<"Name:";
	in.getline(s,80);
	strncpy(name,s,namelen);
	cout<<"city:";
	in.getline(s,80);
	strncpy(city,s,citylen);
	cout<<"Birthyear:";
	in>>year;
	cout<<"Salary:";
	in>>salary;
	in.ignore();
	return in;
}

