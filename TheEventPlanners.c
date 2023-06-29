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

     
