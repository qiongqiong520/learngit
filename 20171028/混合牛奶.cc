 ///
 /// @file    混合牛奶.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-10-28 10:58:36
 //
#include<stdio.h>
int main(){
	FILE *in=fopen("milk.in","r"),*out=fopen("milk.out","w");
	long milk,person,i,j,money=0;
	long farmer[5000][2],t;
	fscanf(in,"%ld %ld",&milk,&person);
	for(i=0;i<person;i++)
		fscanf(in,"%ld %ld",&farmer[i][0],&farmer[i][1]);
	for(i=0;i<person;i++)
		for(j=0;j<person-i ;j++)
			if(farmer[j ][0]>farmer[j+1][0])
			{
				t=farmer[j][0];farmer[j][0]=farmer[j+1][0];farmer[j+1][0]=t;
				t=farmer[j][1];farmer[j][1]=farmer[j+1][1];farmer[j+1][1]=t;
			}
	for(i=0;milk>0;i++)
		 if(milk-farmer[i][1]>0)
		{
		 	milk -=farmer[i][1];
			money+=farmer[i][0]*farmer[i][1];
		}
		else{
			money+=milk*farmer[i][0];
			milk=0;
		}
	fprintf(out,"%ld\n",money);
	fclose(in);
	fclose(out);
	return 0;
}
