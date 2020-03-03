#include "Header.h"
void centerstring(char* s)
{
	int l = strlen(s);
	int pos = (int)((250 - l) / 2);
	for (int i = 0; i<pos; i++)
	cout << " ";
	cout << s;
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void Console_Window_Set()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1000, 500, TRUE);
	Sleep(1000000000);
	MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void Cursor(int &x, int &y)
{
	textcolor(12);
	gotoxy(x, y);
	cout << ">>";
	char a;
	a = _getch();
	gotoxy(++x, y);
	cout << " ";
	gotoxy(--x, y);

	while (int(a) != 13)
	{
		switch (a)
		{
		case 'a':
		{

			gotoxy(x, y);
			cout << " ";
			x -= 30;
			if (x < 5) x += 30;
			gotoxy(x, y);
			cout << ">>";
			break;
		}
		case 's':
		{
			gotoxy(x, y);
			cout << " ";
			y += 10;
			if (y > 35) y -= 10;
			gotoxy(x, y);
			cout << ">>";
			break;
		}
		case 'd':
		{
			gotoxy(x, y);
			cout << " ";
			x += 30;
			if (x > 80) x -= 30;
			gotoxy(x, y);
			cout << ">>";
			break;
		}
		case 'w':
		{
			gotoxy(x, y);
			cout << " ";
			y -= 10;
			if (y < 10) y += 10;
			gotoxy(x, y);
			cout << ">>";
			break;
		}
		};
		a = _getch();
		gotoxy(++x, y);
		cout << " ";
		gotoxy(--x, y);
	}
	system("CLS");
}
void Cursor2(int &x, int &y)
{
	textcolor(12);
	gotoxy(x, y);
	cout << ">>";
	char a;
	a = _getch();
	gotoxy(++x, y);
	cout << " ";
	gotoxy(--x, y);

	while (int(a) != 13)
	{
		switch (a)
		{
		case 'a':
		{

			gotoxy(x, y);
			cout << " ";
			x -= 30;
			if (x < 5) x += 30;
			gotoxy(x, y);
			cout << ">>";
			break;
		}
		case 's':
		{
			gotoxy(x, y);
			cout << " ";
			y += 5;
			if (y > 46) y -= 5;
			gotoxy(x, y);
			cout << ">>";
			break;
		}
		case 'd':
		{
			gotoxy(x, y);
			cout << " ";
			x += 30;
			if (x > 80) x -= 30;
			gotoxy(x, y);
			cout << ">>";
			break;
		}
		case 'w':
		{
			gotoxy(x, y);
			cout << " ";
			y -= 5;
			if (y < 9) y += 5;
			gotoxy(x, y);
			cout << ">>";
			break;
		}
		};
		a = _getch();
		gotoxy(++x, y);
		cout << " ";
		gotoxy(--x, y);
	}
	system("CLS");
}

void window1(int w, int h, int x, int y)
{
	gotoxy(x, y);
	for (int i = 1; i <= w * 2; i++)
	{
		cout << char(219);
	}
	//
	for (int j = 1; j <= h; j++)
	{
		gotoxy(x, y + j);
		cout << char(219);
		for (int i = 1; i <= w * 2 - 2; i++)
		{
			cout << " ";
		}
		cout << char(219);
	}
	//
	cout << endl;
	gotoxy(x, y + h);
	for (int i = 1; i <= w * 2; i++)
	{
		cout << char(219);
	}
}
void window2(int x, int y, char A[100])
{
	int w = 10;
	int h = 2;
	gotoxy(x, y);
	for (int i = 1; i <= w * 2; i++)
	{
		cout << char(205);
	}
	//
	for (int j = 1; j <= h; j++)
	{
		gotoxy(x, y + j);
		cout << char(186);
		for (int i = 1; i <= w * 2 - 2; i++)
		{
			cout << " ";
		}
		cout << char(186);
	}
	//
	cout << endl;
	gotoxy(x, y + h);
	for (int i = 1; i <= w * 2; i++)
	{
		cout << char(205);
	}
	gotoxy(x + 1, y + 1);
	cout << A;
}

void Paint(int x, int y, char *a, int color) 
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}