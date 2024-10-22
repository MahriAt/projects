#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <conio.h>

#define HOST "127.0.0.1"
#define USER "root"
#define PW  "MySQL_password"
#define DATABASE "Contacts"
#define PORT 3306
#define PASSWORD 12345

using namespace std;

MYSQL *conn;
MYSQL_RES *re_set;
MYSQL_ROW row;
stringstream stmt;
const char *q;
string query;

class contacts {
    int id;
    string name;
    string surname;
    string number;
public:
    void add();
    void update();
    void delete_contact();
    void search();
    void display();
};

void contacts::add()
{
    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Phone number: ";
    cin >> phone;
    stmt.str("");
    stmt << "INSERT INTO Contacts(name,surname,phone) VALUES(""<< name <<"," << surname << "," << phone << "");";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn,q);
    res_set = mysql_store_result(conn);
    if(!(res_set))
        cout << endl << endl << "Yuor Contact Saved Successfully" << endl << endl << endl;
    else
        cout << endl << endl << "Entry ERROR" << endl << "Contact Technical Support" << endl << endl << endl;
}

void contacts::update()
{
    char choice;
    cout << "Enter id of the contact: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT name,surname,phone FROM Contacts WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn,q);
    res_set = mysql_store_result(conn);
    if((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Name: " << row[0] << endl;
        cout << "Surname: " << row[1] << endl;
        cout << "Phone: " << row[2] << endl;
        cout << "Do you want to update the number [y/n]: ";
        cin >> choice;
        if ( choice == 121 || coice == 89)
        {
            cout << "Enter new number: ";
            cin >> phone;
            stmt.str("");
            stm << "UPDATE Contacts SET phone = " << phone << "WHERE id = " << id << ";";
            res_set = mysql_store_result(conn);
            if (!(res_set))
                cout << endl << endl << "Contact Updated Seccessfully" << endl << endl << endl;
            else
                cout << endl << endl << "ERROR" << endl << "Contact Technical Suppot" << endl << endl << endl;  
        }
        else {
            cout << "no changes Made";
        }
    }
    else
        cout << "No contact found!!" << endl;
}

void delete_contact()
{
    cout << "Enter id of the contact to delete: ";
    cin >> id;
    stmt.str("");
    stmt << "DELETE FROM Contacts WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << "The contact deleted." << endl;
}

void contacts::search()
{
    cout << "Enter Contac id: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT * FROM Contacts WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn,q);
    res_set = mysql_store_result(conn);
    if((row = myysql_fetch_row(res_set)) != NULL)
    {
        cout << "Contact's information with id " << row[0] << endl;
        cout << "Name: " << row[1] << endl;
        cout << "surname: " << row[2] << endl;
        cout << "Phone number: " << row[3] << endl;
    }
    else 
        cout << "No contact found" << endl;
}

void contacts::display()
{
    query = "SELECT * FROM Contacts;";
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    while((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Contact " << row[0] << " : " << endl;
        cout << "Name: " << row[1] << endl;
        cout << "Surname: " << row[2] << endl;
        cout << "Phone number: " << row[3] << endl;
        cout << endl << endl << endl;
    }
}

void menu()
{
    int c;
    contacts cont;
    while(c != 6)
    {
        cout << "**************************************" << endl;
        cout << "              CONTACTS MENU" <<endl;
        cout << "**************************************" << endl;
        cout << "1. ADD NEW CONTACT" << endl;
        cout << "2. UPDATE THE PHONE NUMBER" << endl;
        cout << "3. DELETE CONTACT" << endl;
        cout << "4. SEARCH BY ID" << endl;
        cout << "5. DISPLAY ALL CONTACTS" << endl;
        cout << "6. EXIT";
        cin >> c;
        switch (c)
        {
        case 1:
            cont.add();
            break;
        case 2:
            cont.update();
            break;
        case 3:
            cont.delete_contact();
            break;
        case 4:
            cont.search();
            break;
        case 5:
            cont.display();
            break;
        case 6:
            break;  
        default:
            cout << "Wrong Input" << endl << "Invalid input" << endl;
            break;
        }
    }
}

void pass()
{
    int num = 0;
    cout << "Enter password: ";
    for(int i = 0; i < 5; i++)
    {
        num = num*10+(getch()-48);
        cout << "*";
    }
    if(num == PASSWORD){
        cout <<endl << endl << "Correct Password" << endl << endl;
        cout << "Press any key ";
        getch();
    }
    else
    {
        cout << endl << endl << "Password incorrect" << endl <<endl;
        cout << "Press any key ";
        getch();
        exit(1);
    }
    return;
}

int main (){
    pass();
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PW, DATABASE, PORT, NULL, 0);
    int choice;
    if(conn)
    {
        while(1)
        {
            system("cls");
            menu();
        }
    }
    else
    {
        system("cls");
        cout << "Error while connection to database" << endl << "Contact technical support" << endl;
        getch();
    }
    return 0;
}