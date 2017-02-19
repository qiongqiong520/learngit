#include<mysql/mysql.h>
#include<stdio.h>

int main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char* server = "localhost";
	char* user = "root";
	char* password = "test";
	char* database = "selete * from user";
	char* query="select * from user";
	int t,r;
	conn = mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
	{
		printf("Error connecting to database :%s\n",mysql_error(conn));
	}else{
		printf("connected ...\n");
	}
	t =mysql_query(conn,query);
	if(t)
	{
		printf("Error making query :%s\n",mysql_error(conn,query));
	}else{
		printf("Query made ...\n");
		res = sql_use_result(conn,query);
		if(res)
		{
			while((row =mysql_fetch_row(res))!=NULL)
			{
				//printf("num = %d\n",mysql_num_field(res));//列数
				for(t=0;t<mysql_num_fields(res);t++)
					printf("%s",row[t]);
				printf("\n");
			}

		}
		mysql_free_result(res);
	}
	mysql_close(conn);
	return 0;
}
