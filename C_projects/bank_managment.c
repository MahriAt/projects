/*random access file*/
#include <stdio.h>
#include <stdlib.h>

struct account {
    int acNo;
    char name [25];
    char surname [50];
    double balance;
};

int menu (void);
void copyFile (FILE *);
void update (FILE *);
void new (FILE *);
void delete (FILE *);
void list (FILE *);

int main(void)
{
    FILE *myptr;
    int choose;
    if((myptr = fopen("bankacc.txt", "a+")) == NULL)
        printf("File can not be opened");
    else
    {
        while((choose = menu())!= 6)
        {
            switch(choose)
            {
                case 1: copyFile(myptr); break;
                case 2: update (myptr); break;
                case 3: new (myptr); break;
                case 4: delete (myptr); break;
                case 5: list (myptr); break;
            }
        }
        fclose(myptr);
    }
}

int menu (void)
{
    int a;
    printf("\nChoose operation\n"
          "1 : Copy all data to copyfile.txt file\n"
          "2 : Update existing information\n"
          "3 : Add new account\n"
          "4 : Delete\n"
          "5 : List data on the screen\n"
          "6 : Close\n ?");
    scanf("%d", a);
    return a;
}
void copyFile (FILE *fptr)
{
    FILE *wptr;
    struct account acinfo = {0, "", "", 0.0};
    if((wptr = fopen("copyfile.txt", "w")) == NULL)
        printf("File can not be opened");
    else
    {
        rewind (fptr);
        fprintf(wptr, "%-10s %-16s %-11s %10s\n", "AccountNo", "Name", "Surname", "Balance");
        while(!feof(fptr))
        {
            fread(&acinfo, sizeof(struct account), 1, fptr);
            if(acinfo.acNo != 0)
                fprintf(wptr, "%-10d %-16s %-11s %10.2f\n", &acinfo.acNo, acinfo.name, acinfo.surname, &acinfo.balance);
        }
    }
}
void update(FILE *fptr)
{
    int accountNo;
    double add;
    struct account acinfo = {0,"", "", 0.0};
    printf("write account number that you want to update [1-100]");
    scanf("%d", &accountNo);
    fseek(fptr, (accountNo-1)*sizeof(struct account), SEEK_SET);
    fread(&acinfo, sizeof(struct account), 1, fptr);
    if(acinfo.acNo == 0)
        printf("no infornation\n");
    else
    {
        printf("%-10d %-16s %-11s %-10f\n", &acinfo.acNo, acinfo.name, acinfo.surname, &acinfo.balance);
        printf("write how much you would like to add or withdraw (-)\n ?");
        scanf("%lf", add);
        acinfo.balance += add;
        printf("%-10d %-16s %-11s %-10f\n", &acinfo.acNo, acinfo.name, acinfo.surname, &acinfo.balance);
        fseek(fptr, (accountNo-1)*sizeof(struct account), SEEK_SET);
        fwrite(&acinfo, sizeof(struct account), 1, fptr);
    }
}
void new(FILE *fptr){
    int accountNo;
    struct account acinfo = {0, "", "", 0.0};
    printf("write new account number: ");
    scanf("%d", &accountNo);
    fseek(fptr, (accountNo-1)*sizeof(struct account), SEEK_SET);
    fread(&acinfo, sizeof(struct account), 1, fptr);
    if(acinfo.acNo == 0)
        printf("zccount with this id already exist");
    else
    {
        printf("write down name surname and ballance\n ?");
        scanf("%s %s %lf", acinfo.name, acinfo.surname, &acinfo.balance);
        fseek(fptr, (accountNo-1)*sizeof(struct account), SEEK_SET);
        fwrite(&acinfo, sizeof(struct account), 1, fptr);
    }
}
void delete (FILE *fptr)
{
    int accountNo;
    struct account empty, acinfo = {0, "", "", 0.0};
    printf("write down the account nuber that you want to delete");
    scanf("%d", &accountNo);
    fseek(fptr, (accountNo-1)*sizeof(struct account), SEEK_SET);
    fread(&acinfo, sizeof(struct account), 1, fptr);
    if(acinfo.acNo == 0)
        printf("Account nomber %d is not exist", &acinfo.acNo);
    else
    {
        fseek(fptr, (accountNo-1)*sizeof(struct account), SEEK_SET);
        fwrite(&empty, sizeof(struct account), 1, fptr);
    }
}
void list (FILE *fptr)
{
    struct account acinfo = {0, "", "", 0.0};
    printf("%-10s %-16s %-11s %10s\n", "AccountNo", "Name", "Surname", "Balance");
    while(!feof(fptr))
    {
        fread(&acinfo, sizeof(struct account), 1, fptr);
        if(acinfo.acNo != 0)
            printf("%-10d %-16s %-11s %10f\n", &acinfo.acNo, acinfo.name, acinfo.surname, &acinfo.balance);
    }
}