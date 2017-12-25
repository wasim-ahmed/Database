#include <iostream>
#include <mysql.h>
#include <my_global.h>
using namespace std;

void finish_with_error(MYSQL *con)
{
	cout<<mysql_error(con)<<endl;
	mysql_close(con);
	exit(1);
}

int main()
{
		MYSQL *con = mysql_init(NULL);
		
		if(con == NULL)
		{
			cout<<mysql_error(con)<<endl;
			exit(1);
		}
		
		if(mysql_real_connect(con,"localhost","wasim","wasim","Company",0,NULL,0) == NULL)
		{
			finish_with_error(con);
		}
		
		if(mysql_query(con,"drop table if exists Mahindra"))
		{
			finish_with_error(con);
		}
		
		if(mysql_query(con,"create table Mahindra(ibu TEXT,revenue INT)"))
		{
			finish_with_error(con);
		}
		
		if(mysql_query(con,"insert into Mahindra values('IES',100000)"))
		{
			finish_with_error(con);
		}
		
		if(mysql_query(con,"insert into Mahindra values('BFSI',10000000)"))
		{
			finish_with_error(con);
		}
		
		mysql_close(con);
}