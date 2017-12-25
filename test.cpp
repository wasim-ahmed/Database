#include <iostream>

#include <mysql.h>

using namespace std;

MYSQL *connection, mysql;

MYSQL_RES *result;

MYSQL_ROW row;

int query_state;

int main() 
{

cout<<mysql_get_client_info()<<endl;
return 0;

}


