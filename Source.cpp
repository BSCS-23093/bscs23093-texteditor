//#include<conio.h>
//#include<iostream>
//using namespace std;


//#include<windows.h>
/*
void gotoRowCol(int rpos, int cpos)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int xpos = cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
*/
/*
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(h, &csbi);
	cpos = csbi.dwCursorPosition.X;
	rpos = csbi.dwCursorPosition.Y;
}

#include "TextEditor.h"
*/
/*
#include<iostream>
#include<conio.h>
#include<time.h>

using namespace std;
*/

void ResetKeys(int& K1, int& K2)
{
	K1 = -1;
	K2 = -1;
}
/*
int main2()
{

	int Key1 = -1, Key2 = -1;

	bool IsFirst = true;

	int d;
	while (true)
	{
		if (_kbhit())
		{
			d = _getch();
			cout << d << endl << endl;

			if (IsFirst)
			{
				if (d == 19)
				{
					if (IsFirst)
					{
						IsFirst = false;
					}

				}
			}
			else
			{
				if (d == 19)
				{
					cout << "Ctlr + S    Ctrl+S" << endl;
				}
				if (d == 4)
				{
					cout << "Ctlr + S    Ctrl+D" << endl;
				}
				IsFirst = true;

			}
		}
	}

	return 0;
}
*/
/*
int mainTE()
{
	TextEditor TE("D.txt");
	TE.Editing();
	return 0;
}
*/
#include "TextEditor.h"
int main() {
	TextEditor TE("Text.txt");
	TE.Editing();
	return 0;
}
