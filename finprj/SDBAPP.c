#include "SDB.h"


void SDB_action(uint8 choice){
/*
the action function uses switch case to quickly switch
to start excuting the corresponding function for each
user input from 1 to 9 and also checks the input is valid
*/
uint32 x,y,z;// ID vars for scanf


switch (choice){
case 1:
    //if the add entry function returns false, let the user know
    //that Data entry was unsuccessfully
    if(!SDB_AddEntry()){
        printf(R "\nData entry was unsuccessfully!!!" RST);
    }
    break;

case 2:
    printf(M "The Database has %d Enteries" RST,SDB_GetUsedSize());
    break;

case 3:
    printf("Enter the ID of the entry you want to read: ");
    scanf("%u", &x);
    SDB_ReadEntry(x);
    break;

case 4:
    SDB_GetList();
    break;

case 5:
    printf("Enter the ID of the entry you want to check: ");
    scanf("%u", &y);
    if(SDB_IsIdExist(y)){
    printf(G "This ID dose exist" RST);
    }else{
    printf(R "That ID DOSE NOT exist" RST);
    }
    break;

case 6:
    printf("Enter the ID of the entry you want to delete: ");
    scanf("%u", &z);
    SDB_DeletEntry(z);
    break;

case 7:
    if(SDB_IsFull()){
     printf(R "Database IS FULL" RST);
    }else{
    printf(G "Database is not full yet" RST);
    }
    break;

case 9:
printf(G "\
Enter 1 To add entry\n\
Enter 2 To get the used size in database\n\
Enter 3 To read student data\n\
Enter 4 To get the list of all students' IDs\n\
Enter 5 To check is ID is in the database\n\
Enter 6 To delete student data\n\
Enter 7 To check if the database is full\n\
Enter 0 To exit\n\
Enter 9 To rePrint the main menu\n" RST);
break;

default:
    printf(R "invalid input\n" M);
    break;
}
}

void SDB_APP(){
/*
first, the app function initilizes the database to make sure it has
no garbage values, then it orints the main manu, after so, within a
super loop it asks the user for input and break the loop only when
the user enters 0
*/
initDB();

//set the choice var to a default value to not affect the super loop
uint8 choice=-1;

printf(C "///////////////Student Master database////////////////\n" RST);
printf(G "\
Please choose your action:\n\n\
Enter 1 To add entry\n\
Enter 2 To get the used size in database\n\
Enter 3 To read student data\n\
Enter 4 To get the list of all students' IDs\n\
Enter 5 To check is ID is in the database\n\
Enter 6 To delete student data\n\
Enter 7 To check if the database is full\n\
Enter 0 To exit\n\
Enter 9 To rePrint the main menu\n" RST);


while(1){

    printf(M "\n\n>>>Main manu\nEnter your choice: ");
    scanf("%u",&choice);
    getchar(); //send getchar so scanf dose'nt repeat
    if(choice == 0){break;}
    SDB_action(choice);
    getchar();
}
}

