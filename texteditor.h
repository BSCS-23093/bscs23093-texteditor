#pragma once
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <fstream>
#include <vector>
#include "document.h"

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
class TextEditor
{
	int cr = 0, cc = 0;
	//
    vector<Document*> AllDocs;
    int Cdri = 0, Cdci = 0;
    int Cdoci, NofDocs;
    // add whatever you like
public:
	TextEditor(string Dname);
	void Editing();
    ~TextEditor();
};
TextEditor::TextEditor(string Dname)
{
	AllDocs.push_back(new Document(Dname));
	NofDocs = 1;
	//PRINT DOCUMENT
	//for (int i = 0; i < AllDocs.size(); i++)
	//{
	//	AllDocs[i]->PrintDocument();
	//}
	AllDocs[0]->PrintDocument();
	//Cdoci = 0;
	//NofDocs = 0;
	//AllDocs.push_back(new Document);
	//NofDocs++;
}
void TextEditor::Editing() {
	int d;
	char ch;
	cr = 0; cc = 0;
	gotoRowCol(cr, cc);
	//Line ALine;
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
					if (cr > 0) {
						cr--;
					}
					if (AllDocs[0]->Ls[cr].Size < cc)
					{
						cc = AllDocs[0]->Ls[cr].Size;
					}
				}
				else if (d == 80)
				{
					if (AllDocs[0]->NofLines-1 != cr) {
						cr++;
					}
					if (AllDocs[0]->Ls[cr].Size < cc)
					{
						cc = AllDocs[0]->Ls[cr].Size;
					}
				}
				else if (d == 77)
				{
					cc++;
					if (cc == AllDocs[0]->Ls[cr].Size)
					{
						cc = 0;
						cr++;
					}
				}
				else if (d == 75)
				{
					cc--;
					if (cc == -1 && cr != 0)
					{
						cr--;
						cc = AllDocs[0]->Ls[cr].Size;
					}
				}
			}
			else if (d == 13)
			{
				//InsertNewLineAt
				AllDocs[0]->InsertNewLineAt(cr, cc);
				cr++;
				cc = 0;
				AllDocs[0]->PrintDocument();
			}
			else
			{
				ch = char(d);
				//cout << char(d);
				//cout<<ch;
				//ALine.InserCharAt(cc, ch);
				AllDocs[0]->InsertACharacter(cr, cc, ch);
				AllDocs[0]->PrintDocument();
				cc++;

			}
			gotoRowCol(cr, cc);

		}
	}
}
TextEditor::~TextEditor()
{
	for (int i = 0; i < NofDocs; i++)
	{
		delete AllDocs[i];
	}
}


