#pragma once
#include <iostream>
#include <list>
#include <vector>
#include<conio.h>
#include<windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

//
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
//

struct letter
{
	char ch;
	letter* next;
	// add whatever you like

};