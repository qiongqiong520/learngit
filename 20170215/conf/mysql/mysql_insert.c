 ///
 /// @file    mysql_delete.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-25 12:52:47
 ///
 //
#include<stdio.h>
#include<mysql/mysql.h>

int main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char* server="localhost";
	char* user ="root";
	char* password ="luke";
	char* database="zhongwen";
	char* query="insert into test2(name) values('中文')";
	int t,r;
	conn =mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
	{
		printf("Error connecting to query:%s\n",mysql_error(conn));
	}else{
		printf("connected...\n");
	}
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query :%s\n",mysql_error(conn));
	}else{
		printf("delete success\n");
	}
	mysql_close(conn);
	return 0;
}
 
