#pragma once
#include "para.h"
#include "line.h"
#include <fstream>

class document
{
	friend class texteditor;
	int dri, dci;
	int NofLines;
	line* Ls;
	vector<para> Ps;
	string DName;
	bool isProtected = false;
	string password;
	// add whatever you like
public:
	document(string name,bool state);
	~document();
	void PrintDocument();
	void InsertNewLineAt(int ri, int ci);
	void InsertAChar(int ri, int ci, char ch);
	void DeleteCharAt(int ri, int ci);
	void DeleteCharAt2(int ri, int ci);
	void load()
	{
		ifstream Rd(DName);
		string line_d;
		NofLines = 0;
		while (getline(Rd, line_d))
		{
			NofLines++;
		}
		Rd.close();
		Ls = new line[NofLines];
		Rd.open(DName);
		int ri = 0; int ci = 0; char ch;
		while (Rd) {
			ch = Rd.get();
			if (!Rd) break;
			if (ch == '\n') {
				ri++;
				ci = 0;
			}
			else {
				Ls[ri].InsertCharAt(ci, ch);
				//InsertACharacter(ri, ci, ch);
				ci++;
			}
		}
	}
};
document::document(string name,bool state)
{
	if (state == 0) {
		DName = name;
		//create new text file
		ofstream Wrt;
		Wrt.open(DName, ios::out);
		Wrt << "Created New File";
		Wrt.close();
		dri = 0;
		dci = 0;
		NofLines = 0;
		Ls = new line;
		//
		load();
	}
	else{
		DName = name;
		load();
	}
}
document::~document()
{
	delete Ls;
}
void document::PrintDocument()
{
	system("cls");
	gotoRowCol(0, 0);
	ofstream Wrt(DName);
	for (int i = 0; i < NofLines; i++)
	{
		for (const auto& letter : Ls[i].Cs)
		{
			Wrt << letter.ch;
			cout << letter.ch;
		}
		Wrt << endl;
		cout << endl;
	}
}
void document::InsertNewLineAt(int li, int ci)
{
	line* temp = new line[NofLines + 1];
	for (int i = 0; i < li; i++)
	{
		temp[i] = Ls[i];
	}

	// Create a new line and insert characters up to ci
	line newLine;
	auto it = Ls[li].Cs.begin();
	for (int i = 0; i < ci; i++, it++)
	{
		newLine.Cs.push_back(*it);
	}
	newLine.Size = ci;
	temp[li] = newLine;

	// Move remaining characters to the next line
	line remainingLine;
	for (; it != Ls[li].Cs.end(); it++)
	{
		remainingLine.Cs.push_back(*it);
	}
	remainingLine.Size = Ls[li].Size - ci;
	temp[li + 1] = remainingLine;

	for (int i = li + 1; i < NofLines; i++)
	{
		temp[i + 1] = Ls[i];
	}
	delete[] Ls;
	Ls = temp;
	NofLines++;
}
void document::InsertAChar(int ri, int ci, char ch)
{
	Ls[ri].InsertCharAt(ci, ch);
}
void document::DeleteCharAt(int ri, int ci)
{
	Ls[ri].delChar(ci);
}
void document::DeleteCharAt2(int ri, int ci)
{
	Ls[ri].delChar2(ci);
}
