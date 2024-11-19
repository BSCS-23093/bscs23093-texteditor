#pragma once
#include "letter.h"

class line
{
	friend class para;
	friend class document;
	friend class texteditor;
	int Size;
	list<letter> Cs;
	bool isParaStarter = false;
	//add whatever you like
public:
	line();
	line(const line& obj);
	line& operator=(const line& obj);
	void PrintLine();
	void InsertCharAt(int ci, char ch);
	void delChar(int ci);
	void delChar2(int ci);
	~line();
};
line::line()
{
	Size = 0;
}
line::line(const line& obj)
{
	Size = obj.Size;
	Cs = obj.Cs;
}
line& line::operator=(const line& obj)
{
	Size = obj.Size;
	Cs = obj.Cs;
	return *this;
}
void line::PrintLine()
{
	list<letter>::iterator it = Cs.begin();
	while (it != Cs.end())
	{
		cout << it->ch;
		++it;
	}
	cout << endl;
}
line::~line()
{
	Cs.clear();
}
void line::InsertCharAt(int ci, char ch)
{
	list<letter>::iterator it = Cs.begin();
	if (ci > Size)
	{
		while (Size < ci)
		{
			letter L;
			L.ch = ' ';
			Cs.push_back(L);
			++Size;
		}
		it = Cs.end();
	}
	else
	{
		advance(it, ci);
	}
	letter L;
	L.ch = ch;
	Cs.insert(it, L);
	++Size;
}
void line::delChar(int ci)
{
	if (ci > 0 && ci <= Size) {
		list<letter>::iterator it = Cs.begin();
		advance(it, ci - 1);
		Cs.erase(it);
		--Size;
	}
}
void line::delChar2(int ci)
{
	if (ci < Size && !Cs.empty()) {
		list<letter>::iterator it = Cs.begin();
		advance(it, ci);
		Cs.erase(it);
		--Size;
	}
}