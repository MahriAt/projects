#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, result, q, a;
    printf("This program prints if the number polindrome or not\n");
    printf("Please enter a number ");
    scanf("%d", &x);
    q = x;
    result = 0;
    while(q != 0)
    {
        a = q%10;
        result = result*10 + a;
        q= q/10;
        printf(" %d %d\n", result, q);
    }
    if(result != x)
        printf("it is not");
    else
        printf("it is");
    return 0;
}
