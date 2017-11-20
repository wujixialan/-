#include<stdio.h>
#include<malloc.h>
#include<windows.h>
#include<string.h>
#include<memory.h>
#define MAXSIZE 20
#define SEX 6
#define PEOPLE 200

typedef struct
{
	char name[MAXSIZE];
	char sex[SEX];
	char number[MAXSIZE];
	float score;
}Student;

void Get_information(Student *student);
void Get_score(Student *student);
void Change(Student *student);
void Delete(Student *student);
void Select(Student *student);
void Order(Student *student);
void Print_all(Student *student);
int Get_peoplecount(Student *student);
void Save(Student *student);
int Read_data(Student *student);