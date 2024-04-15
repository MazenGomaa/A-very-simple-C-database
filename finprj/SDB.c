#include "SDB.h"

student db[dbsize]; //The DataBase Variable, an array of 10 structs of the type student
uint8 dbptr = 0;

void initDB(){
//initialize database with NULL as its value for all of its elements and struct members

    for(uint8 i=0; i<3;i++){      //loop through the db array of structs
            //set each member of i struct to NULL
        db[i].Student_ID    = NULL;
        db[i].Student_year  = NULL;
        db[i].Course1_ID    = NULL;
        db[i].Course1_grade = NULL;
        db[i].Course2_ID    = NULL;
        db[i].Course2_grade = NULL;
        db[i].Course3_ID    = NULL;
        db[i].Course3_grade = NULL;
    }

}






uint8 SDB_GetUsedSize(){
// simpley the database pointer

return dbptr;
}



bool SDB_IsFull (){
//check if the current size of the entered data is the same
//size of the whole db,If so return true, else, false

    if(SDB_GetUsedSize() == dbsize){
        return true;
    }else{
        return false;
    }
}



void SDB_DeletEntry (uint32 ID){
/*
the delete function simply takes the reqiured ID of the data to be deleted
then uses it to find the index of the struct of that data within the db main
array

and then it shifts the array to the left in the place of the deleted data
*/


uint8 i; //the index var i is used to store the index of the deleted struct
uint8 z; //a copy of i is made to be modified


//loop through the database and search for the matching ID
    for(i=0 ; i<dbsize ; i++){
        if(db[i].Student_ID == ID){
        break;  //exit the loop once the matching ID is found within the array's index i
         }
    }

z=i;

//first, before shifting, check that i is'nt at the end of the array
if(!(i==dbsize-1)){

//if not, then shift the entire struct int the place of the deleted struct
        //and loop through the rest of the array's elements
        for(z; z<dbsize;z++){
    db[z].Student_ID    =  db[z+1].Student_ID;
    db[z].Student_year  =  db[z+1].Student_year;
    db[z].Course1_ID    =  db[z+1].Course1_ID;
    db[z].Course1_grade =  db[z+1].Course1_grade;
    db[z].Course2_ID    =  db[z+1].Course2_ID;
    db[z].Course2_grade =  db[z+1].Course2_grade;
    db[z].Course3_ID    =  db[z+1].Course3_ID;
    db[z].Course3_grade =  db[z+1].Course3_grade;
    }
//set the last element to be empty and not garbge values

}
// if i is at the end of the array then theres no need to shift
//+ its already deleted

//decrement the database pointer since the database just lost an element
dbptr--;
};



