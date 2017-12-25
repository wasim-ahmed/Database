#include <iostream>
#include <my_global.h>
#include <mysql.h>
using namespace std;

int main()
{
	MYSQL *con = mysql_init(NULL);
	
	if(con == NULL)
	{
		cout<<mysql_error(con)<<endl;
		exit(1);
	}
	
	if (mysql_real_connect(con,"localhost","root","test",NULL,0,NULL,0) == NULL)
	{
		cout<<mysql_error(con)<<endl;
		mysql_close(con);
		exit(1);
	}
	
	if(mysql_query(con,"create database Company"))
	{
		cout<<mysql_error(con)<<endl;
		mysql_close(con);
		exit(1);
	}
	
	mysql_close(con);
	exit(0);
}


