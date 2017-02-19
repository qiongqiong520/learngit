#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

int main(int argc,char** argv)
{
struct dirent *pDirInfo;
DIR *pDir;
if*argc<2){
pDir = opendir(".");
else{
pDir = opendir(argv[1]);

