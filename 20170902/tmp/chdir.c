 ///
 /// @file    shdir.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-02 13:19:57
 ///
#include<stdio.h>
#include <unistd.h>
int main(){
	chdir("./tmp");
	printf("current workging directory: %s\n",getcwd(NULL,0));
	return 0;
}
