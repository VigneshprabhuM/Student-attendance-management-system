#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct login1
{
   char username[30];
   char password[30];
   char name[30];
   int dob;
   char gender[10];
   int no;
   char mail[30];
   char bg[10];
   char qua[30];
   int ano;
}l;


void login()
{
   char username[30],password[30];
   FILE *log;
   log=fopen("login.txt","r");
  struct login1 l;

   printf("Username:  ");
   fgets(username, 30, stdin);
   printf("\nPassword: ");
   fgets(password, 30, stdin);

   while(fread(&l,sizeof(l),1,log))
       {
       if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

           {
               printf("\nSuccessful Login\n");
           }
       else
           {
               printf("\nIncorrect Login Details\n");
           }
}

fclose(log);

}


void registration()
{
   char name[30];
   FILE *log;
   log=fopen("login.txt","w");
   struct login1 l;

   printf("\nEnter  Name:");
   scanf("%s",l.name);
   printf("\nEnter date of birth:");
   scanf("%d",&l.dob);
   printf("\nEnter gender:");
   scanf("%s",l.gender);
   printf("\nEnter phone number:");
   scanf("%d",&l.no);
   printf("\nEnter mail id:");
   scanf("%s",l.mail);
   printf("\nEnter the blood group:");
   scanf("%s",l.bg);
   printf("\nEnter the qualification:");
   scanf("%s",l.qua);
   printf("\n Enter Aadhaar number:");
   scanf("%d",&l.ano);
   printf("View account\n");
   printf("%s",l.name);
   printf("%d",l.dob);
   printf("%s",l.gender);
   printf("%d",l.no);
   printf("%s",l.mail);
   printf("%c",l.bg);
   printf("%s",l.qua);
   printf("%d",l.ano);



   fwrite(&l,sizeof(l),1,log);
   fclose(log);

   printf("\nRegistration Successful!\n");
   getchar();
   login();
}



int main()
{
   int option;
   printf("Press '1' to Register\nPress '2' to Login\n\n");
   scanf("%d",&option);
   switch(option)
   {
       case 1:
       {
           registration();
           break;
       }
       case 2:
       {
           login();
           break;
       }
   }
}