bool SDB_AddEntry(){
/*
the add function dose the oppsite of the delete function, and also checks the
input for errors to determine whether the data can be accepted or not
*/

    uint8 mem;        //memory location variable to be used as the array's Index
    bool faultFlag;  //input error detection boolean, 1= input error, entry   not saved, 0= entry saved

    // saving the database pointer value into the memory location var
    mem = dbptr;


    if(!(dbptr==dbsize)){       //if the database is'nt full, start accepting data
        printf(Y "\n\///////////////Add student course data////////////////\n\Enter the Student's ID:" );
        scanf("%u", &db[mem].Student_ID);

        //check the data if it's correct, if not, set the fault flag so it dose'nt
        // save that whole entry, same with every data input
    if(db[mem].Student_ID <= 0 || db[mem].Student_ID > u32 ){
        printf(R "\nInvalid input!\n" RST);
        getchar();
        faultFlag =true;
    }



    printf("Enter the student's Year:");
    scanf("%u", &db[mem].Student_year);
    if(db[mem].Student_year <= 0 || db[mem].Student_year > u32 ){
        printf(R "\nInvalid input!\n" RST);
        getchar();
        faultFlag =true;
    }


    printf("\n-----------Course Data-------------\n");


    printf("Enter course 1 ID: ");scanf("%u", &db[mem].Course1_ID);getchar();
    printf("Enter course 1 Grade: ");scanf("%u", &db[mem].Course1_grade);
    if((db[mem].Course1_grade<= 0||db[mem].Course1_grade>u32) && (db[mem].Course1_ID<= 0||db[mem].Course1_ID>u32) ){
        printf(R "\nInvalid input!\n" RST);
        getchar();
        faultFlag =true;
    }



    printf("\nEnter course 2 ID: ");scanf("%u", &db[mem].Course2_ID);getchar();
    printf("Enter course 2 Grade: ");scanf("%u", &db[mem].Course2_grade);
    if((db[mem].Course2_grade<= 0||db[mem].Course2_grade>u32) && (db[mem].Course2_ID<= 0||db[mem].Course2_ID>u32) ){
        printf(R "\nInvalid input!\n" RST);
        getchar();
        faultFlag =true;
    }



    printf("\nEnter course 3 ID: ");scanf("%u", &db[mem].Course3_ID);getchar();
    printf("Enter course 3 Grade: ");scanf("%u", &db[mem].Course3_grade);
    if((db[mem].Course3_grade<= 0||db[mem].Course3_grade>u32) && (db[mem].Course3_ID<= 0||db[mem].Course3_ID>u32) ){
        printf(R "\nInvalid input!\n" RST);
        getchar();
        faultFlag =true;
    }


    //if the fault flag was set, delete this specific entry and return false
    if(faultFlag){
        db[mem].Student_ID    = NULL;
        db[mem].Student_year  = NULL;
        db[mem].Course1_ID    = NULL;
        db[mem].Course1_grade = NULL;
        db[mem].Course2_ID    = NULL;
        db[mem].Course2_grade = NULL;
        db[mem].Course3_ID    = NULL;
        db[mem].Course3_grade = NULL;
        return false;
    }else{
        //else print the following and increment the db pointer, so that
        // we can keep track of how the entered data
        printf(G "Data is added successfully" RST);
        dbptr++;
        return true;
    }


//if the database is full, return false
}else if(dbptr==dbsize){return false;}


}



bool SDB_ReadEntry (uint32 ID){
/*
First it searches for the desired ID's Index inside of the array and store it whithin i
then check if the id exist, if so proceed, if not, let the user know
*/

    //the setflag for non-exsisting ID
    bool faultflag = false;

    //loop through database and search for the matching ID
    //and break the loop once the matching ID is found within
    //the array's index i and set the fault flag true
    uint8 i;
        for(i=0 ; i<dbsize ; i++){
            if(db[i].Student_ID == ID){
            faultflag = true;
            break;
            }
        }

//check if the flag is true
    if(faultflag){

//if true, print the matching ID's data from the database
//from the main db array with the matched index i
printf(C "\n\
///////////////Student course data////////////////\n\
Student's ID:%d, Student's Year:%d  \n\
--------------------------------------------------\n\
Course No.1 [ID:%d]\n\
Grade: %d\n--------\n\
Course No.1 [ID:%d]\n\
Grade: %d\n--------\n\
Course No.1 [ID:%d]\n\
Grade: %d" RST,\
db[i].Student_ID, db[i].Student_year,\
db[i].Course1_ID, db[i].Course1_grade,\
db[i].Course2_ID, db[i].Course2_grade,\
db[i].Course3_ID, db[i].Course3_grade);
return true;
    }
    else{
        //else, let the user know that the ID dose not exist and return false
        printf(R "This ID dose not exist!!\n" RST);
        return false;
        }

};



void SDB_GetList (){
//Loops the db array, print every student_id member of each element
uint8 i=0 , y=SDB_GetUsedSize();

    //print the total number of IDs
    printf(G "\nExisting students' IDs:\n --A Total of:%d\n" RST,SDB_GetUsedSize());

    //print all Existing IDs, if there's none, let the user Know
    for(i=0 ; i<y ; i++){
            //make sure there are any data
       if(SDB_GetUsedSize() > 0){
            if(db[i].Student_ID){
                printf(G "Student No.%d ID: %d\n" RST,i+1,db[i].Student_ID);
            }
       }
        else{
            //if there are'nt any, break the loop and let the user know
        printf(R "No data to display" RST);
        break;
        }
    }
}



bool SDB_IsIdExist(uint32 ID){
/*
Same as before, Loops the db array and search for a matching ID
and then if it finds the ID, Returns true, else false
*/

bool existflag = false; //boolean flag var for the ID's existence with default value of false
for(uint8 i=0 ; i<dbsize ; i++){
if(db[i].Student_ID == ID){
existflag = true;
//after looping the array, if the ID existed then the condition is true and the flag is set
}
}
return existflag;
}


