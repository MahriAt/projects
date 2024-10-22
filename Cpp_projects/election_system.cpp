#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <conio.h>

#define HOST "127.0.0.1"
#define USER "root"
#define PW  "MySQL_password"
#define DATABASE "election_DB"
#define PORT 3306

using namespace std;

MYSQL * conn;
MYSQL_RES *res_set;
MYSQL_ROW row;
stringstream stmt;
const char *q;
string query;

class citizen
{
    int national_id;
    string name;
    string surname;
    int age;
    string city;
public:
    void info();
    void vote();
};

typedef struct
{
    int id;
    int vote;
}c_vote;

void citizen::info()
{
    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Age: ";
    cin >> age;
    cout << "City: ";
    cin >> city;
    cout << "National Id number: ";
    cin >> national_id;
    stmt.str("");
    stmt << "Select * from members where national_id  = " << national_id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
        cout << "You have already voted. Thank you for coming!" << endl << endl;
    }
    else
    {
        stmt << "INSERT INTO citizens(name,surname,age,city,national_id) VALUES(""<< name <<"," << surname << "," << age <<"," << city << "," << national_id << "");";
        query = stmt.str();
        q = query.c_str();
        mysql_query(conn,q);
        res_set = mysql_store_result(conn);
        if(!(res_set))
            cout << endl << endl << "Your Informations Have Saved Successfully" << endl << endl << endl;
        else
            cout << endl << endl << "Entry ERROR" << endl << "Contact Technical Support" << endl << endl << endl;
    }
    system("cls");
}

void citizen::vote()
{
    cout << "In accordance with U.S. privacy laws and regulations ensuring the anonymity of elections, your vote is confidential and will remain completely private."<< endl <<"We are committed to safeguarding your personal data throughout the entire voting process." << endl << endl;
    cout << "1.Donald Trump" << endl;
    cout << "2.Kamala Harris" <<endl;
    cout << "Please enter your vote: ";
    cin >> vote;
    if(vote == 1 || vote == 2)
        cout << "Thank you for yor vote!" << endl;
    else
    {
        cout << "Please write a number 1 or 2"<< endl;
        cin >> vote;
    }
}

