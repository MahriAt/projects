#include <iostream>
#include <cmath>
using namespace std;

void menu (void);

int main ()
{
    cout<< "***Calculator***" << endl;
    bool exit = true;
    while (exit)
    {
        int a, b;
        int menuChoose;
        a = 0;
        b = 0;
        menu();
        cin>>menuChoose;
        if(menuChoose < 4 || menuChoose == 5){
            cout << "write two numbers:";
            cin>> a;
            cin>>b;}
        switch (menuChoose)
        {
        case 1:
            cout<<"result "<<a+b<<endl;
            break;
        case 2:
            cout<<"result "<<a-b<<endl;
            break;
        case 3:
            cout<<"result "<<a*b<<endl;
            break;
        case 4:
            cout << "write two numbers:";
            double c, d;
            cin>> c;
            cin>>d;
            cout<<"result "<<c/d<<endl;
            break;
        case 5:
            cout<<"result "<<pow(a,b)<<endl;
            break;
        case 6:
            cout << "write a number: ";
            double num;
            cin>> num;
            cout<<"result "<<sqrt(num)<<endl;
            break;
        case 7:
            cout << "write two numbers:";
            double e, f;
            cin>> e;
            cin>>f;
            cout<<"result "<<(e*(f*0.01))<<endl;
            break;
        case 8:
            exit=false;
        }
    }
    
    return 0;
}

void menu (void){
    cout<< "Please choose operation:" <<endl
        << "1-add two numbers"<<endl
        << "2-substruct numbers"<<endl
        << "3-multiply numbers"<<endl
        << "4-devide numbers"<<endl
        << "5-pover"<<endl
        << "6-square root of number"<<endl
        << "7-procenteg of number"<<endl
        << "8-exit" <<endl;

}