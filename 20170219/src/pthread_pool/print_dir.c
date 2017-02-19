 ///
 /// @file    print_dir.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-17 15:06:57
 ///
 

#include "func.h"

void printdir(char *dir,int depth)
{
	DIR *dp = opendir(dir);
	if(NULL==dp)
	{
		fprintf(stderr,"cannot open directory:%s\n",dir);
		return ;
	}
	chdir(dir);
	struct dirent *entry;
	struct stat statbuf;
	while((entry =readdir(dp))!=NULL)
	{
		stat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(".",entry->d_name)==0||strcmp("..",entry->d_name)==0)
				continue;
			printf("%*s%s/\n",depth,"",entry->d_name);
			printf(entry->d_name,depth+4);
		}
		else
			printf("%*s%s\n",depth,"",entry->d_name);
	}
	chdir("..");
	closedir(dp);
}
int main(int argc,char* argv[])
{
	char *topdir,pwd[2]=".";
	if(argc<2)
		topdir = pwd;
	else
		topdir = argv[1];
	printf("Direntory scan of %s\n",topdir);
	printf(topdir,0);
	printf("done.\n");
	exit(0);
}

