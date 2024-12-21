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
#include <unordered_map>
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
void selectRowCol(int rpos, int cpos)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int xpos = cpos, ypos = rpos;
    COORD scrn;
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(h, scrn);

    // Highlight the selected position
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(h, &csbi);
    WORD wAttributes = csbi.wAttributes;
    SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << " ";
    SetConsoleCursorPosition(h, scrn);
    SetConsoleTextAttribute(h, wAttributes);
}

struct letter
{
	char ch;
	letter* next;
	// add whatever you like

};