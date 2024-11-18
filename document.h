#pragma once
#include "para.h"
#include <string>
#include <fstream>
using namespace std;
class Document
{
	friend class TextEditor;
    int dri, dci;
    int NofLines;
    Line* Ls;
	string DName;
    // add whatever you like
public:
	Document(string fname);
	~Document();
    void InsertACharacter(int li,int ci,char ch);
	void PrintDocument();
	void Load(string fname);
	void InsertNewLineAt(int li, int ci);
};
Document::Document(string fname)
{
	Load(fname);
}

void Document::Load(string fname) {
	DName = fname;
	ifstream Rd(DName);
	string line;
	NofLines = 0;
	while (getline(Rd, line))
	{
		NofLines++;
	}
	Rd.close();
	Ls = new Line[NofLines];
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
			//Ls[ri].InserCharAt(ci, ch);
			InsertACharacter(ri, ci, ch);
			ci++;
		}
	}
	/*
	for (int i = 0; i < NofLines; i++)
	{
		getline(Rd, line);
		for (int j = 0; j < line.size(); j++)
		{
			if (line[j] == '\n') {
				ri++;
				ci = 0;
			}
			else {
				//Ls[i].InserCharAt(j, line[j]);
				InsertACharacter(ri, ci, line[j]);
				ci++;
			}
		}
	}
	Rd.close();
	*/
}
/*
void Document::Load(string fname) {
	DName = fname;
	ifstream Rdr(fname);
	Rdr >> NofLines; //Rdr.ignore();
	NofLines = 3;
	Ls = new Line[NofLines];
	int ri = 0; int ci = 0; char ch;
	while (Rdr) {
		ch = Rdr.get();
		if (!Rdr) break;
		if (ch == '\n') {
			ri++;
			ci = 0;
		}
		else {
			//Ls[ri].InserCharAt(ci, ch);
			InsertACharacter(ri, ci, ch);
			ci++;
		}
	}
}
*/
void Document::InsertACharacter(int li, int ci, char ch)
{
    /*
	if (li < 0 || li >= NofLines)
	{
		cout << "Invalid line index\n";
		return;
	}
    */
	Ls[li].InserCharAt(ci, ch);
}
void Document::PrintDocument() {
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
Document::~Document()
{
	delete[] Ls;
}
void Document::InsertNewLineAt(int li, int ci) {
	Line* temp = new Line[NofLines + 1];
	for (int i = 0; i < li; i++)
	{
		temp[i] = Ls[i];
	}

	// Create a new line and insert characters up to ci
	Line newLine;
	auto it = Ls[li].Cs.begin();
	for (int i = 0; i < ci; i++, it++)
	{
		newLine.Cs.push_back(*it);
	}
	newLine.Size = ci;
	temp[li] = newLine;

	// Move remaining characters to the next line
	Line remainingLine;
	for (; it != Ls[li].Cs.end(); it++)
	{
		remainingLine.Cs.push_back(*it);
	}
	remainingLine.Size = Ls[li].Size - ci;
	temp[li+1] = remainingLine;

	for (int i = li + 1; i < NofLines; i++)
	{
		temp[i + 1] = Ls[i];
	}
	delete[] Ls;
	Ls = temp;
	NofLines++;
}
