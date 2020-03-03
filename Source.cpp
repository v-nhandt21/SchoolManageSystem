#include "Header.h"
int main()
{
	resizeConsole(598, 700);
	list a; bool isLog = 0;
	User_Input("User.csv", a);
	User login;
	Login(isLog,a,login);
//	AS_Student_Move(a);
//	AS_Course_View(a);
//	Changepassword(login, a);
//	AS_Class_StudentView(a);
//	AS_Student_Add(a);
//	AS_Course_Add(a);
//	AS_Presence_View(a);
	system("pause");
}