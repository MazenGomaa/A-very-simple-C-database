#include "STD.h"
#include <stdio.h>
#include <stdlib.h>


//database elements' struct as student
typedef struct SimpleDb
{
uint32 Student_ID;
uint32 Student_year;
uint32 Course1_ID;
uint32 Course1_grade;
uint32 Course2_ID;
uint32 Course2_grade;
uint32 Course3_ID;
uint32 Course3_grade;
} student;



//SDB.c Functions Prototypes
void initDB();

bool SDB_IsFull ();

uint8 SDB_GetUsedSize();

bool SDB_AddEntry();

void SDB_DeletEntry (uint32 );

bool SDB_ReadEntry (uint32 );

void SDB_GetList ();

bool SDB_IsIdExist(uint32);

void SDB_APP();
