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
int main() {
	main12();
}