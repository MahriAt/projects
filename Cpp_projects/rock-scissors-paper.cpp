#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int rounds, user, computer,playerPoints, computerPoints;
    playerPoints = 0;
    computerPoints = 0;
    cout<<"***Rock Sizers Paper***"<<endl
        <<"You can choose (1)Rock, (2)Scissors, (3)Paper"<<endl
        <<"You can play more than one round and compare points"<<endl
        <<"How many rounds do you want to play?"<<endl;
    cin>>rounds;
    for (int i = 0; i <= rounds; i++)
    {
        cout<<"Rock Scissors Paper!"<<endl
            <<"1 2 3";
        cin>>user;
        computer = (rand() % 3)+1;
        switch (computer)
        {
        case 1:
            cout<<"Rock!"<<endl;
            if (user == 2)
            {
                cout<<"I won!"<<endl;
                computerPoints++;
            }
            else if(user == 3)
            {
                cout<<"Uhhh, I lose"<<endl;
                playerPoints++;
            }
            else
                cout<<"Lets play again"<<endl;
            break;
        case 2:
            cout<<"Scissors"<<endl;
            if (user == 3)
            {
                cout<<"I won!"<<endl;
                computerPoints++;
            }
            else if(user == 1)
            {
                cout<<"Uhhh, I lose"<<endl;
                playerPoints++;
            }
            else
                cout<<"Lets play again"<<endl;
            break;
        case 3:
            cout<<"Paper!"<<endl;
            if (user == 1)
            {
                cout<<"I won!"<<endl;
                computerPoints++;
            }
            else if(user == 2)
            {
                cout<<"Uhhh, I lose"<<endl;
                playerPoints++;
            }
            else
                cout<<"Lets play again"<<endl;
            break;
        default:
            break;
        }
        cout<<"Your points: "<<playerPoints<<endl
            <<"Computer points: "<<computerPoints<<endl;
    }
    if(playerPoints>computerPoints)
        cout<<"You won this game"<<endl;
    else if(playerPoints<computerPoints)
        cout<<"You lost this game"<<endl;
    return 0;
}
