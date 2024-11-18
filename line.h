#pragma once
#include <iostream>
#include <list>
#include "letter.h"

class Line
{
	friend class TextEditor;
	friend class Document;
public:
	int Size;
	std::list<letter> Cs;
	//char* Cs;
	// add whatever you like
public:
	Line();
	~Line();
	Line(const Line& L);
	void InserCharAt(int i, char ch);
};
Line::Line()
{
	Size = 0;
}
Line::Line(const Line& L){
	//deep copy constructor
	Size = L.Size;
	auto it = L.Cs.begin();
	for (int i = 0; i < Size; i++)
	{
		letter l;
		l.ch = it->ch;
		Cs.push_back(l);
		it++;
	}	
}
void Line::InserCharAt(int i, char ch)
{
	//if (i < 0 || i > Size)
	//{
	//	std::cout << "Invalid index\n";
		//return 0;
	//}
	auto it = Cs.begin();
	for (int j = 0; j < i; j++)
	{
		it++;
	}
	letter l;
	l.ch = ch;
	Cs.insert(it, l);
	Size++;
}
Line::~Line()
{
	//delete[] Cs;
}

