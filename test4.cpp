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
	}
	
	if(mysql_real_connect(con,"localhost","wasim","wasim","Company",0,NULL,0) == NULL)
	{
		finish_with_error(con);
	}
	
	if(mysql_query(con,"select * from Mahindra"))
	{
		finish_with_error(con);
	}
	
	MYSQL_RES *result = mysql_store_result(con);
	
	if(result == NULL)
	{
		finish_with_error(con);
	}
	
	int num_fields = mysql_num_fields(result);
	
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	
	while((row = mysql_fetch_row(result)))
	{
		for (int i=0;i < num_fields;i++ )
		{
			
			if(i == 0)
			{
				while(field = mysql_fetch_field(result))
				{
					cout<<field->name;
					cout<<"\t";
				}
				cout<<endl;
			}
			
			cout<<row[i]<<"\t";
		}
		
	}
	cout<<endl;
	mysql_free_result(result);
	mysql_close(con);
	
	exit(0);
	
 }