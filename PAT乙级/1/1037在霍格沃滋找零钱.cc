 ///
 /// @file    1037在霍格沃滋找零钱.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 19:59:06
 ///
 
#include <iostream>
#include<string>
using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::swap;
int main(){
int pg,ps,pk,ag,as,ak;
scanf("%d.%d.%d",&pg,&ps,&pk);
scanf("%d.%d.%d",&ag,&as,&ak);
bool isenough;
if(ag!=pg)isenough =ag>pg;
else{
	if(as!=ps)isenough=as>ps;
	else isenough=ak>pk;
}
if(!isenough){
	swap(ak,pk);
	swap(as,ps);
	swap(ag,pg);
}
int rg,rs,rk;
if(ak>=pk)rk=ak-pk;
else{rk =ak+29-pk;as--;}
if(as>=ps)rs = as-ps;
else{rs =as+17-ps;ag--;}
rg=ag-pg;
if(isenough)cout<<rg<<"."<<rs<<"."<<rk<<endl;
else cout<<0-rg<<"."<<rs<<"."<<rk<<endl;
}


