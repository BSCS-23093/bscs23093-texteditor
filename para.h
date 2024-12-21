#pragma once
#include "line.h"

class para
{
	//friend class texteditor;
	//friend class document;
	int Size;
	list<line*> Ls;
public:
	/*
	para()
	{
		Size = 0;
	}
	para(const para& obj)
	{
		Size = obj.Size;
		Ls = obj.Ls;
	}
	para& operator=(const para& obj)
	{
		Size = obj.Size;
		Ls = obj.Ls;
		return *this;
	}
	void AddLine(line* L)
	{
		Ls.push_back(L);
		Size++;
	}
	void AddLine()
	{
		line* L = new line;
		Ls.push_back(L);
		Size++;
	}
	void AddLine(int i)
	{
		list<line*>::iterator it = Ls.begin();
		advance(it, i);
		Ls.insert(it, new line);
		Size++;
	}
	void AddLine(int i, line* L)
	{
		list<line*>::iterator it = Ls.begin();
		advance(it, i);
		Ls.insert(it, L);
		Size++;
	}
	void RemoveLine(int i)
	{
		list<line*>::iterator it = Ls.begin();
		advance(it, i);
		Ls.erase(it);
		Size--;
	}
	void RemoveLine()
	{
		Ls.pop_back();
		Size--;
	}
	void RemoveLine(int i, int j)
	{
		list<line*>::iterator it1 = Ls.begin();
		advance(it1, i);
		list<line*>::iterator it2 = Ls.begin();
		advance(it2, j);
		Ls.erase(it1, it2);
		Size -= j - i + 1;
	}
	void RemoveLine(int i, int j, int k)
	{
		list<line*>::iterator it1 = Ls.begin();
		advance(it1, i);
		list<line*>::iterator it2 = Ls.begin();
		advance(it2, j);
		list<line*>::iterator it3 = Ls.begin();
		advance(it3, k);
		Ls.erase(it1, it2);
		Size -= j - i + 1;
	}
	void RemoveLine(int i, int j, int k, int l)
	{
		list<line*>::iterator it1 = Ls.begin();
		advance(it1, i);
		list<line*>::iterator it2 = Ls.begin();
		advance(it2, j);
		list<line*>::iterator it3
			= Ls.begin();
		advance(it3, k);

		list<line*>::iterator it4 = Ls.begin();
		advance(it4, l);
		Ls.erase(it1, it2);
		Size -= j - i + 1;
	}
	*/
};