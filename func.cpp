#include "Header.h"

//Index
void User_Update(list&a) {
	User *cur = a.User_head;
	ofstream fout("User.csv");
	if (!fout.is_open()) return;
	else
	{
		while (cur != NULL)
		{
			fout << cur->username<<"," ;
			fout << cur->fullname << ",";
			fout << cur->email << ",";
			fout << cur->mobliephone << ",";
			fout << cur->type << ",";
			fout << cur->password << ",";
			if (cur->pNext == NULL) fout << cur->classes;
			else fout << cur->classes << endl;

			cur = cur->pNext;
		}
	}
	fout.close();
}
void User_Input(char path[], list &a)
{
	a.User_head =NULL;
	User *cur = a.User_head;
	ifstream fin(path);
	if (!fin.is_open()) cur = NULL;
	else
	{
		while (fin.good())
		{
			if (a.User_head == NULL) {
				a.User_head = new User; cur = a.User_head;
			}
			else {
				cur->pNext = new User;
				cur = cur->pNext;
			}
			fin.get(cur->username, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->fullname, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->email, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->mobliephone, 1000, ',');
			fin.ignore(10, ',');
			fin >> cur->type;
			fin.ignore(10, ',');
			fin.get(cur->password, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->classes, 100, '\n');                                                                                                 
			fin.ignore(10, '\n');
		}
		cur->pNext = NULL;
	}
	fin.close();
}
void Login(bool& isLog, list &a, User &login) {
	gotoxy(1, 20);
	User *cur;
	cur = a.User_head;
	textcolor(5);
	window1(50, 53, 1, 1);
	for (int i = 1; i <= 30; i++) cout << endl;
	textcolor(10);
	int mmm = 10;
	gotoxy(25, mmm + 3);
	cout << "___  ___         _____                                  " << endl; gotoxy(25, mmm + 4);
	cout << "|  \\/  |        /  __ \\                                 " << endl; gotoxy(25, mmm + 5);
	cout << "| .  . | _   _  | /  \\/  ___   _   _  _ __  ___   ___   " << endl; gotoxy(25, mmm + 6);
	cout << "| |\\/| || | | | | |     / _ \\ | | | || '__|/ __| / _ \\  " << endl; gotoxy(25, mmm + 7);
	cout << "| |  | || |_| | | \\__/\\| (_) || |_| || |   \\__ \\|  __/  " << endl; gotoxy(25, mmm + 8);
	cout << "\\_|  |_/ \\__, |  \\____/ \\___/  \\__,_||_|   |___/ \\___|  " << endl; gotoxy(25, mmm + 9);
	cout << "          __/ |                                       " << endl; gotoxy(25, mmm + 10);
	cout << "         |___/                                        " << endl; gotoxy(25, mmm + 11);
	textcolor(11);
	gotoxy(40, 1);
	gotoxy(50, mmm + 12);
	cout << "LOGIN";
	cout << endl;
	//
	gotoxy(50, mmm + 30);
	cout << "Group 15" << endl; gotoxy(45, mmm + 31);
	cout << "Thai Thuan Thanh" << endl; gotoxy(45, mmm + 32);
	cout << "Ngo Hoang Bao Thach" << endl; gotoxy(45, mmm + 33);
	cout << "Do Tri Nhan" << endl; gotoxy(45, mmm + 34);
	cout << "Nguyen Ngoc Phong" << endl;
	cout << endl; gotoxy(45, mmm + 35);
	cout << "Use a,s,d,w to move the cursor!";
	cout << endl;
	//
	textcolor(12);
	gotoxy(35, mmm + 15);
	cout << "USERNAME:  ";
	cin.get(login.username, 100, '\n');
	cin.ignore(100, '\n');
	gotoxy(35, mmm + 17);
	cout << "PASSWORD:  ";
	cin.get(login.password, 100, '\n');
	cin.ignore(100, '\n');
	while (cur != NULL)
	{
		if (strcmp(cur->username, login.username) == 0 && strcmp(cur->password, login.password) == 0)
		{
			isLog = 1;
			login = *cur;
			break;
		}
		else cur = cur->pNext;
	}
	if (cur == NULL) isLog = 0;
	//////////////////////////////////
	while (isLog == 0)
	{
		cout << "Wrong password or username!";
		system("CLS");
		gotoxy(1, 1);
		Login(isLog, a, login);
	}
	while (isLog == 1)
	{
		system("CLS");
		Showmenu(a, login, isLog);
	}
}
void Showmenu(list &a, User &login, bool& isLog)
{
	int i = 0;
	if (login.type == 0)
	{
		int mmm = -1;
		gotoxy(25, mmm + 3);
		cout << "___  ___         _____                                  " << endl; gotoxy(25, mmm + 4);
		cout << "|  \\/  |        /  __ \\                                 " << endl; gotoxy(25, mmm + 5);
		cout << "| .  . | _   _  | /  \\/  ___   _   _  _ __  ___   ___   " << endl; gotoxy(25, mmm + 6);
		cout << "| |\\/| || | | | | |     / _ \\ | | | || '__|/ __| / _ \\  " << endl; gotoxy(25, mmm + 7);
		cout << "| |  | || |_| | | \\__/\\| (_) || |_| || |   \\__ \\|  __/  " << endl; gotoxy(25, mmm + 8);
		cout << "\\_|  |_/ \\__, |  \\____/ \\___/  \\__,_||_|   |___/ \\___|  " << endl; gotoxy(25, mmm + 9);
		cout << "          __/ |                                       " << endl; gotoxy(25, mmm + 10);
		cout << "         |___/                                        " << endl; gotoxy(25, mmm + 11);
		textcolor(10);
		window2(10, 10, "View Info");
		window2(40, 10, "Change password");
		window2(70, 10, "Logout / Exit");

		textcolor(14);
		window2(10, 20, "Check - in");
		window2(40, 20, "View checkin result");
		window2(70, 20, "View scores");
		window2(10, 30, "View schedules");

		int x = 8; int y = 11;
		Cursor(x, y);
		textcolor(10);
		if (x + 2 == 10 && y - 1 == 10) Viewinfo(login);
		if (x + 2 == 40 && y - 1 == 10) { Changepassword(login, a);}
		if (x + 2 == 70 && y - 1 == 10) Logout(isLog);

		if (x + 2 == 10 && y - 1 == 20) Stu_Presence_Check(a,login);
		if (x + 2 == 40 && y - 1 == 20) Stu_Presence_View(a, login);
		if (x + 2 == 70 && y - 1 == 20) Stu_Score_View(a, login);
		if (x + 2 == 10 && y - 1 == 30) Stu_Schedule_View(a);
	}
	if (login.type == 1)
	{
		int mmm = -1;
		gotoxy(25, mmm + 3);
		cout << "___  ___         _____                                  " << endl; gotoxy(25, mmm + 4);
		cout << "|  \\/  |        /  __ \\                                 " << endl; gotoxy(25, mmm + 5);
		cout << "| .  . | _   _  | /  \\/  ___   _   _  _ __  ___   ___   " << endl; gotoxy(25, mmm + 6);
		cout << "| |\\/| || | | | | |     / _ \\ | | | || '__|/ __| / _ \\  " << endl; gotoxy(25, mmm + 7);
		cout << "| |  | || |_| | | \\__/\\| (_) || |_| || |   \\__ \\|  __/  " << endl; gotoxy(25, mmm + 8);
		cout << "\\_|  |_/ \\__, |  \\____/ \\___/  \\__,_||_|   |___/ \\___|  " << endl; gotoxy(25, mmm + 9);
		cout << "          __/ |                                       " << endl; gotoxy(25, mmm + 10);
		cout << "         |___/                                        " << endl; gotoxy(25, mmm + 11);
		textcolor(10);
		window2(10, 10, "View Info");
		window2(40, 10, "Change password");
		window2(70, 10, "Logout / Exit");
		textcolor(14);

		window2(10, 15, "Add new student");
		window2(40, 15, "Edit student");
		window2(70, 15, "Remove student");
		window2(10, 20, "Move student");
		window2(40, 20, "Add class");
		window2(70, 20, "View class list");
		window2(10, 25, "View student list");

		textcolor(7);
		window2(10, 30, "Add course");
		window2(40, 30, "Edit course");
		window2(70, 30, "Remove course");
		window2(10, 35, "View course list");

		textcolor(13);
		window2(10, 40, "Add schedule");
		window2(40, 40, "Edit Schedule");
		window2(70, 40, "Remove Schedule");
		window2(10, 45, "View schedule list");
		window2(40, 45, "view attendance");
		window2(70, 45, "view scoreboard");
		int x = 8; int y = 11;
		Cursor2(x, y);
		textcolor(10);
		if (x + 2 == 10 && y - 1 == 10) Viewinfo(login);
		if (x + 2 == 40 && y - 1 == 10) Changepassword(login, a);
		if (x + 2 == 70 && y - 1 == 10) Logout(isLog);

		if (x + 2 == 10 && y - 1 == 15) AS_Student_Add(a);
		if (x + 2 == 40 && y - 1 == 15) AS_Student_Edit(a);
		if (x + 2 == 70 && y - 1 == 15) AS_Student_Remove(a);
		if (x + 2 == 10 && y - 1 == 20) AS_Student_Move(a);
		if (x + 2 == 40 && y - 1 == 20) AS_Class_Add(a);
		if (x + 2 == 70 && y - 1 == 20) AS_Class_View(a);
		if (x + 2 == 10 && y - 1 == 25) AS_Class_StudentView(a);

		if (x + 2 == 10 && y - 1 == 30) AS_Course_Add(a);
		if (x + 2 == 40 && y - 1 == 30) AS_Course_Edit(a);
		if (x + 2 == 70 && y - 1 == 30) AS_Course_Remove(a);
		if (x + 2 == 10 && y - 1 == 35) AS_Course_View(a);

		if (x + 2 == 10 && y - 1 == 40) AS_Schedule_Add(a);
		if (x + 2 == 40 && y - 1 == 40) AS_Schedule_Edit(a);
		if (x + 2 == 70 && y - 1 == 40) AS_Schedule_Remove(a);
		if (x + 2 == 10 && y - 1 == 45) AS_Schedule_View(a);
		if (x + 2 == 40 && y - 1 == 45) AS_Presence_View(a);
		if (x + 2 == 70 && y - 1 == 45) AS_Score_View(a);
	}
	if (login.type == 2)
	{
		int mmm = -1;
		gotoxy(25, mmm + 3);
		cout << "___  ___         _____                                  " << endl; gotoxy(25, mmm + 4);
		cout << "|  \\/  |        /  __ \\                                 " << endl; gotoxy(25, mmm + 5);
		cout << "| .  . | _   _  | /  \\/  ___   _   _  _ __  ___   ___   " << endl; gotoxy(25, mmm + 6);
		cout << "| |\\/| || | | | | |     / _ \\ | | | || '__|/ __| / _ \\  " << endl; gotoxy(25, mmm + 7);
		cout << "| |  | || |_| | | \\__/\\| (_) || |_| || |   \\__ \\|  __/  " << endl; gotoxy(25, mmm + 8);
		cout << "\\_|  |_/ \\__, |  \\____/ \\___/  \\__,_||_|   |___/ \\___|  " << endl; gotoxy(25, mmm + 9);
		cout << "          __/ |                                       " << endl; gotoxy(25, mmm + 10);
		cout << "         |___/                                        " << endl; gotoxy(25, mmm + 11);
		textcolor(10);
		window2(10, 10, "View Info");
		window2(40, 10, "Change password");
		window2(70, 10, "Logout / Exit");
		textcolor(14);
		window2(10, 20, "Import scoreboard");
		window2(40, 20, "Edit grade");
		window2(70, 20, "View scores");
		int x = 8; int y = 11;
		Cursor(x, y);
		textcolor(4);
		if (x + 2 == 10 && y - 1 == 10) Viewinfo(login);
		if (x + 2 == 40 && y - 1 == 10) Changepassword(login, a);
		if (x + 2 == 70 && y - 1 == 10) Logout(isLog);

		if (x + 2 == 10 && y - 1 == 20) Lec_Score_Add(a);
		if (x + 2 == 40 && y - 1 == 20) Lec_Score_Edit(a);
		if (x + 2 == 70 && y - 1 == 20) Lec_Score_View(a);
	}
}
void Viewinfo(User &login)
{
	system("CLS");
	cout << login.classes << endl;
	cout << login.email << endl;
	cout << login.fullname << endl;
	cout << login.mobliephone << endl;
	cout << login.password << endl;
	cout << login.type << endl;
	cout << login.username << endl;
	int zz = _getch();
}
void Changepassword(User &login, list& a)
{
	system("CLS");

	User change;
	cout << "Input your current password:   ";
	cin.get(change.password, 100, '\n');
	cin.ignore(100, '\n');
	if (strcmp(change.password, login.password) == 0)
	{
		cout << "Input your new password:   ";
		cin.get(login.password, 100, '\n');
		cin.ignore(100, '\n');
		User *cur;
		cur = a.User_head;
		while (cur != NULL)
		{
			if (strcmp(cur->username, login.username) == 0)
			{
				strcpy_s(cur->password, login.password);
				cout << "sucess!";
				User_Update(a);
				int zz = _getch();
				return;
			}
			else cur = cur->pNext;
		}
	}
	else cout << "Wrong password" << endl;
}
void Logout(bool &isLog)
{
	system("CLS");
	isLog = 0;
	cout << "you have been log out" << endl;
}

