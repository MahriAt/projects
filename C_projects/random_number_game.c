#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//this program will roll two dices and if you get 11 you win

int main()
{
 try:
    srand(time(NULL));
    int a = 1 + rand()%6;
    int b = 1 + rand()%6;
    int n = a+b;
    static int p = 0;

    if(n==7 || n==11)
    {
        printf("you won\n");
        printf("%d\n", n);

    }
    else if(n==2 || n==3 || n==12)
    {
        printf("you lose\n", n);
        printf("%d\n", n);
    }
    else
    {
        
        if(p<= 6)
        {
            p++;
            printf("you get a point\n");
            printf("%d\n", p);
            goto try;
        }
        else if(p==7) 
        {
            printf("you win\n");
        }
        
    }
    return 0;


}