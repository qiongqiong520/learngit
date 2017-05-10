 ///
 /// @file    39数组中出现次数超过一半的数字.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 13:46:53
 ///
 
#include <iostream>
#include<cstdio>
using std::cout;
using std::endl;

bool g_bInputInvalid =false;
bool CheckInvalidArray(int* number,int length)
{
	g_bInputInvalid =false;
	if(numbers ==nullptr&&length<=0)
		g_bInputInvalid=true;
	return g_bInputInvalid;
}

bool CheckMoveThandHalf(int* number,int length,int number)
{
	int times=0;
	for(int i=0;i<length;++i)
	{
		if(numbers[i]==number)
			times++;
	}
	bool is MoreThanHalf =true;
	if(times*s<=length)
	{
		g_bInputInvalid =true;
		isMoreeThanHalf=false;
	}
	return isMoreThanHalf;

}
int MoreThanHalfNum_Solution1(int* numbers,int length)
{
	if(CheckInvalidArray(numbers,length))
		return 0;
	int middle =length>>1;
	int start =0;
	int end =length -1;
	int index = Partition(numbers,length,start,end);
	while(index!=middle)
	{
		if(index>middle)
		{
			end = index-1;
			index = Partition(numbers,length,start,end);
		}
		else
		{
			start -index+1;
			index -Partition(numbears,index,strat,end);
		}
	}
	int result =numbers[middle];
	if(!CheckMoreThanHalf(numbers,length,result))
		result =0;
	return result;
}

int MoreThanHalfNum_Solution2(int* numbers,int length)
{
	if(CheckInvalidArray(numbers,length))
		return 0;
	int result =numbers[0];
	int times =1;
	for(int i=1;i<length;++i)
	{
		if(times==0)
		{result =numbers[i];
			times=1;
		}
		else if(numbers[i]==result)
			times++;
		else
			times--;
	}
	if(!CheckMoreThanHalf(numbers,length,result))
		result =0;
	return result;
}

void Test(char* testName,int* numbers,int length

