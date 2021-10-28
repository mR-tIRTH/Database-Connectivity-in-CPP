
#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
using namespace std;

class database
{
public:

    void insert_record()
    {
        system("cls");
        MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.43.136","admin","tirthesh21","inventory",0,NULL,0);
        if(conn)
        {

            int qstate=0,item_code,item_price,item_quantity,n;
            cout<<"\n\n\t\t\t\tHow Many Records Do You Want To Enter?:";
            cin>>n;
            string item_name;
            for(int i=1; i<=n; i++)
            {
                cout<<"\t\t\t\t\tInsertion :"<<i<<endl;
                cout<<"\t\t\t\tPlease Enter Item Code:";
                cin>>item_code;
                cout<<"\t\t\t\tPlease Enter Item Name:";
                cin>>item_name;
                cout<<"\t\t\t\tPlease Enter Item Price:";
                cin>>item_price;
                cout<<"\t\t\t\tPlease Enter Item Quantity:";
                cin>>item_quantity;

                stringstream ss;
                ss << "INSERT INTO insert_operation1(item_code, item_name,item_price,item_quantity) VALUES('" << item_code << "','" << item_name << "','" << item_price <<"','"<<item_quantity<<"')";

                string query = ss.str();
                const char* q = query.c_str();
                qstate = mysql_query(conn, q);
            }
            if(qstate == 0)
            {
                cout << "Record Inserted successfully..." << endl;

            }
            else
            {
                cout << "Insert Error" << mysql_error(conn) << endl;
            }
        }
        else
        {
            cout << "Connection Error" << endl;
        }




    }
    void deleterecord()
    {
        string dummy;
        string val;
        MYSQL* conn;
        MYSQL* conn2;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.43.136","admin","tirthesh21","inventory",0,NULL,0);
        conn2=mysql_init(0);
        conn2=mysql_real_connect(conn,"192.168.43.136","admin","tirthesh21","inventory",0,NULL,0);
        if(conn)
        {
            string item_name;
            int quantity;
            cout << "Enter Name : ";

            cin >> item_name;

            MYSQL* conn3;
            MYSQL_ROW row;
            MYSQL_RES* res;
            conn3=mysql_init(0);
            conn3=mysql_real_connect(conn3,"192.168.43.136","admin","tirthesh21","inventory",0,NULL,0);
            if(conn3)
            {
                int qstate = mysql_query(conn3, "SELECT item_name FROM insert_operation1");

                if(!qstate)
                {
                    res = mysql_store_result(conn3);
                    while(row = mysql_fetch_row(res))
                    {

                        val=row[0];

                    }
                }
            }

            if(val==item_name){
            int qstate1 = 0;

            stringstream ss1;
            ss1 << "DELETE FROM insert_operation1" << " WHERE item_name = '" << item_name << "'";

            string query1 = ss1.str();

            const char* q1 = query1.c_str();
            qstate1 = mysql_query(conn2, q1);
            if(qstate1 == 0)
            {
                cout << "Record Deleted..." << endl;
            }
            else
            {
                cout << "There is no such record exist!!!!" << mysql_error(conn) << endl;
            }
        }else{
        cout<<"Not available"<<endl;

        }
        }

    }
    void view_all_records()
    {

        string dummy;
        system("cls");
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* res;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.43.136","admin","tirthesh21","inventory",0,NULL,0);
        if(conn)
        {
            int qstate = mysql_query(conn, "SELECT item_code, item_name, item_price,item_quantity FROM insert_operation1");

            if(!qstate)
            {
                res = mysql_store_result(conn);
                cout<<"\n\n\n\t\t\t\t\t\t\tVIEW TABLE\n\t\t\t\t\t\t\t----------";
                cout << "\n\n\n\n\t\t\t\tID" <<"\t | \t" << "NAME" <<"\t | \t" << "PRICE" <<"\t | \t" << "QUANTITY" << endl << endl;
                cout<<"\t\t\t\t--------------------------------------------------------"<<endl<<endl;
                while(row = mysql_fetch_row(res))
                {

                    cout <<"\t\t\t\t"<< row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] << endl << endl;

                }
            }
        }


    }
    void update_records()
    {
        system("cls");
        string value;
        MYSQL* conn;
        MYSQL* conn2;
        MYSQL_ROW row;
        MYSQL_RES* res;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.43.136","admin","tirthesh21","inventory",0,NULL,0);
        conn2=mysql_init(0);
        conn2=mysql_real_connect(conn,"192.168.43.136","admin","tirthesh21","inventory",0,NULL,0);
        if(conn)
        {

            string item_name;
            int item_quantity;
            cout << "Enter Name : ";
            cin >> item_name;

            MYSQL* conn3;
            MYSQL_ROW row;
            MYSQL_RES* res;
            conn3=mysql_init(0);
            conn3=mysql_real_connect(conn3,"192.168.43.136","admin","tirthesh21","inventory",0,NULL,0);
            if(conn3)
            {
                int qstate = mysql_query(conn3,"SELECT item_name FROM insert_operation1");

                if(!qstate)
                {
                    res = mysql_store_result(conn3);
                    while(row = mysql_fetch_row(res))
                    {

                        value=row[0];

                    }
                }
            }
            if(value==item_name)
            {
                cout << "Enter Quantity : ";
                cin >> item_quantity;

                int qstate1 = 0;

                stringstream ss1;
                ss1 << "UPDATE insert_operation1 SET item_quantity = item_quantity + " << item_quantity << " WHERE item_name = '" << item_name<<"'";

                string query1 = ss1.str();

                const char* q1 = query1.c_str();
                qstate1 = mysql_query(conn2, q1);
                if(qstate1 == 0)
                {
                    cout << "Record Updated..." << endl;
                }
                else
                {
                    cout << "Insert Error" << mysql_error(conn) << endl;
                }
            }
            else
            {
                cout<<"Not available"<<endl;
            }
        }

    }


};


int main()
{

    database obj1;
    int flag=0;
    do
    {
        char choice;
        system("cls");
        cout<<"\n\n\t\t\t\t\t\t     INVENTORY\n";
        cout<<"\t\t\t\t\t\t     ---------\n";
        cout<<"\n\n\t\t\t\t\t***************************************"<<endl<<endl;
        cout<<"\t\t\t\t\t\t1.INSERT RECORDS"<<endl<<endl;
        cout<<"\t\t\t\t\t\t2.DELETE RECORDS"<<endl<<endl;
        cout<<"\t\t\t\t\t\t3.VIEW ALL RECORDS"<<endl<<endl;
        cout<<"\t\t\t\t\t\t4.UPDATE RECORDS"<<endl<<endl;
        cout<<"\t\t\t\t\t\t5.EXIT"<<endl<<endl;
        cout<<"\t\t\t\t\t***************************************"<<endl<<endl;
        cout<<"\t\t\t\t\tPLEASE ENTER YOUR CHOICE:";
        cin>>choice;

        if(choice=='1')
        {
            obj1.insert_record();
        }
        else if(choice=='2')
        {

            obj1.deleterecord();
        }
        else if(choice=='3')
        {
            obj1.view_all_records();
        }
        else if(choice=='4')
        {
            obj1.update_records();
        }
        else if(choice=='5')
        {
            break;
        }
        else
        {
            cout<<"Entered invalid data"<<endl;
        }
        cout<<" CONTINUE = 1 / EXIT = 0 :";
        cin>>flag;
    }
    while(flag==1);
    return 0;
}