void condidates (void)
{
    int menu_choice;
    cout << "**************************************" << endl;
    cout << "              CONDIDATES" << endl;
    cout << "**************************************" << endl;
    cout << "1.Donald Trump" << endl;
    cout << "2.Kamala Harris" <<endl;
    cout << "Please choise a number of condidate to learn more: ";
    cin >> menu_choice;
    while (menu_choice != 1 || menu_choice != 2)
    {
        cout << "To choise candidate write 1 or 2" << endl; 
        cin >> menu_choice;
    }
    switch (menu_choice)
    {
        case 1:
            cout << "Donald Trump" << endl <<endl << "Under our leadership, the United States will be respected again. No nation will question our power. No enemy will doubt our might." <<endl << "Our borders will be totally secure. Our economy will soar. We will return law and order to our streets, patriotism to our schools," <<endl
                 << "and importantly, we will restore peace, stability and harmony all throughout the world." <<endl <<endl << "Biography" <<endl <<endl;
            cout << "Trump was born in Queens, New York, in 1946. He attended Fordham University before transferring to the"<<endl
                 << "Wharton School of Finance at the University of Pennsylvania, where he received a B.S. in economics in 1968." <<endl <<endl
                 << "After graduation, Trump joined his family's company, Elizabeth Trump & Son. He took control of the company in 1971" <<endl
                 << "and later renamed it the Trump Organization. He was involved in a variety of real estate and other business" <<endl
                 << "ventures in the following years. From 2004 until 2015, Trump hosted and served as executive producer of The" <<endl
                 << "Apprentice on NBC." << endl <<endl
                 << "In 1999, Trump ran as a Reform Party presidential candidate; he withdrew from the race in February 2000."<<endl
                 << "Between 1987 and 2012, he changed his official party affiliation five times, registering most recently as a Republican" <<endl
                 << "in April 2012" <<endl <<endl
                 << "Trump declared his candidacy for the 2016 presidential election on June 16, 2015, and officially received the" <<endl
                 << "nomination of the Republican Party on July 19, 2016, at the Republican National Convention. On November 8, 2016," <<endl
                 << "Trump was elected the 45th president of the United States. He received 304 electoral votes to Hillary Clinton's (D) 227." <<endl <<endl
                 << "Trump assumed office on January 20, 2017, and filed to run for re-election on the same day. He crossed the delegate" <<endl
                 << "threshold necessary to win the Republican nomination—1,276 delegates—on March 17, 2020. He was formally" <<endl
                 << "nominated at the Republican National Convention on August 24, 2020. President Joe Biden defeated Trump in the" <<endl
                 << "2020 presidential election on November 3, 2020. Biden received 306 electoral votes, while Trump received 232." <<endl <<endl;
            break;

        case 2:
            cout << "Kamala Harris" << endl <<endl << "Today, we face a choice between two very different visions for our nation:" <<endl << "one focused on the future and the other focused on the past. And we are fighting for the future." <<endl <<endl
                 << "Biography" <<endl <<endl;
            cout << "Harris was born in Oakland, California, in 1964. Her mother, Shyamala Gopalan, is a biologist from India. Her father,"<<endl
                 << "Donald J. Harris, is an economist from Jamaica. From the age of twelve, Harris lived in Montreal, Quebec, with her" <<endl
                 << "mother and sister until she returned to the U.S. to attend Howard University in Washington, D.C. She earned a" <<endl
                 << "bachelor's degree in political science and economics from Howard in 1986. Harris attended law school at the" <<endl
                 << "University of California, Hastings, serving as president of the school's chapter of the Black Law Students Association." <<endl
                 << "She graduated with a J.D. in 1989" << endl <<endl
                 << "After graduating from law school, Harris joined the office of the Alameda County district attorney, where she worked"<<endl
                 << "for eight years as a prosecutor. Then-state assemblyman Willie Brown (D) appointed Harris to positions on the" <<endl
                 << "California Unemployment Insurance Appeals Board and the Medical Assistance Commission in 1994. In 1998" <<endl
                 << "Harris was hired as managing attorney for the San Francisco District Attorney's Career Criminal Unit. She transferred" <<endl
                 << "to head the Division on Families and Children in 2000. In 2003, Harris was elected San Francisco District Attorney." <<endl
                 << "She won re-election in 2007." <<endl <<endl
                 << "In 2010, was elected California attorney general. She was re-elected in 2014. In 2016, Harris was elected to the U.S." <<endl
                 << "Senate seat formerly held by Barbara Boxer (D). Harris was the first South Asian American to serve in the U.S. Senate." <<endl <<endl
                 << "In 2009, Harris authored Smart on Crime: A Career Prosecutor's Plan to Make Us Safer, where she discussed" <<endl
                 << "potential changes to the criminal justice system. She wrote The Truths We Hold: An American Journey, a memoir, and" <<endl
                 << "Superheroes Are Everywhere, a picture book, in 2018." <<endl <<endl <<endl;
            break;
    }
}

void main_menu()
{
    int m;
    while (m!=3)
    {
        cout << "**************************************" << endl;
        cout << "              WELCOME" <<endl;
        cout << "     ELECTIONS IN THE USA 2024" <<endl;
        cout << "**************************************" << endl;
        cout << "1. READY TO VOTE!" << endl;
        cout << "2. MORE INFORMATION ABOUT CONDIDATES" << endl;
        cout << "3. EXIT" << endl;
        cin >> m;
        switch (m)
        {
        case 1:
            c.info();
            c.vote();
            break;
        case 2:
            condidates();
            break;
        case 3:
            break; 
        default:
            cout << "Wrong Input" << endl << "Invalid input" << endl;
            break;
        }
    }
    
}

int main (){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PW, DATABASE, PORT, NULL, 0);
    int choice;
    if(conn)
    {
        while(1)
        {
            system("cls");
            main_menu();
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