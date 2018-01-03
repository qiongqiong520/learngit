 ///
 /// @file    func.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-02 13:59:44
 ///
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000
#define SWAP(a,b){int tmp;tmp=a;a=b;b=tmp;}

void arr_print(int*);
void arr_select(int*);
void arr_insert(int *a);
int partition(int *a,int left,int right);

