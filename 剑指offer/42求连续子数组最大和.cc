///
/// @file    42求连续子数组最大和.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-05-10 14:21:57
///
#include <cstdio>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if((pData == nullptr) || (nLength <= 0))
	{
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for(int i = 0; i < nLength; ++i)
	{
		if(nCurSum <= 0)
			nCurSum = pData[i];
		else
			nCurSum += pData[i];

		if(nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}

	return nGreatestSum;
} 

void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
	if(testName != nullptr)
		printf("%s begins: \n", testName);

	int result = FindGreatestSumOfSubArray(pData, nLength);
	if(result == expected && expectedFlag == g_InvalidInput)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}


void Test1()
{
	int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}



void Test2()
{
	int data[] = {-2, -8, -1, -5, -9};
	Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}


void Test3()
{
	int data[] = {2, 8, 1, 5, 9};
	Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

void Test4()
{
	Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}



