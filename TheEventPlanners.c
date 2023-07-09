#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 struct EventRegistration{
    char AttendeeName[50];
    char AttendeeAddress[50];
    char Contact[50];
 }e;
   struct Catering{
       char Menu[50];
       char Quantity[50];
}d;
    FILE *fp;
     void WelcomeScreen()
{
    printf("\n\n\n\n\n\t\t\t\t*****************************************");
    printf("\n\t\t\t\t*\t\tWELCOME TO    \t\t*");
    printf("\n\t\t\t\t*          THE EVENT PLANNERS           *  ");
    printf("\n\t\t\t\t*****************************************");
    printf("\n\n\n\nPlan your own Event.>.>.>.>.>.>\n");
    getch();
    system("cls");
}

void Headline()
{
    printf("\n\n\t\t\t-------------------------------------------------------------------------------");
    printf("\n\t\t\t|                              THE EVENT PLANNERS                             |");
    printf("\n\t\t\t-------------------------------------------------------------------------------");
}
int main(){
      WelcomeScreen();
      Headline();
     int ch;

  while(1){
    system("cls");
    printf("<== THE EVENT PLANNERS ==>\n");
    printf("1.Event Registration\n");
    printf("2.Attendees list\n");
    printf("3.Catering\n");
    printf("4.MenuList\n");

    printf("\nEnter your option number: ");
    scanf("%d",&ch);

    switch(ch){
     case 1:
        EventRegistration();
        break;
     case 2:
        AttendeesList();
        break;
     case 3:
        Catering();
        break;
     case 4:
        MenuList();
        break;

     default:
        printf("Error! Invalid choice...\n\n");
    }
     printf("\n\nPlan your own Event...");
     getch();
  }
  return 0;
}

void EventRegistration(){
    fp = fopen("EventRegistration.txt", "ab");

    printf("Enter Attendee Name: ");
    fflush(stdin);
    gets(e.AttendeeName);

    printf("Enter Attendee Address: ");
    fflush(stdin);
    gets(e.AttendeeAddress);

    printf("Enter Attendee's Contact(number or e-mail): ");
    fflush(stdin);
    gets(e.Contact);

    printf("\nAttendee Added Successfully");

    fwrite(&e, sizeof(e), 1, fp);
    fclose(fp);
}

void AttendeesList(){

    system("cls");
    printf("<== Attendees List ==>\n\n");
    printf("%-30s %-30s %-20s\n", "Attendees Name", "Address", "Contact");
    printf("----------------------------------------------------------------------------------------------------------\n");

    fp = fopen("EventRegistration.txt", "rb");
    while(fread(&e, sizeof(e), 1, fp) == 1){
        printf("%-30s %-30s %-20s\n", e.AttendeeName, e.AttendeeAddress, e.Contact);
    }

    fclose(fp);
}
     
