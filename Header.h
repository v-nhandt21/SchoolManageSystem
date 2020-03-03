#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
#include <conio.h>
#include <Windows.h>
#define _WIN32_WINNT 0x0500
																				//Design
void Paint(int x, int y, char *a, int color);
void gotoxy(int x, int y);
void textcolor(int x);
void resizeConsole(int width, int height);
void centerstring(char* s);
void window1(int w, int h, int x, int y);
void window2(int x, int y, char A[100]);
void Cursor(int &x, int &y);
void Cursor2(int &x, int &y);
																				//Data structer
struct User{
	char username[1000];
	char fullname[1000];
	char email[1000];
	char mobliephone[20];
	int type;
	char password[1000];
	char classes[100];
	User *pNext;

};

struct Score
{
	
	char StudentID[100];
	float Midterm_score;
	float Lab_score;
	float Final_score;
	Score * next;
};

struct Presence
{
	
	char StudentID[100];
	int Week;
	bool check[50];
	Presence *next;
};

struct Course
{
	char Course_code[100];   //.Eg : CTT008, CS161
	char Lecture[20];
	int NumSD;
	char StudentID[100][100];
	Course *pNext;
};

struct Schedule
{
	char Course_code[100];   //.Eg : CTT008, CS161
	char Year[100];				//.Eg : 2016 - 2017
	int Semester;				//.Eg : 1, 2, 3
	char Course_name[100];
	char Lecturer[100];
	char Start[100];
	char End[100];
	char From[100];
	char To[100];
	char Dateofweek[100];    // .Eg: Monday, Tuesday... 
	Schedule *pNext;
};

struct Student {
	char ID[100];
	char name[100];
	char Class[10];
	char email[1000];
	char mobliephone[20];	
	int gender; // 0:male, 1: female
	Student * next;
};

struct Class {
	char ClassID[10];
	Class* next;
};

struct list {
	User *User_head;
	Class *Class_head;
	Course *Course_head;
	Presence *Presence_head;
	Score *Score_head;
	Student *Student_head;
	Schedule *Schedule_head;
};

																					//Index
void Login(bool& isLog, list &a, User& login);
void Showmenu(list &a, User &login, bool& isLog);
void Viewinfo(User &login);
void Changepassword(User &login, list& a);
void Logout(bool &isLog);
void User_Input(char path[], list &a);
void User_Update(list&a);
																					//Function

																	///////////Function for Academic staff
void Student_Update(list&a, char ClassID[10]);
void AS_Student_Input(list& a, char ClassID[10]);
void AS_Student_Add(list &a);// Add student
void AS_Student_Edit(list &a);//8. Edit an existing student
void AS_Student_Remove(list &a);//9. Remove a student
void AS_Student_Move(list &a);//10. Change students from class A to class B

void Class_Update(list&a);
void AS_Class_Input(list &a);
bool isOpenClass(list &a, char ClassID[]);
void AS_Class_Add(list &a);//11. Add a new empty class     // tao them node+ tao file csv trong folder class
void AS_Class_View(list &a);//12. View list of classes
void AS_Class_StudentView(list &a);//13. View list of students in a class

void Course_Update(list&a);
void AS_Course_Input(list &a);
bool isOpenCourse(list &a, char CourseCode[]);
void AS_Course_Add(list &a);//15. Add a new course         // tao them node+ tao file csv trong folder presence va score
void AS_Course_Edit(list &a);//16. Edit an existing course
void AS_Course_Remove(list &a);//17. Remove a course
void AS_Course_View(list &a);//18. View list of courses

void Schedule_Update(list&a, char ClassID[10]);
void AS_Schedule_Input(list &a, char ClassID[10]);
void AS_Schedule_Add(list &a);
void AS_Schedule_Edit(list &a);
void AS_Schedule_Remove(list &a);
void AS_Schedule_View(list &a);

void Presence_Update(list&a, char CourseCode[10]);
void AS_Presence_Input(list& a, char CourseCode[10]);
void AS_Presence_View(list &a);//24. Search and view attendance list of a course
void AS_Presence_Export(list &a);//25. Export attendance list to a csv file                                    //

void Score_Update(list&a, char CourseCode[10]);
void AS_Score_Input(list& a, char CourseCode[10]);
void AS_Score_View(list &a);//26. Search and view scoreboard of a course
void AS_Score_Export(list &a);//27. Export a scoreboard to a csv file*/                                           //

																 //Function for lecturer

void Lec_Score_Add(list &a);//28. Import scoreboard of a course(midterm, final, lab, bonus)
void Lec_Score_Edit(list &a);//29. Edit grade of a student
void Lec_Score_View(list &a);//30. View a scoreboard*/
																//Function for student

void Stu_Presence_Check(list &a, User &login);// Check-in.
void Stu_Presence_View(list &a, User &login);// View check-in result
void Stu_Score_View(list &a, User &login);// View his/her scores of a course
void Stu_Schedule_View(list &a);// View schedules