#include <stdio.h>
#include <stdlib.h>
//this code for hospital database with links in C
struct patientdata 
{
    char name [50];
    char surname [50];
    int age;
    int id;
    char mail [50];
    struct patientdata *next;
};
typedef struct patientdata pdata;
pdata *head, *new;

pdata *addpatient(pdata *head);
void printlist (pdata *head);
pdata *patientlist();

int main(void)
{
    int b;
    head = patientlist();
    printlist (head);
    printf("Do you want to add anyone else?y(1)/n(0) ");
    scanf("%d", &b);
    if(b == 0)
        printlist (head);
    else{
        head = addpatient(head);
        printlist (head);
    }
    return 0;
}

pdata* patientlist()
{
    int n, k;
    pdata *head, *p;
    printf("How many patients will be in data: ");
    scanf("%d",&n);
    for(k=0; k<n; k++)
    {
        if(k==0)
        {
            head = (pdata *)malloc(sizeof(pdata));
            p = head;
        }
        else
        {
            p->next= (pdata*)malloc(sizeof(pdata));
            p = p->next;
        }
        printf("Enter %d patient's Name: ", k+1);
        scanf("%s", p->name);
        printf("Enter %d patient's Surname: ", k+1);
        scanf("%s", p->surname);
        printf("Enter %d patient's age: ", k+1);
        scanf("%d", &p->age);
        printf("Enter %d patient's id: ", k+1);
        scanf("%d", &p->id);
        printf("Enter %d patient's email: ", k+1);
        scanf("%s", p->mail);
    }
    p->next = NULL;
    return head;
}
void printlist (pdata *head)
{
    int count = 1;
    pdata *p;
    p = head;
    if(p == NULL){
        printf("NO data entered\n");
    }
    else 
    {
        while(p!= NULL)
        {
        printf("%d patient: %s %s %d %d %s\n", count, p->name, p->surname, p->age, p->id, p->mail);
        p = p->next;
        count++;
        }
    }
    
}
pdata *addpatient(pdata *head)
{
    pdata *p;
    pdata *new = (pdata* )malloc(sizeof(pdata));
    printf("Enter new patient's Name: ");
    scanf("%s", new->name);
    printf("Enter new patient's Surname: ");
    scanf("%s", new->surname);
    printf("Enter new patient's age: ");
    scanf("%d", &new->age);
    printf("Enter new patient's id: ");
    scanf("%d", &new->id);
    printf("Enter new patient's email: ");
    scanf("%s", new->mail);
    p = head;
    while(p->next!= NULL){
        p = p->next;
    }
    p->next = new;
    new->next = NULL;
    return head;
}