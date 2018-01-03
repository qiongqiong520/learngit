 ///
 /// @file    main.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-02 12:54:53
 ///
#include"func.h"
//fprintf,fscanf 都是真大文本文件进行使用
int main(int agrc,char** argv){
	FLIE* fp;
	int ret;
	stu a[3]={1001,95.3,"lili",1005,90,"zhangsan",1002,91.2,"lisi"};
	stu b[3];
	char c[100];
	char *p;
	char d;
	fp=fopen(argv[1],"r+");
	if(NULL ==fp){
		perror("fopen");
	}
	ret= fwrite(a,sizeof(stu),3,ftp);//二进制方式写结构体
	if(ret>0)
		perror("fwrite");
	fseek(fp,0,SEEK_CUR);
	ret= fputc('A',fp);
	fclose(fp);
	system("pause");
}
