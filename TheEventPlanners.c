#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>

 struct EventRegistration{
    char AttendeeName[50];
    char AttendeeAddress[50];
    char Contact[50];
 }e;

   struct MenuItem {
    char name[50];
    float quantity;
};

void CateringOrder();
void CateringList();

void CateringOrder() {
    FILE *cateringFile;
    cateringFile = fopen("CateringMenu.txt", "ab");

    struct MenuItem cateringItem;

    printf("Enter Catering Item Name: ");
    fflush(stdin);
    gets(cateringItem.name);

    printf("Enter Catering Item Quantity: ");
    scanf("%f", &cateringItem.quantity);

    printf("\nCatering Item Added Successfully");

    fwrite(&cateringItem, sizeof(cateringItem), 1, cateringFile);
    fclose(cateringFile);
}

void CateringList() {
    system("cls");
    printf("<== Catering Menu ==>\n\n");
    printf("%-30s %-10s\n", "Item Name", "Quantity");
    printf("---------------------------------------\n");

    FILE *cateringFile;
    cateringFile = fopen("CateringMenu.txt", "rb");

    struct MenuItem cateringItem;

    while (fread(&cateringItem, sizeof(cateringItem), 1, cateringFile) == 1) {
        printf("%-30s %.1f\n", cateringItem.name, cateringItem.quantity);
    }

    fclose(cateringFile);
}

void ContactInfo();
void LeaveFeedback();

void ContactInfo() {
    printf("\nContact Information:\n");
    printf("Email: event@example.com\n");
    printf("Phone: +1234567890\n");
}

void LeaveFeedback() {
    FILE *feedbackFile;
    feedbackFile = fopen("Feedback.txt", "a");

    char feedback[200];
    printf("\nEnter your feedback (max 200 characters):\n");
    fflush(stdin);
    gets(feedback);

    fprintf(feedbackFile, "%s\n", feedback);

    printf("Thank you for your feedback!\n");

    fclose(feedbackFile);
}


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
  int main(){
      WelcomeScreen();
     int ch;

   while(1){
    system("cls");
    printf("\n\n\t\t\t-------------------------------------------------------------------------------");
    printf("\n\t\t\t|                              THE EVENT PLANNERS                             |");
    printf("\n\t\t\t-------------------------------------------------------------------------------");
    printf("\n\nPlan Your Own Event -->\n");
    printf("                                                    1.Attendee Registration\n");
    printf("                                                    2.Attendees list\n");
    printf("                                                    3.CateringOrder\n");
    printf("                                                    4.CateringList\n");
    printf("                                                    5.Contact\n ");
    printf("                                                   6.Feedback\n");
    printf("                                                    7.Exit\n");

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
            CateringOrder();
            break;
        case 4:
            CateringList();
            break;
        case 5:
            ContactInfo();
            break;
        case 6:
            LeaveFeedback();
            break;
        case 7:
            printf("Exiting the program. Goodbye!\n");
                exit(0);
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

