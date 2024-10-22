#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Roman numbers to decimal numbers


int romanToInt(char* s);
int main(){
    char rome[50];
    printf("enter rome number: ");
    scanf("%s", rome);
    char *s;
    s = rome;
    int num;
    num = romanToInt(s);
    printf("Your number %d", num);
}
int romanToInt(char* s) {
    int result =0;
    while(*s)
    {
        switch(*s){
            case 'I': 
                if(*(s+1)=='V' || *(s+1) == 'X')
                    result -=1;
                else
                    result +=1;
                break;
            case 'V': result += 5;
            break;
            case 'X':
                if(*(s+1)=='L' || *(s+1) == 'C')
                    result -=10;
                else
                    result +=10;
                break;
            case 'L': result += 50;
            break;
            case 'C':  
                if(*(s+1)=='D' || *(s+1) == 'M')
                    result -=100;
                else
                    result +=100;
                break;
            case 'D': result += 500;
            break;
            case 'M': result += 1000;
            break;
            default:
            return 0;
            break;
        }
        s++;
    }
    return result;
}