#include<sys/types.h>
#include<dirent.h>
DIR *opendir(const char *name);//打开一个目录
struct dirent *readdir(DIR *dir);//读取目录的一项信息，并返回该项信息的结构体指针
void rewinddir(DIR *dir);//重新定位到目录文件的头部
void seekdir(DIR *dir,off_t offset);//用来设置目录六文件的头部
off_t telldir(DIR *dir);//返回目录六当前的读取位置
int closedir(DIR *dir);//关闭目录文件
