 ///
 /// @file    B1037在霍格沃资找零钱.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-26 13:12:14
 ///
#include<cstdio>
const int Galleon=17*29;
const int Sickle=29;
int main(){
	int a1,b1,c1;
	int a2,b2,c2;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	int price=a1*Galleon+b1*Sickle+c1;
	int money=a2*Galleon+b1*Sickle+c2;
	int change=money-price;
	if(change <0){
		printf("-");
		change=-change;
	}
	printf("%d.%d.%d\n",change/Galleon,change%Galleon/Sickle,change%Sickle);
	return 0;
}
