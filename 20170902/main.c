 ///
 /// @file    main.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-02 14:18:34
 ///
#include"func.h"
int main()
{
	 int arr[N];
	int i;
	time_t bg,end;
	clock_t cbg,cend;
	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		arr[i]=rand()%100;
	}
	time(&bg);
	//cbg=clock();
	//arr_select(arr);
	//arr_insert(arr);
	arr_quicksort(arr,0,N-1);
	//cend=clock();
	time(&end);
	printf("time=%d\n",end-bg);
	return 0;
}	
