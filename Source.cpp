//#include<conio.h>
//#include<iostream>
//using namespace std;

/*
#include<windows.h>
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
int main()
{
	int d, cr = 0, cc = 0;
	char ch;
	while (true)
	{
		if (_kbhit())
		{
			d = _getch();

			if (d == 224)
			{
				d = _getch();
				if (d == 72)
				{
					cr--;
				}
				else if (d == 80)
				{
					cr++;
				}
				else if (d == 77)
				{
					cc++;
				}
				else if (d == 75)
				{
					cc--;
				}
			}
			else if (d == 13)
			{
				cr++;
				cc = 0;
			}
			else
			{
				cout << char(d);
				cc++;

			}
			gotoRowCol(cr, cc);

		}
	}

	return 0;
}
*/
#include "texteditor.h"
int main12()
{
	//texteditor te("T.txt");
	texteditor te;
	te.Editing();
    //te.Editing();
	return 0;
}

int main123() {
	int d;

	while (1) {
		if (_kbhit) {
			d = _getch();
			cout << d;
		}
	}
	return 0;
}

int main1234()
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
				if (d == 18)
				{
					IsFirst = false;
				}
			}
			else
			{
				if (d == 18)
				{
					cout << "Ctrl + O" << endl;
				}
				else if (d == 4)
				{
					cout << "Ctrl + D" << endl;
				}
				IsFirst = true;
			}
		}
	}

	return 0;
}
	

int main() {
	main12();
}