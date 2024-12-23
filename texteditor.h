#pragma once
#include "document.h"
class texteditor
{
public:
	int cr = 0, cc = 0;
    vector<document*> AllDocs;
	int Cdri = 0, Cdci = 0;
    int Cdoci, NofDocs;
public:
	texteditor();
	void Editing();
	~texteditor();
};
texteditor::texteditor()
{
	cout << "Welcome To Text Editor" << endl;
	cout << "1)Open Document" << endl;
	cout << "2)Create New Document" << endl;
	cout << "3)Exit" << endl;
	int choice;
	cin >> choice;
	if (choice == 2)
	{
		string filename;
		system("cls");
		cout << "Enter Document Name: "<<endl;
		cin >> filename;
		string efilename = filename + ".txt";
		AllDocs.push_back(new document(efilename,0));
		NofDocs++;
		system("cls");
		AllDocs[NofDocs-1]->PrintDocument();
		Cdoci = NofDocs-1;
	}
	else if (choice == 1)
	{
		bool docfound=false;
		string fname;
		system("cls");
		cout << "Enter Document Name: "<<endl;
		cin >> fname;
		string efname = fname + ".txt";
		AllDocs.push_back(new document(efname,1));
		NofDocs++;
		Cdoci = NofDocs - 1;
		/////////////////////////////////////////////////
		/*
		for (int i = 0; i < NofDocs; i++) {
			if (AllDocs[i]->DName == efname)
			{
				Cdoci = i;
				docfound = true;
				break;
			}
		}
		if (docfound == false) {
			AllDocs.push_back(new document(efname));
			NofDocs++;
			system("cls");
			AllDocs[NofDocs - 1]->PrintDocument();
			Cdoci = NofDocs - 1;
		}
		*/
		/////////////////////////////////////////////////
		/*
		for (int i = 0; i < NofDocs; i++)
		{
			if (AllDocs[i]->DName == efname)
			{
				Cdoci = i;
				break;
			}
		}
		*/
		docfound = false;
		system("cls");
		AllDocs[Cdoci]->PrintDocument();
	}
	else if (choice == 3)
	{
		exit(0);
	}
	//AllDocs[0]->PrintDocument();
}
void texteditor::Editing() {
	int d;
	char ch;
	bool IsFirst = true;
	bool IsFirst2 = true;
	cr = 0; cc = 0;
	gotoRowCol(cr, cc);
	//Line ALine;
	while (true)
	{
		if (_kbhit())
		{
			d = _getch();

			//
			if (d == 224)
			{
				d = _getch();
				if (d == 72)
				{
					if (cr > 0) {
						cr--;
					}
					if (AllDocs[Cdoci]->Ls[cr].Size < cc)
					{
						cc = AllDocs[0]->Ls[cr].Size;
					}
				}
				else if (d == 80)
				{
					if (AllDocs[Cdoci]->NofLines - 1 != cr) {
						cr++;
					}
					if (AllDocs[Cdoci]->Ls[cr].Size < cc)
					{
						cc = AllDocs[Cdoci]->Ls[cr].Size;
					}
				}
				else if (d == 77)
				{
					cc++;
					if (cc == AllDocs[Cdoci]->Ls[cr].Size)
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
						cc = AllDocs[Cdoci]->Ls[cr].Size;
					}
				}
				else if (d == 83) {
					//AllDocs[Cdoci]->DeleteCharAt(cr, cc + 1);
					AllDocs[Cdoci]->DeleteCharAt2(cr, cc);
					AllDocs[Cdoci]->PrintDocument();
				}
			}
			else if (d == 13)
			{
				//InsertNewLineAt
				AllDocs[Cdoci]->InsertNewLineAt(cr, cc);
				cr++;
				cc = 0;
				AllDocs[Cdoci]->PrintDocument();
			}
			else if(d==8)
			{
				AllDocs[Cdoci]->DeleteCharAt(cr, cc);
				AllDocs[Cdoci]->PrintDocument();
				if (cc == 0 && cr != 0)
				{
					cr--;
					cc = AllDocs[Cdoci]->Ls[cr].Size;
				}
				else if (cc == 0 && cr == 0)
				{
					cr = 0;
					cc = 0;
				}
				else
				{
					cc--;
				}
			}
			else if (IsFirst && d==15)
			{
				//if (d == 15)
				{
					IsFirst = false;
				}
			}
			else if (!IsFirst)
			{
				if (d == 15)
				{
					//string word;
					//gotoRowCol(28, 0);
					//cin >> word;
					//gotoRowCol(0, 0);
					//cout << "Ctrl + O" << endl;
					//To Upper
					//AllDocs[Cdoci]->ToLowerLine(cr,cc);
					//AllDocs[Cdoci]->ToUpperWord(cr, cc);
					//AllDocs[Cdoci]->findingWordCaseSensitive(word);
					//AllDocs[Cdoci]->findingWordCaseInSensitive(word);
					//AllDocs[Cdoci]->findingSpecialCharCount();
					//AllDocs[Cdoci]->avgWordLength();
					//AllDocs[Cdoci]->wordGame();
					//AllDocs[Cdoci]->saveFile();
					//AllDocs[Cdoci]->findingSubString(word);
					//AllDocs[Cdoci]->replaceAll(word, "alif");
					//AllDocs[Cdoci]->AddPrefixToWords("lm", word);
					//AllDocs[Cdoci]->AddSuffixToWords("lm", word);
					//AllDocs[Cdoci]->subStringCount(word);
					//AllDocs[Cdoci]->LargestWordLength();
					//AllDocs[Cdoci]->SmallestWordLength();
					//AllDocs[Cdoci]->countParas();
					string file1, file2;
					cout << "Enter File 1: ";
					cin >> file1;
					file1 = file1 + ".txt";
					cout << "Enter File 2: ";
					cin >> file2;
					file2 = file2 + ".txt";
					AllDocs[Cdoci]->mergeFiles(file1, file2);
					AllDocs[Cdoci]->PrintDocument();
				}
				else if (d == 5)
				{
					cout << "Ctrl + D" << endl;
				}
				else if (d == 4) {
					//InsertNewLineAt
					AllDocs[Cdoci]->InsertNewLineAt(cr, cc);
					cr++;
					cc = 0;
					AllDocs[Cdoci]->Ls[cr].isParaStarter = true;
					cout<< AllDocs[Cdoci]->Ls[cr].isParaStarter;
					cout << AllDocs[Cdoci]->DName;
					AllDocs[Cdoci]->PrintDocument();
				}
				IsFirst = true;
			}
			else
			{
				ch = char(d);
				//cout << char(d);
				//cout<<ch;
				//ALine.InserCharAt(cc, ch);
				
				AllDocs[Cdoci]->InsertAChar(cr, cc, ch);
				//AllDocs[Cdoci]->Ls[cr].InsertCharAt(cc, ch);
				AllDocs[Cdoci]->PrintDocument();
				cc++;

			}

			gotoRowCol(cr, cc);

		}
	}
}
texteditor::~texteditor()
{
	for (int i = 0; i < NofDocs; i++)
	{
		delete AllDocs[i];
	}
}