//Check Error

bool isOpenClass(list &a, char ClassID[])
{
	AS_Class_Input(a);
	Class *cur = a.Class_head;
	while (cur != NULL)
	{
		if (strcmp(cur->ClassID, ClassID) == 0) return 1; 
		cur = cur->next;
	}
	return 0;
}
bool isOpenCourse(list &a, char CourseCode[])
{
	AS_Course_Input(a);
	Course *cur = a.Course_head;
	while (cur != NULL)
	{
		if (strcmp(cur->Course_code, CourseCode) == 0) return 1;
		cur = cur->pNext;
	}
	return 0;
}
bool is_textfile_empty(char* filename)
{
	ifstream fin;
	fin.open(filename);
	char k;
	fin >> k;
	if (k == '\0') return 1;

	fin.close();

	return 0;
}

//Function for Academic staff

void Student_Update(list&a, char ClassID[10])
{
	Student *cur = a.Student_head;
	char s1[19] = "Student/";
	unsigned int i, j, n1, n2;

	n1 = strlen(s1);
	n2 = strlen(ClassID);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = ClassID[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s1);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2; i++) {
		s1[i] = s2[j];
		j++;
	}
	ofstream fout;
	fout.open(s1);
	while (cur != NULL)
	{
		//if (cur->next == NULL) continue;
		fout << cur->ID << "," << cur->name << "," << cur->Class << "," << cur->email << "," << cur->mobliephone << "," << cur->gender << endl;
		cur = cur->next;
	}
	fout.close();
}
void AS_Student_Input(list& a, char ClassID[10])
{
	if (isOpenClass(a, ClassID) == 0) { a.Student_head = NULL; return; }
	char s1[19] = "Student/";
	unsigned int i, j, n1, n2;

	n1 = strlen(s1);
	n2 = strlen(ClassID);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = ClassID[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s1);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2; i++) {
		s1[i] = s2[j];
		j++;
	}
	///
	a.Student_head = new Student;
	Student *cur = a.Student_head;
	Student *tm=NULL, *tm1=NULL;
	ifstream fin(s1);
	if (!fin.is_open())
	{
		cur = NULL; cout << "Wrong" << endl;
	}
	else
	{
		if(is_textfile_empty(s1)==1) { 
			a.Student_head = NULL; return; };
		while (fin.good())
		{
			tm1 = tm;
			fin.get(cur->ID, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->name, 1000, ',');
			fin.ignore(100, ',');
			fin.get(cur->Class, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->email, 1000, ',');
			fin.ignore(100, ',');

			fin.get(cur->mobliephone, 1000, ',');
			fin.ignore(100, ',');
			fin >> cur->gender;
			fin.ignore(10, '\n');
			cur->next = new Student;
			tm = cur;
			cur = cur->next;
		}
		tm1->next = NULL;
	}
	fin.close();
}
void AS_Student_Add(list &a)// Add student
{
	char ClassID[10];
	cout << "Input class you want to add student: ";
	cin.get(ClassID, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenClass(a, ClassID) == 0) return;
	AS_Student_Input(a, ClassID);
	Student *cur = a.Student_head;
	if (cur == NULL)
	{
		a.Student_head = new Student;
		cur = a.Student_head;
	}
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = new Student;
		cur = cur->next;
	}
	cur->next = NULL;
	cout << "Input ID: (1751087) ";
	cin.get(cur->ID, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "Input name: (DoTriNhan) ";
	cin.get(cur->name, 1000, '\n');
	cin.ignore(100, '\n');
	cout << "Input class: (17CTT2) ";
	cin.get(cur->Class, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "Input email: (dtnhan@apcs.vn) ";
	cin.get(cur->email, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "Input mobilphone: (01675994743)";
	cin.get(cur->mobliephone, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "Input gender: (0/1)";
	cin >> cur->gender;
	cin.ignore(10, '\n');
	Student_Update(a, ClassID);
	cout << " Add success!!! ";
	cout << "Enter to back menu.";
	int zz = _getch();
}
void AS_Student_Edit(list &a)//8. Edit an existing student  ???
{
	char ClassID[10], StuID[10];
	cout << "Input class you want to edit student: ";
	cin.get(ClassID, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenClass(a, ClassID) == 0) return;
	AS_Student_Input(a, ClassID);
	Student *cur = a.Student_head;
	cout << "Input Student ID you want to edit: ";
	cin.get(StuID, 10, '\n');
	cin.ignore(100, '\n');
	while (cur != NULL)
	{
		if (strcmp(cur->ID, StuID) == 0) break;
		cur = cur->next;
	}
	if (cur == NULL) cout << "There is no student with that name in class";
	else {
		cout << "Edit student " << cur->name << " :"<<endl;
		cout << "Input ID: (1751103) ";
		cin.get(cur->ID, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input name: (ThaiThuanThanh) ";
		cin.get(cur->name, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input class: (17CTT2) ";
		cin.get(cur->Class, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input email: (ttthanh@apcs.vn) ";
		cin.get(cur->email, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input mobilphone: (0123456789) ";
		cin.get(cur->mobliephone, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input gender: (1/0)";
		cin >> cur->gender;
		cin.ignore(10, '\n');
		Student_Update(a, ClassID);
		cout << "Edit success";
	}
	
	cout << "\nEnter to back menu!";
	int zz = _getch();
}
void AS_Student_Remove(list &a)//9. Remove a student
{
	char ClassID[10], StuID[10];
	cout << "Input class you want to remove student: (17CTT2) ";
	cin.get(ClassID, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenClass(a, ClassID) == 0) return;
	AS_Student_Input(a, ClassID);
	Student *cur = a.Student_head;
	cout << "Input Student ID you want to remove: (1751103) ";
	cin.get(StuID, 10, '\n');
	cin.ignore(10, '\n');
	if (cur == NULL) "There is no student with that name in class";
	else
	{
		if (strcmp(cur->ID, StuID) == 0) {
			Student *tm = a.Student_head;
			a.Student_head = a.Student_head->next;
			cur = a.Student_head;
			delete tm;
		}
		else
		{
			while (cur->next != NULL)
			{
				if (strcmp(cur->next->ID, StuID) == 0) break;
				cur = cur->next;
			}
			if (cur->next == NULL) cout << "There is no student with that name in class";
			else {
				cout << "Student " << cur->next->name << " has been removed";
				Student *tm = cur->next;
				cur->next = cur->next->next;
				delete tm;
			}
		}
	}
	Student_Update(a, ClassID);
	cout << "Remove success";
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Student_Move(list &a)//10. Change students from class A to class B
{
	char ClassID_From[10], ClassID_To[10], StuID[10];
	cout << "Input class you want to move student: (17CTT1) ";
	cin.get(ClassID_From, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(100, '\n');
	if (isOpenClass(a, ClassID_From) == 0) return;
	cout << "Input class you want to move student to: (17CTT2) ";
	cin.get(ClassID_To, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenClass(a, ClassID_To) == 0) return;
	AS_Student_Input(a, ClassID_From);
	Student *cur = a.Student_head;
	cout << "Input Student ID you want to move: (1751102) ";
	cin.get(StuID, 10, '\n');
	cin.ignore(100, '\n');
	Student *Move = NULL;
	bool abs = 0;
	if (cur == NULL) "There is no student with that ID in class";
	else
	{
		if (strcmp(cur->ID, StuID) == 0) {
			Move = a.Student_head;
			a.Student_head = a.Student_head->next;
			abs = 1;
		}
		else
		{
			while (cur->next != NULL)
			{
				if (strcmp(cur->next->ID, StuID) == 0) break;
				cur = cur->next;
			}
			if (cur->next == NULL) cout << "There is no student with that ID in class";
			else {
				Move = cur->next;
				cur->next = cur->next->next;
				abs = 1;
			}
		}
		Student_Update(a, ClassID_From);
	}
	if (abs == 1)
	{
		AS_Student_Input(a, ClassID_To);
		cur = a.Student_head;
		if (cur == NULL)
		{
			a.Student_head = new Student;
			cur = a.Student_head;
		}
		else
		{
			while (cur->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = Move;
			cur = cur->next;
		}
		cur->next = NULL;
		cout << "Student have been move!";
		Student_Update(a, ClassID_To);
	}
	cout << "Move success";
	cout << "\nEnter to back menu.";
	int zz = _getch();
}

void Class_Update(list&a) {
	Class *cur = a.Class_head;
	ofstream fout("class.csv");
	if (!fout.is_open()) return;
	else
	{
		while (cur != NULL)
		{
			fout << cur->ClassID << endl;
			cur = cur->next;
		}
	}
	fout.close();
}
void AS_Class_Input(list &a)
{
	a.Class_head = new Class;
	Class *cur = a.Class_head, *tm = NULL,*tm1=NULL;
	ifstream fin("class.csv");
	if (!fin.is_open()) { cur = NULL; cout << "Wrong" << endl; }
	else
	{
		while (fin.good())
		{
			tm1 = tm;
			fin.get(cur->ClassID, 10, '\n');   //.Eg : CTT008, CS161
			fin.ignore(10, '\n');
			cur->next = new Class;
			tm = cur;
			cur = cur->next;
		}
		tm1->next = NULL;
	}
	fin.close();
}
void AS_Class_Add(list &a)//11. Add a new empty class     // tao them node+ tao file csv trong folder class
{
	char CID[11];
	AS_Class_Input(a);
	cout << "Input the name of class you want to add: (1751103) ";
	cin.get(CID, 10, '\n');
	cin.ignore(10, '\n');
	Class *cur = a.Class_head;
	bool avb = 1;
	if (cur == NULL)
	{
		a.Class_head = new Class;
		cur = a.Class_head;
	}
	else
	{
		while (cur->next != NULL)
		{
			if (strcmp(cur->ClassID, CID )== 0)  avb = 0;
			cur = cur->next;
		}
		cur->next = new Class;
	}
	cur->next->next = NULL;
	if (avb == 1)
	{
		cur = cur->next;
		strcpy_s(cur->ClassID, CID);
		Class_Update(a);

		char s1[19] = "Student/";
		unsigned int i, j, n1, n2;

		n1 = strlen(s1);
		n2 = strlen(CID);

		j = 0;
		for (i = n1; i < n1 + n2 + 1; i++) {
			s1[i] = CID[j];
			j++;
		}
		///
		char s2[] = ".csv";
		n1 = strlen(s1);
		n2 = strlen(s2);
		j = 0;
		for (i = n1; i < n1 + n2 + 1; i++) {
			s1[i] = s2[j];
			j++;
		}
		std::ofstream outfile(s1);
		/////////////
		char s3[20] = "Schedule/";
		n1 = strlen(s3);
		n2 = strlen(CID);

		j = 0;
		for (i = n1; i < n1 + n2 + 1; i++) {
			s3[i] = CID[j];
			j++;
		}
		///
		strcpy_s(s2, ".csv");
		n1 = strlen(s3);
		n2 = strlen(s2);

		j = 0;
		for (i = n1; i < n1 + n2 + 1; i++) {
			s3[i] = s2[j];
			j++;
		}
		ofstream outfile3(s3);
		outfile3.close();

		cout << "Add success";
	}
	else {
		cur->next = NULL; cout << "There has the same class";
	}
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Class_View(list &a)//12. View list of classes
{
	AS_Class_Input(a);
	Class *cur = a.Class_head;
	while (cur != NULL)
	{
		cout << cur->ClassID << endl;
		cur = cur->next;
	}
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Class_StudentView(list &a)//13. View list of students in a class
{
	char ClassID[10];
	cout << "Input class you want to view student list: (17CTT2)";
	cin.get(ClassID, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	AS_Student_Input(a, ClassID);
	Student *cur = a.Student_head;
	if (cur == NULL)
	{
		cout << "Class is not exit" << endl;
	}
	else
	{
		while (cur != NULL)
		{
			cout << cur->ID << " " << cur->name << " " << cur->Class << " " << cur->email << " " << cur->mobliephone << " " << cur->gender << endl;
			cur = cur->next;
		}
	}
	cout << "\nEnter to back menu.";
	int zz = _getch();
}

void Course_Update(list&a) {
	Course *cur = a.Course_head;
	ofstream fout("Course.csv");
	if (!fout.is_open()) return;
	else
	{
		while (cur != NULL)
		{
			fout << cur->Course_code<<"," ;
			fout << cur->Lecture << ",";
			fout << cur->NumSD << ",";
			for (int i = 0; i < cur->NumSD - 1; i++)
			{
				fout<<cur->StudentID[i]<<",";
			}
			if (cur->pNext == NULL) fout << cur->StudentID[cur->NumSD - 1];
			else fout << cur->StudentID[cur->NumSD - 1] << endl;
			cur = cur->pNext;
		}
	}
	fout.close();
}
void AS_Course_Input(list &a)
{
	a.Course_head = NULL;
	Course *cur = a.Course_head, *tm = NULL, *tm1 = NULL;
	ifstream fin("Course.csv");
	if (!fin.is_open()) { cur = NULL; cout << "Wrong" << endl; }
	else
	{
		while (fin.good())
		{
			if (a.Course_head == NULL)
			{
				a.Course_head = new Course;
				cur = a.Course_head;
			}
			else {
				cur->pNext = new Course;
				cur = cur->pNext;
			}
			fin.get(cur->Course_code, 100, ',');   //.Eg : CTT008, CS161
			fin.ignore(10, ',');
			fin.get(cur->Lecture, 19, ',');
			fin.ignore(19, ',');
			fin >> cur->NumSD;
			for (int i = 0; i < cur->NumSD - 1; i++)
			{
				fin.ignore(19, ',');
				fin.get(cur->StudentID[i], 19, ',');
			}
			fin.ignore(19, ',');
			fin.get(cur->StudentID[cur->NumSD - 1], 19, '\n');
			fin.ignore(19, '\n');
		}
		cur->pNext = NULL;
	}
	fin.close();
}
void AS_Course_Add(list &a)//15. Add a new course
{
	char CourseCode[10];
	cout << "Input course you want to add: ";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	AS_Course_Input(a);
	Course *cur = a.Course_head;
	if (cur == NULL)
	{
		a.Course_head = new Course;
		cur = a.Course_head;
	}
	else
	{
		while (cur->pNext != NULL)
		{
			cur = cur->pNext;
		}
		cur->pNext = new Course;
		cur = cur->pNext;
	}
	cur->pNext = NULL;
	strcpy_s(cur->Course_code, CourseCode);
	cout << "Input lecture: ";
	cin.get(cur->Lecture, 19, '\n');
	cin.ignore(10, '\n');
	cout << "Input Number student of course: ";
	cin >> cur->NumSD;
	cin.ignore(10, '\n');
	for (int i = 0; i < cur->NumSD ; i++)
	{
		cout << "student "<<i+1<<" :";
		cin.get(cur->StudentID[i], 19, '\n');
		cin.ignore(19, '\n');
	}
	Course_Update(a);

	char s3[21] = "Presence/";
	unsigned int i, j, n1, n2;
	n1 = strlen(s3);
	n2 = strlen(CourseCode);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s3[i] = CourseCode[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s3);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s3[i] = s2[j];
		j++;
	}
	ofstream outfile3(s3);
	outfile3.close();
	/////
	cout << "Add success";
	char s1[18] = "Score/";

	n1 = strlen(s1);
	n2 = strlen(CourseCode);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = CourseCode[j];
		j++;
	}
	///
	strcpy_s(s2, ".csv");
	n1 = strlen(s1);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = s2[j];
		j++;
	}
	ofstream outfile1(s1);
	outfile1.close();
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Course_Edit(list &a)//16. Edit an existing course
{
	char CourseCode[10];
	cout << "Input course you want to edit:(CS162) ";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	AS_Course_Input(a);
	Course *cur = a.Course_head;
	while (cur != NULL)
	{
		if (strcmp(cur->Course_code, CourseCode) == 0) break;
		cur = cur->pNext;
	}
	if (cur == NULL) cout << "There is no student in class";
	else {
		cout << "Edit Code " << cur->Course_code << " :"<<endl;
		cout << "Input Course Code: ";
		cin.get(cur->Course_code, 1000, '\n');   //.Eg : CTT008, CS161
		cin.ignore(10, '\n');
		cout << "Input lecture: ";
		cin.get(cur->Lecture, 19, '\n');
		cin.ignore(10, '\n');
		cout << "Input Number student of course: ";
		cin >> cur->NumSD;
		cin.ignore(10, '\n');
		for (int i = 0; i < cur->NumSD; i++)
		{
			cout << "student " << i + 1 << " :";
			cin.get(cur->StudentID[i], 19, '\n');
			cin.ignore(19, '\n');
		}
		Course_Update(a);
	}
	cout << "Edit success!"<<endl;
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Course_Remove(list &a)//17. Remove a course
{
	char CourseCode[10];
	cout << "Input course you want to remove: (CS162) ";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	AS_Course_Input(a);
	Course *cur = a.Course_head;
	if (cur == NULL) "There is no avaiable course";
	else
	{
		if (strcmp(cur->Course_code, CourseCode) == 0) {
			Course *tm = a.Course_head;
			a.Course_head = a.Course_head->pNext;
			cur = a.Course_head;
			//////
			char s3[19] = "Presence/";
			unsigned int i, j, n1, n2;
			n1 = strlen(s3);
			n2 = strlen(CourseCode);

			j = 0;
			for (i = n1; i<n1 + n2 + 1; i++) {
				s3[i] = CourseCode[j];
				j++;
			}
			//
			char s2[] = ".csv";
			n1 = strlen(s3);
			n2 = strlen(s2);

			j = 0;
			for (i = n1; i<n1 + n2 + 1; i++) {
				s3[i] = s2[j];
				j++;
			}
			DeleteFile(s3);
			//
			cout << "Add success";
			char s1[16] = "Score/";

			n1 = strlen(s1);
			n2 = strlen(CourseCode);

			j = 0;
			for (i = n1; i<n1 + n2 + 1; i++) {
				s1[i] = CourseCode[j];
				j++;
			}
			///
			strcpy_s(s2, ".csv");
			n1 = strlen(s1);
			n2 = strlen(s2);

			j = 0;
			for (i = n1; i<n1 + n2 + 1; i++) {
				s1[i] = s2[j];
				j++;
			}
			DeleteFile(s1);
			delete tm;
		}
		else
		{
			while (cur->pNext != NULL)
			{
				if (strcmp(cur->pNext->Course_code, CourseCode) == 0) break;
				cur = cur->pNext;
			}
			if (cur->pNext == NULL) cout << "There is no student with that name in class";
			else {
				Course *tm = cur->pNext;
				cur->pNext = cur->pNext->pNext;
				char s3[19] = "Presence/";
				unsigned int i, j, n1, n2;
				n1 = strlen(s3);
				n2 = strlen(CourseCode);

				j = 0;
				for (i = n1; i<n1 + n2 + 1; i++) {
					s3[i] = CourseCode[j];
					j++;
				}
				//
				char s2[] = ".csv";
				n1 = strlen(s3);
				n2 = strlen(s2);

				j = 0;
				for (i = n1; i<n1 + n2 + 1; i++) {
					s3[i] = s2[j];
					j++;
				}
				DeleteFile(s3);
				//
			
				char s1[16] = "Score/";

				n1 = strlen(s1);
				n2 = strlen(CourseCode);

				j = 0;
				for (i = n1; i<n1 + n2 + 1; i++) {
					s1[i] = CourseCode[j];
					j++;
				}
				///
				strcpy_s(s2, ".csv");
				n1 = strlen(s1);
				n2 = strlen(s2);

				j = 0;
				for (i = n1; i<n1 + n2 + 1; i++) {
					s1[i] = s2[j];
					j++;
				}
				DeleteFile(s1);
				
				cout << "Course " << tm << " has been removed"<<endl;
				delete tm;

			}
		}
	}
	Course_Update(a);
	cout << "Remove success!";
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Course_View(list &a)//18. View list of courses
{
	AS_Course_Input(a);
	Course *cur = a.Course_head;
	while (cur != NULL)
	{
		cout << cur->Course_code << endl;
		cout << cur->Lecture << endl;
		cout << cur->NumSD << endl;
		for (int i = 0; i < cur->NumSD - 1; i++)
		{
			cout << cur->StudentID[i] << endl;
		}
		cout << cur->StudentID[cur->NumSD - 1] << endl;
		cout << "----------------------------------------------" << endl;
		cur = cur->pNext;
	}
	cout << "\nEnter to back menu.";
	int zz = _getch();
}

bool isCollision(Schedule a, Schedule b)
{
	if (strcmp(a.Dateofweek, b.Dateofweek) != 0) return false;
	else
	{
		int frA = 0, frB = 0, toA = 0, toB = 0;
		int i = 0;
		while (a.From[i] != ':' && b.From[i] != ':')
		{
			frA += 10 * frA + (a.From[i] - 48);
			frB += 10 * frB + (b.From[i] - 48);
			i++;
		}
		i = 0;
		while (a.To[i] != ':' && b.To[i] != ':')
		{
			toA += 10 * toA + (a.To[i] - 48);
			toB += 10 * toB + (b.To[i] - 48);
		}
		if (frA == frB || toA == toB) return true;
		else if ((frA<frB && frA>toB) || (toA<frB && toA>toB)) return true;
		else if ((toA > frB) || (frA < toB)) return false;
		else if ((toA == frB) || (frA == toB))
		{
			int minfrA, minfrB, mintoA, mintoB;
			minfrA = minfrB = mintoA = mintoB = 0;
			for (int i = 0; i < strlen(a.To); i++)
			{
				if (a.To[i] == ':')
				{
					for (int j = i + 1; j < strlen(a.To); j++)
					{
						minfrA += 10 * minfrA + (a.From[j] - 48);
						minfrB += 10 * minfrB + (b.From[j] - 48);
						mintoA += 10 * mintoA + (a.To[j] - 48);
						mintoB += 10 * mintoB + (a.To[j] - 48);
					}
				}
				break;
			}
			if (minfrA > mintoB || mintoA < minfrB) return false;
			else return true;
		}
	}
}
void Schedule_Update(list&a, char ClassID[10]) {
	Schedule *cur = a.Schedule_head;
	char s1[201] = "Schedule/";
	unsigned int i, j, n1, n2;
	if (cur == NULL) return;
	n1 = strlen(s1);
	n2 = strlen(ClassID);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = ClassID[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s1);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2; i++) {
		s1[i] = s2[j];
		j++;
	}
	ofstream fout;
	fout.open(s1);
	if (!fout.is_open()) return;
	else
	{
		while (cur != NULL)
		{
			fout << cur->Course_code << "," << cur->Year << "," << cur->Semester << "," << cur->Course_name << "," << cur->Lecturer << "," << cur->Start << "," << cur->End << "," << cur->From << "," << cur->To << "," << cur->Dateofweek << endl;
			cur = cur->pNext;
		}
	}
	fout.close();
}
void AS_Schedule_Input(list &a, char ClassID[10])
{
	char s1[201] = "Schedule/";
	unsigned int i, j, n1, n2;

	n1 = strlen(s1);
	n2 = strlen(ClassID);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = ClassID[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s1);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2; i++) {
		s1[i] = s2[j];
		j++;
	}
	///
	a.Schedule_head = new Schedule;
	Schedule *cur = a.Schedule_head, *tm = NULL,*tm1=NULL;
	ifstream fin(s1);
	if (!fin.is_open())
	{
		cur = NULL; cout << "Wrong Schedule class" << endl;
	}
	else
	{
		if (is_textfile_empty(s1) == 1) {
			a.Schedule_head = NULL; return;
		};
		while (fin.good())
		{
			tm1 = tm;
			fin.get(cur->Course_code, 1000, ',');   //.Eg : CTT008, CS161
			fin.ignore(10, ',');
			fin.get(cur->Year, 1000, ',');			//.Eg : 2016 - 2017
			fin.ignore(10, ',');
			fin >> cur->Semester;				//.Eg : 1, 2, 3
			fin.ignore(10, ',');
			fin.get(cur->Course_name, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->Lecturer, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->Start, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->End, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->From, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->To, 1000, ',');
			fin.ignore(10, ',');
			fin.get(cur->Dateofweek, 1000, '\n');
			fin.ignore(10, '\n');
			cur->pNext = new Schedule;
			tm = cur;
			cur = cur->pNext;
		}
		tm1->pNext = NULL;
	}
	fin.close();
}
void AS_Schedule_Add(list &a)//15. Add a new course
{
	char ClassID[10];
	cout << "Input class you want to add course: (17CTT2) ";
	cin.get(ClassID, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenClass(a,ClassID) == 0) return;
	AS_Schedule_Input(a, ClassID);
	Schedule *cur = a.Schedule_head;
	Schedule *tm = NULL;
	if (cur == NULL)
	{
		a.Schedule_head = new Schedule;
		cur = a.Schedule_head;
	}
	else
	{
		while (cur->pNext != NULL)
		{
			cur = cur->pNext;
		}
		cur->pNext = new Schedule;
		tm = cur;
		cur = cur->pNext;
	}
	cur->pNext = NULL;
	cout << "Input Course code: (CS162)";
	cin.get(cur->Course_code, 1000, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	cout << "Input Year: (2016-2017) ";
	cin.get(cur->Year, 1000, '\n');			//.Eg : 2016 - 2017
	cin.ignore(10, '\n');
	cout << "Input Semester: (1/2/3)";
	cin >> cur->Semester;				//.Eg : 1, 2, 3
	cin.ignore(10, '\n');
	cout << "Input Course name: (General Physics) ";
	cin.get(cur->Course_name, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "Input Lecturer: (Dinh Ba Tien) ";
	cin.get(cur->Lecturer, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "When course start: (7/5/2018)";
	cin.get(cur->Start, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "End: (6/9/2018)";
	cin.get(cur->End, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "Course start: (16:00)";
	cin.get(cur->From, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "To: (19:00)";
	cin.get(cur->To, 1000, '\n');
	cin.ignore(10, '\n');
	cout << "Input Date of week: (2,3,4,...,7)";
	cin.get(cur->Dateofweek, 1000, '\n');
	cin.ignore(10, '\n');;
	if (isCollision(*tm, *cur) == 1)
	{
		cout << "The course is collision, Try again";
		tm->pNext = NULL;
		delete cur;
	}
	Schedule_Update(a, ClassID);
	cout << "Add success!";
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Schedule_Edit(list &a)//16. Edit an existing course
{
	char ClassID[10], Sche[10];
	cout << "Input class you want to edit student: (17CTT2) ";
	cin.get(ClassID, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenClass(a, ClassID) == 0) return;
	AS_Schedule_Input(a, ClassID);
	Schedule *cur = a.Schedule_head;
	cout << "Input course you want to edit: (CS162) ";
	cin.get(Sche, 10, '\n');
	cin.ignore(100, '\n');
	while (cur != NULL)
	{
		if (strcmp(cur->Course_code, Sche) == 0) break;
		cur = cur->pNext;
	}
	if (cur == NULL) cout << "There is no course with that name in schedule";
	else {
		cout << "Edit Schedule of " << cur->Course_code << " :"<<endl;
		cout << "Input Course Code: (CT008)";
		cin.get(cur->Course_code, 1000, '\n');   //.Eg : CTT008, CS161
		cin.ignore(10, '\n');
		cout << "Input Year: (2016-2017) ";
		cin.get(cur->Year, 1000, '\n');			//.Eg : 2016 - 2017
		cin.ignore(10, '\n');
		cout << "Input Semester: (1/2/3)";
		cin >> cur->Semester;				//.Eg : 1, 2, 3
		cin.ignore(10, '\n');
		cout << "Input Course name: (Computer Science) ";
		cin.get(cur->Course_name, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input Lecturer: (Nguyen Huu Nha) ";
		cin.get(cur->Lecturer, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input Start: (2016) ";
		cin.get(cur->Start, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input End: (2017)";
		cin.get(cur->End, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input hour From: (06:00) ";
		cin.get(cur->From, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input hour To: (09:00) ";
		cin.get(cur->To, 1000, '\n');
		cin.ignore(10, '\n');
		cout << "Input Dateofweek: (2,3,4,...,7)";
		cin.get(cur->Dateofweek, 1000, '\n');
		cin.ignore(10, '\n');
		Schedule_Update(a, ClassID);
		cout << "Edit success!";
		cout << "\nEnter to back menu.";
		int zz = _getch();
	}
}
void AS_Schedule_Remove(list &a)//17. Remove a course
{
	char ClassID[10], Sche[10];
	cout << "Input class you want to remove course: (17CTT2) ";
	cin.get(ClassID, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenClass(a, ClassID) == 0) return;
	AS_Schedule_Input(a, ClassID);
	Schedule *cur = a.Schedule_head;
	cout << "Input course you want to remove from schedule: (CS162)";
	cin.get(Sche, 10, '\n');
	cin.ignore(10, '\n');
	if (cur == NULL) "There is no course with that name in class schedule";
	else
	{
		if (strcmp(cur->Course_code, Sche) == 0) {
			Schedule *tm = a.Schedule_head;
			a.Schedule_head = a.Schedule_head->pNext;
			cur = a.Schedule_head;
			delete tm;
		}
		else
		{
			while (cur->pNext != NULL)
			{
				if (strcmp(cur->pNext->Course_code, Sche) == 0) break;
				cur = cur->pNext;
			}
			if (cur->pNext == NULL) cout << "There is no course with that name in class";
			else {
				Schedule *tm = cur->pNext;
				cur->pNext = cur->pNext->pNext;
				
				cout << "Course " << tm << " has been removed from schedule";
				delete tm;
			}
		}
	}
	Schedule_Update(a, ClassID);
	cout << "Remove success!";
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Schedule_View(list &a)//18. View list of courses
{
	char ClassID[10];
	cout << "Input class you want to view schedule: (17CTT2) ";
	cin.get(ClassID, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenClass(a, ClassID) == 0) return;
	AS_Schedule_Input(a, ClassID);
	Schedule *cur = a.Schedule_head;
	if (cur == NULL)
	{
		cout << "There is no course in schedule" << endl;
	}
	else
	{
		while (cur != NULL)
		{
			cout << cur->Course_code << " " << cur->Year << " " << cur->Semester << " " << cur->Course_name << " " << cur->Lecturer << " " << cur->Start << " " << cur->End << " " << cur->From << " " << cur->To << " " << cur->Dateofweek << endl;
			cur = cur->pNext;
		}
	}
	cout << "\nEnter to back menu.";
	int zz = _getch();
}

void Presence_Update(list&a, char CourseCode[10])
{
	Presence *cur = a.Presence_head;
	char s3[20] = "Presence/";
	unsigned int i, j, n1, n2;
	n1 = strlen(s3);
	n2 = strlen(CourseCode);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s3[i] = CourseCode[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s3);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2; i++) {
		s3[i] = s2[j];
		j++;
	}
	///
	ofstream fout;
	fout.open(s3);
	while (cur != NULL)
	{
		
		fout << cur->StudentID << ",";
		fout << cur->Week;
		for (int m = 0; m < cur->Week; m++)
		{
			fout << "," << cur->check[m];
		}
		fout << endl;
		cur = cur->next;
	}
	fout.close();
}
void AS_Presence_Input(list& a, char CourseCode[10])
{
	char s3[20] = "Presence/";
	unsigned int i, j, n1, n2;
	n1 = strlen(s3);
	n2 = strlen(CourseCode);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s3[i] = CourseCode[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s3);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2; i++) {
		s3[i] = s2[j];
		j++;
	}
	a.Presence_head = new Presence;
	Presence *cur = a.Presence_head, *tm = NULL, *tm1=NULL;
	ifstream fin(s3);
	if (!fin.is_open()) {
		cur = NULL;
		cout << "wrong" << endl;
	}
	else
	{
		if (is_textfile_empty(s3) == 1) {
			a.Presence_head = NULL; return;
		};
		while (fin.good())
		{
			tm1 = tm;
			fin.get(cur->StudentID, 1000, ',');
			fin.ignore(10, ',');
			fin >> cur->Week;
			fin.ignore(100, ',');
			for (int m = 0; m < cur->Week; m++)
			{
				fin >> cur->check[m];
				if(m==cur->Week-1) fin.ignore(100, '\n');
				else fin.ignore(100, ',');
			}
			cur->next = new Presence;
			tm = cur;
			cur = cur->next;
		}
		tm1->next = NULL;
	}
	fin.close();
}
void AS_Presence_View(list &a)//24. Search and view attendance list of a course
{
	char CourseCode[10];
	cout << "Input course you want to view presence list: (CS162) ";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	AS_Presence_Input(a, CourseCode);
	Presence *cur = a.Presence_head;
	if (cur == NULL)
	{
		cout << "There is no student in class" << endl;
	}
	else
	{
		while (cur != NULL)
		{
			
			cout << cur->StudentID << " ";
			cout << cur->Week << " ";
			for (int m = 0; m < cur->Week; m++)
			{
				cout << cur->check[m] << " ";
			}
			cout << endl;
			cur = cur->next;
		}
	}
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Presence_Export(list &a)//25. Export attendance list to a csv file
{
	char CourseCode[100];
	cout << "Input course you want to Export: (CS162) ";
	cin.get(CourseCode, 100, '\n');
	cin.ignore(100, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	char s3[19] = "Presence/";
	unsigned int i, j, n1, n2;
	n1 = strlen(s3);
	n2 = strlen(CourseCode);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s3[i] = CourseCode[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s3);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s3[i] = s2[j];
		j++;
	}
	Presence *cur = a.Presence_head;
	ofstream fout(s3);
	if (!fout.is_open()) cout << "Wrong" << endl;
	else
	{
		while (cur != NULL)
		{
			fout <<  cur->StudentID << "," << cur->Week;
			for (int m = 0; m < cur->Week; m++)
			{
				fout << cur->check[m];
			}
			fout << endl;
			cur = cur->next;
		}
	}
	fout.close();
}

void Score_Update(list&a, char CourseCode[10])
{
	Score *cur = a.Score_head;
	char s1[17] = "Score/";
	unsigned int i, j, n1, n2;

	n1 = strlen(s1);
	n2 = strlen(CourseCode);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = CourseCode[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s1);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2; i++) {
		s1[i] = s2[j];
		j++;
	}
	///
	ofstream fout;
	fout.open(s1);
	while (cur != NULL)
	{
		fout << cur->StudentID << ",";
		fout << cur->Midterm_score << ",";
		fout << cur->Lab_score << ",";
		fout << cur->Final_score;
		fout << endl;
		cur = cur->next;
	}
	fout.close();
}
void AS_Score_Input(list& a, char CourseCode[10])
{
	char s1[17] = "Score/";
	unsigned int i, j, n1, n2;

	n1 = strlen(s1);
	n2 = strlen(CourseCode);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = CourseCode[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s1);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2; i++) {
		s1[i] = s2[j];
		j++;
	}
	///
	a.Score_head = new Score;
	Score *cur = a.Score_head, *tm = NULL, *tm1=NULL;
	ifstream fin(s1);
	if (!fin.is_open()) { cur = NULL; cout << "Wrong" << endl; }
	else
	{
		if (is_textfile_empty(s1) == 1) {
			a.Score_head = NULL; return;
		};
		while (fin.good())
		{
			tm1 = tm;
			fin.get(cur->StudentID, 1000, ',');
			fin.ignore(10, ',');
			fin >> cur->Midterm_score;
			fin.ignore(10, ',');
			fin >> cur->Lab_score;
			fin.ignore(10, ',');
			fin >> cur->Final_score;
			fin.ignore(100, '\n');
			cur->next = new Score;
			tm = cur;
			cur = cur->next;
		}
		tm1->next = NULL;
	}
	fin.close();
}
void AS_Score_View(list &a)//26. Search and view scoreboard of a course
{
	char CourseCode[10];
	cout << "Input course you want to view score list: (CS162) ";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	AS_Score_Input(a, CourseCode);
	Score *cur = a.Score_head;
	if (cur == NULL)
	{
		cout << "There is no student in course" << endl;
	}
	else
	{
		while (cur != NULL)
		{
			
			cout << cur->StudentID << " ";
			cout << cur->Midterm_score << " ";
			cout << cur->Lab_score << " ";
			cout << cur->Final_score;
			cout << endl;
			cur = cur->next;
		}
	}
	cout << "Successful!";
	cout << "\nEnter to back menu.";
	int zz = _getch();
}
void AS_Score_Export(list &a)//27. Export a scoreboard to a csv file*                                           //
{
	char CourseCode[100];
	cout << "Input course you want to Export: (CS162) ";
	cin.get(CourseCode, 100, '\n');
	cin.ignore(100, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	char s1[16] = "Score/";
	unsigned int i, j, n1, n2;

	n1 = strlen(s1);
	n2 = strlen(CourseCode);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = CourseCode[j];
		j++;
	}
	///
	char s2[] = ".csv";
	n1 = strlen(s1);
	n2 = strlen(s2);

	j = 0;
	for (i = n1; i<n1 + n2 + 1; i++) {
		s1[i] = s2[j];
		j++;
	}
	///
	Score *cur = a.Score_head;
	ofstream fout(s1);
	if (!fout.is_open()) cout << "Wrong" << endl;
	else
	{
		while (cur != NULL)
		{
			fout <<  cur->StudentID << "," << cur->Midterm_score << "," << cur->Lab_score << "," << cur->Final_score;
			fout << endl;
			cur = cur->next;
		}
		cur->next = NULL;
	}
	fout.close();

}

//Function for lecturer
void Lec_Score_Add(list &a)//28. Import scoreboard of a course(midterm, final, lab, bonus)
{
	char CourseCode[100];
	cout << "Input the course you want to add score: (CS162) ";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	AS_Score_Input(a, CourseCode);
	Score *cur = a.Score_head;
	if (cur == NULL)
	{
		cout << "There is no student in course" << endl;
	}
	else
	{
		while (cur != NULL)
		{
			cout << "Input score of " << cur->StudentID << ": " << endl;
			cout << "Midterm: ";
			cin >> cur->Midterm_score;
			cout << "Lab: ";
			cin >> cur->Lab_score;
			cout << "Final: ";
			cin >> cur->Final_score;
			cin.ignore(100, '\n');
			float GPA = 0.3*cur->Lab_score + 0.3*cur->Midterm_score + 0.4*cur->Final_score;
			cout.precision(3);
			std::cout << "GPA: "<<GPA << '\n';
			std::cout.unsetf(std::ios::floatfield);
			cout << "Score has been added";
			cout << endl;
			cout << endl;
			cur = cur->next;
		}
	}
	Score_Update(a, CourseCode);
	cout << "Enter to back menu!";
	int zz = _getch();
}
void Lec_Score_Edit(list &a)//29. Edit grade of a student
{
	char CourseCode[10], StuID[10];
	cout << "Input the class you want to edit score: (17CTT2) ";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	AS_Score_Input(a, CourseCode);
	Score *cur = a.Score_head;
	cout << "Input Student ID you want to edit score: (17CTT2) ";
	cin.get(StuID, 10, '\n');
	cin.ignore(100, '\n');
	while (cur != NULL)
	{
		if (strcmp(cur->StudentID, StuID) == 0) break;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		cout << "There is no student with that ID in course" << endl;
	}
	else
	{
		cout << "Input score of " << cur->StudentID << ": " << endl;
		cout << "Midterm: ";
		cin >> cur->Midterm_score;
		cout << "Lab: ";
		cin >> cur->Lab_score;
		cout << "Final: ";
		cin >> cur->Final_score;
		cin.ignore(100, '\n');
		cout << endl;
		cout << endl;
	}
	Score_Update(a, CourseCode);
	cout << "Edit success!";
	cout << "Enter to back menu!";
	int zz = _getch();
}
void Lec_Score_View(list &a)//30. View a scoreboard*/
{
	char CourseCode[10];
	cout << "Input course you want to view score list: (CS162)";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	AS_Score_Input(a, CourseCode);
	Score *cur = a.Score_head;
	if (cur == NULL)
	{
		cout << "There is no student in course" << endl;
	}
	else
	{
		while (cur != NULL)
		{
			cout << cur->StudentID << " ";
			cout << cur->Midterm_score << " ";
			cout << cur->Lab_score << " ";
			cout << cur->Final_score;
			cout << endl;
			cur = cur->next;
		}
	}
	cout << "\nEnter to back menu!";
	int zz = _getch();
}
//Function for student

void Stu_Presence_Check(list &a, User &login)// Check-in.
{
	char CourseCode[10];
	cout << "Input the course you want to checkin: (CS162)";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	AS_Presence_Input(a, CourseCode);
	Presence *cur = a.Presence_head;
	while (cur != NULL)
	{
		if (strcmp(cur->StudentID, login.username) == 0) break;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		cout << "Your did't sign in for the course before" << endl;
	}
	else
	{
		cur->Week++;
		cur->check[cur->Week - 1] = 1;
		cout << "check in success!";
		cout << endl;
		cout << endl;
	}
	Presence_Update(a, CourseCode);
	cout << "\nEnter to back menu!";
	int zz = _getch();
}                                                            
void Stu_Presence_View(list &a,User &login)// View check-in resul
{
	char CourseCode[10];
	cout << "Input course you want to view presence list: (CS162)";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	AS_Presence_Input(a, CourseCode);
	Presence *cur = a.Presence_head;
	while (cur != NULL)
	{
		if (strcmp(cur->StudentID, login.username) == 0) break;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		cout << "Your did't sign in for the course before" << endl;
	}
	else
	{
		
		cout << cur->StudentID << " ";
		cout << cur->Week << " ";
		for (int m = 0; m < cur->Week; m++)
		{
			cout << cur->check[m] << " ";
		}
		cout << endl;
	}
	cout << "\nEnter to back menu!";
	int zz = _getch();
}
void Stu_Score_View(list &a, User &login)// View his/her scores of a course
{
	char CourseCode[10];
	cout << "Input course you want to view score list: (CS162) ";
	cin.get(CourseCode, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenCourse(a, CourseCode) == 0) return;
	AS_Score_Input(a, CourseCode);
	Score *cur = a.Score_head;
	while (cur != NULL)
	{
		if (strcmp(cur->StudentID, login.username) == 0) break;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		cout << "Your did't sign in for the course before" << endl;
	}
	else
	{
		cout << cur->StudentID << " ";
		cout << cur->Midterm_score << " ";
		cout << cur->Lab_score << " ";
		cout << cur->Final_score;
		cout << endl;
	}
	cout << "\nEnter to back menu!";
	int zz = _getch();
}
void Stu_Schedule_View(list &a)// View schedules
{
	char ClassID[10];
	cout << "Input your class to view schedule: (17CTT1) ";
	cin.get(ClassID, 10, '\n');   //.Eg : CTT008, CS161
	cin.ignore(10, '\n');
	if (isOpenClass(a, ClassID) == 0) return;
	AS_Schedule_Input(a, ClassID);
	Schedule *cur = a.Schedule_head;
	if (cur == NULL)
	{
		cout << "There is no course in schedule" << endl;
	}
	else
	{
		while (cur != NULL)
		{
			cout << cur->Course_code << " " << cur->Year << " " << cur->Semester << " " << cur->Course_name << " " << cur->Lecturer << " " << cur->Start << " " << cur->End << " " << cur->From << " " << cur->To << " " << cur->Dateofweek << endl;
			cur = cur->pNext;
		}
	}
	cout << "\nEnter to back menu!";
	int zz = _getch();
}   