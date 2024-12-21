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
	bool isProtected = true;
	string password = "abcd";
	// add whatever you like
public:
	document(string name,bool state);
	~document();
	void PrintDocument();
	void saveFile();
	void InsertNewLineAt(int ri, int ci);
	void InsertAChar(int ri, int ci, char ch);
	void DeleteCharAt(int ri, int ci);
	void DeleteCharAt2(int ri, int ci);
	void insertPara(int cr, int cc);
	//
	void ToUpperLine(int ri,int ci);
	void ToUpperWord(int ri, int ci);
	void ToLowerLine(int ri, int ci);
	void ToLowerWord(int ri, int ci);
	void findingWordCaseSensitive(string word);
	void findingWordCaseInSensitive(string word);
	void findingSpecialCharCount();
	void avgWordLength();
	void wordGame();
	void findingSubString(string subString);
	void replaceFirst(string oldWord, string newWord);
	void replaceAll(string oldWord, string newWord);
	void AddPrefixToWords(string prefix,string word);
	void AddSuffixToWords(string suffix, string word);
	void subStringCount(string subString);
	void LargestWordLength();
	void SmallestWordLength();
	void countParas();
	//
	void mergeFiles(string file1, string file2);
	//
	void load()
	{
		ifstream Rd(DName);
		string line_d;
		//NofLines = 20;
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
				if (Ls[ri].isParaStarter == true)
				{
					Ls[ri].isParaStarter = true;
				}
				//InsertACharacter(ri, ci, ch);
				ci++;
			}
		}
	}
};
document::document(string name,bool state)
{
	if (state == 0) {
		cout << "Want Password Protection? (Y/N): ";
		char c;
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			isProtected = true;
			cout << "Enter Password: ";
			cin >> password;
		}
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
		if (isProtected)
		{
			cout << "Enter Password: ";
			string pass;
			cin >> pass;
			do
			{
				cout << "Incorrect Password Try Again" << endl;
				cin >> pass;
			}while (pass != password);
		}
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
	//ofstream Wrt(DName);
	for (int i = 0; i < NofLines; i++)
	{
		for (const auto& letter : Ls[i].Cs)
		{
			//Wrt << letter.ch;
			cout << letter.ch;
		}
		//Wrt << endl;
		cout << endl;
	}
}
void document::saveFile() {
	ofstream Wrt(DName);
	for (int i = 0; i < NofLines; i++)
	{
		for (const auto& letter : Ls[i].Cs)
		{
			Wrt << letter.ch;
		}
		Wrt << endl;
	}
	Wrt.close();
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
//
	if (ri > 0 && ci == 0)
	{
		line* temp = new line[NofLines - 1];
		for (int i = 0; i < ri; i++)
		{
			temp[i] = Ls[i];
		}
		//
		line* MergedLine = new line;
		for (const auto& letter : Ls[ri-1].Cs)
		{
			MergedLine->Cs.push_back(letter);
			MergedLine->Size++;
		}
		for (const auto& letter : Ls[ri].Cs)
		{
			MergedLine->Cs.push_back(letter);
			MergedLine->Size++;
		}
		temp[ri - 1] = *MergedLine;
		//
		for (int i = ri + 1; i < NofLines; i++)
		{
			temp[i - 1] = Ls[i];
		}
		delete[] Ls;
		Ls = temp;
		NofLines--;
	}
//
	else {
		Ls[ri].delChar(ci);
	}
}
void document::DeleteCharAt2(int ri, int ci)
{
	Ls[ri].delChar2(ci);
}
void document::ToUpperLine(int ri,int ci)
{
	list<letter>::iterator it = Ls[ri].Cs.begin();
	//for(auto Iterator it;)
	while (it != Ls[ri].Cs.end())
	{
		advance(it, 0);
		(*it).ch = toupper((*it).ch);
		++it;
	}
}
void document::ToUpperWord(int ri, int ci)
{
	if (ci >= Ls[ri].Size)
	{
		return;
	}
	list<letter>::iterator it = Ls[ri].Cs.begin();
	advance(it, ci);
	if (it->ch == ' ' && prev(it)->ch == ' ' && next(it)->ch ==' ')
	{
		return;
	}

	// Move iterator to the start of the word
	while (it != Ls[ri].Cs.begin() && prev(it)->ch != ' ')
	{
		--it;
	}

	// Convert the word to uppercase
	while (it != Ls[ri].Cs.end() && it->ch != ' ')
	{
		it->ch = toupper(it->ch);
		++it;
	}
}
void document::ToLowerLine(int ri, int ci)
{
	list<letter>::iterator it = Ls[ri].Cs.begin();
	//for(auto Iterator it;)
	while (it != Ls[ri].Cs.end())
	{
		advance(it, 0);
		(*it).ch = tolower((*it).ch);
		++it;
	}
}
void document::ToLowerWord(int ri, int ci)
{
	if (ci >= Ls[ri].Size)
	{
		return;
	}
	list<letter>::iterator it = Ls[ri].Cs.begin();
	advance(it, ci);
	if (it->ch == ' ' && prev(it)->ch == ' ' && next(it)->ch == ' ')
	{
		return;
	}

	// Move iterator to the start of the word
	while (it != Ls[ri].Cs.begin() && prev(it)->ch != ' ')
	{
		--it;
	}

	// Convert the word to uppercase
	while (it != Ls[ri].Cs.end() && it->ch != ' ')
	{
		it->ch = tolower(it->ch);
		++it;
	}
}

void document::findingWordCaseSensitive(string word)
{
	int count = 0;
	for (int i = 0; i < NofLines; i++)
	{
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end())
		{
			string temp;
			auto wordStart = it;
			while (it != Ls[i].Cs.end() && it->ch != ' ')
			{
				temp += it->ch;
				++it;
			}
			if (temp == word)
			{
				count++;
				SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
				for (auto chIt = wordStart; chIt != it; ++chIt)
				{
					cout << chIt->ch;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			}
			else
			{
				for (auto chIt = wordStart; chIt != it; ++chIt)
				{
					cout << chIt->ch;
				}
			}
			if (it != Ls[i].Cs.end())
			{
				cout << it->ch;
				++it;
			}
		}
		cout << endl;
	}
	gotoRowCol(11, 0);
	cout << "The word " << word << " is repeated " << count << " times" << endl;
	system("pause");
	gotoRowCol(0, 0);
}

void document::findingSpecialCharCount() {
	//cout << "Finding Special Characters" << endl;
	int count = 0;
	for (int i = 0; i < NofLines; i++)
	{
		list<letter>::iterator it = Ls[i].Cs.begin();
		advance(it, 0);
		while (it != Ls[i].Cs.end())
		{

			if (it->ch == '!' || it->ch == '@' || it->ch == '#' || it->ch == '$' || it->ch == '%' || it->ch == '^' || it->ch == '&' || it->ch == '*' || it->ch == '(' || it->ch == ')' || it->ch == '-' || it->ch == '_' || it->ch == '+' || it->ch == '=' || it->ch == '[' || it->ch == ']' || it->ch == '{' || it->ch == '}' || it->ch == '|' || it->ch == ';' || it->ch == ':' || it->ch == '"' || it->ch == '\'' || it->ch == '<' || it->ch == '>' || it->ch == ',' || it->ch == '.' || it->ch == '/' || it->ch == '?' || it->ch == '`' || it->ch == '~')
			{
				count++;
			}	
			++it;
		}
	}
	//cout << "Done Counting" << endl;
	gotoRowCol(28, 0);
	cout << "The special characters are repeated " << count << " times" << endl;
	//paush until user press any key
	system("pause");
	gotoRowCol(0, 0);
}
void document::avgWordLength()
{
	int count = 0;
	int total = 0;
	for (int i = 0; i < NofLines; i++)
	{
		list<letter>::iterator it = Ls[i].Cs.begin();
		advance(it, 0);
		while (it != Ls[i].Cs.end())
		{
			string temp;
			while (it != Ls[i].Cs.end() && it->ch != ' ')
			{
				temp += it->ch;
				++it;
			}
			total += temp.size();
			count++;
			if (it != Ls[i].Cs.end())
			{
				++it;
			}
		}
	}
	gotoRowCol(28, 0);
	cout << "The average word length is " << total / count << endl;
	//paush until user press any key
	system("pause");
	gotoRowCol(0, 0);
}

void document::wordGame() {
	string maxWord;
	int maxCount = 0;

	// Extract all words from the document
	vector<string> words;
	for (int i = 0; i < NofLines; i++) {
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end()) {
			string temp;
			while (it != Ls[i].Cs.end() && it->ch != ' ') {
				temp += it->ch;
				++it;
			}
			if (!temp.empty()) {
				words.push_back(temp);
			}
			if (it != Ls[i].Cs.end()) {
				++it;
			}
		}
	}

	// Check each word against all other words
	for (const string& word : words) {
		int count = 0;
		for (const string& otherWord : words) {
			if (word == otherWord) continue;
			bool canForm = true;
			for (char ch : otherWord) {
				if (word.find(ch) == string::npos) {
					canForm = false;
					break;
				}
			}
			if (canForm) {
				count++;
			}
		}
		if (count > maxCount) {
			maxCount = count;
			maxWord = word;
		}
	}

	gotoRowCol(15, 0);
	cout << "The word that contains the alphabets for the highest number of other words in the file is " << maxWord << endl;
	system("pause");
	gotoRowCol(0, 0);
}
void document::findingWordCaseInSensitive(string word) {
	int count = 0;
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	for (int i = 0; i < NofLines; i++) {
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end()) {
			string temp;
			auto wordStart = it;
			while (it != Ls[i].Cs.end() && it->ch != ' ') {
				temp += it->ch;
				++it;
			}
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			if (temp == word) {
				count++;
				SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
				for (auto chIt = wordStart; chIt != it; ++chIt) {
					cout << chIt->ch;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			} else {
				for (auto chIt = wordStart; chIt != it; ++chIt) {
					cout << chIt->ch;
				}
			}
			if (it != Ls[i].Cs.end()) {
				cout << it->ch;
				++it;
			}
		}
		cout << endl;
	}
	gotoRowCol(11, 0);
	cout << "The word " << word << " is repeated " << count << " times" << endl;
	system("pause");
	gotoRowCol(0, 0);
}
//
/*
void document::findingWordCaseInSensitive(string word) {
	int count = 0;
	for (int i = 0; i < NofLines; i++)
	{
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end())
		{
			string temp;
			while (it != Ls[i].Cs.end() && it->ch != ' ')
			{
				temp += it->ch;
				++it;
			}
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			if (temp == word)
			{
				count++;
			}
			if (temp == word) {
				for (int i = 0; i < word.size(); i++)
				{
					it--;
				}
				SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
				for (int i = 0; i < word.size(); i++)
				{

					cout << it->ch;
					it++;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);

			}
			if (it != Ls[i].Cs.end())
			{
				++it;
			}
		}
	}
	gotoRowCol(11, 0);
	cout << "The word " << word << " is repeated " << count << " times" << endl;
	//paush until user press any key
	system("pause");
	gotoRowCol(0, 0);
}
*/
void document::findingSubString(string subString) {
	int count = 0;
	for (int i = 0; i < NofLines; i++)
	{
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end())
		{
			string temp;
			auto wordStart = it;
			while (it != Ls[i].Cs.end() && it->ch != ' ')
			{
				temp += it->ch;
				++it;
			}
			size_t pos = temp.find(subString);
			if (pos != string::npos)
			{
				count++;
				SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
				for (size_t i = 0; i < temp.size(); ++i)
				{
					if (i >= pos && i < pos + subString.size())
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
					}
					cout << temp[i];
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			}
			else
			{
				for (auto chIt = wordStart; chIt != it; ++chIt)
				{
					cout << chIt->ch;
				}
			}
			if (it != Ls[i].Cs.end())
			{
				cout << it->ch;
				++it;
			}
		}
		cout << endl;
	}
	gotoRowCol(11, 0);
	cout << "The substring " << subString << " is repeated " << count << " times" << endl;
	system("pause");
	gotoRowCol(0, 0);
}
/////

void document::replaceFirst(string oldWord, string newWord) {
	for (int i = 0; i < NofLines; i++)
	{
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end())
		{
			string temp;
			auto wordStart = it;
			while (it != Ls[i].Cs.end() && it->ch != ' ')
			{
				temp += it->ch;
				++it;
			}
			if (temp == oldWord)
			{
				auto replaceIt = wordStart;
				for (char ch : newWord)
				{
					if (replaceIt != it)
					{
						replaceIt->ch = ch;
						++replaceIt;
					}
					else
					{
						Ls[i].Cs.insert(replaceIt, { ch });
					}
				}
				while (replaceIt != it)
				{
					replaceIt = Ls[i].Cs.erase(replaceIt);
				}
				return;
			}
			if (it != Ls[i].Cs.end())
			{
				++it;
			}
		}
	}
}
	

void document::replaceAll(string oldWord, string newWord) {
	for (int i = 0; i < NofLines; i++) {
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end()) {
			string temp;
			auto wordStart = it;
			while (it != Ls[i].Cs.end() && it->ch != ' ') {
				temp += it->ch;
				++it;
			}
			if (temp == oldWord) {
				auto replaceIt = wordStart;
				for (char ch : newWord) {
					if (replaceIt != it) {
						replaceIt->ch = ch;
						++replaceIt;
					}
					else {
						Ls[i].Cs.insert(replaceIt, { ch });
					}
				}
				while (replaceIt != it) {
					replaceIt = Ls[i].Cs.erase(replaceIt);
				}
			}
			if (it != Ls[i].Cs.end()) {
				++it;
			}
		}
	}
}
/////
void document::AddPrefixToWords(string prefix, string word) {
	for (int i = 0; i < NofLines; i++) {
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end()) {
			string temp;
			auto wordStart = it;
			while (it != Ls[i].Cs.end() && it->ch != ' ') {
				temp += it->ch;
				++it;
			}
			if (temp == word) {
				auto replaceIt = wordStart;
				for (char ch : prefix) {
					Ls[i].Cs.insert(replaceIt, { ch });
				}
			}
			if (it != Ls[i].Cs.end()) {
				++it;
			}
		}
	}
}
void document::AddSuffixToWords(string suffix, string word) {
	for (int i = 0; i < NofLines; i++) {
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end()) {
			string temp;
			auto wordStart = it;
			while (it != Ls[i].Cs.end() && it->ch != ' ') {
				temp += it->ch;
				++it;
			}
			if (temp == word) {
				auto replaceIt = it;
				for (char ch : suffix) {
					Ls[i].Cs.insert(replaceIt, { ch });
				}
			}
			if (it != Ls[i].Cs.end()) {
				++it;
			}
		}
	}
}
///////
void document::subStringCount(string subString) {
	int count = 0;
	for (int i = 0; i < NofLines; i++) {
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end()) {
			string temp;
			auto wordStart = it;
			while (it != Ls[i].Cs.end() && it->ch != ' ') {
				temp += it->ch;
				++it;
			}
			size_t pos = temp.find(subString);
			if (pos != string::npos) {
				count++;
			}
			if (it != Ls[i].Cs.end()) {
				++it;
			}
		}
	}
	gotoRowCol(11, 0);
	cout << "The substring " << subString << " is repeated " << count << " times" << endl;
	system("pause");
	gotoRowCol(0, 0);
}
/////////////////////
void document::LargestWordLength() {
	int max = 0;
	string largestWord;
	for (int i = 0; i < NofLines; i++) {
		list<letter>::iterator it = Ls[i].Cs.begin();
		while (it != Ls[i].Cs.end()) {
			string temp;
			while (it != Ls[i].Cs.end() && it->ch != ' ') {
				temp += it->ch;
				++it;
			}
			if (temp.size() > max) {
				max = temp.size();
				largestWord = temp;
			}
			if (it != Ls[i].Cs.end()) {
				++it;
			}
		}
	}
	gotoRowCol(11, 0);
	cout << "The largest word in the file is \"" << largestWord << "\" with length " << max << endl;
	system("pause");
	gotoRowCol(0, 0);
}
void document::SmallestWordLength() {
    int min = INT_MAX;
    string smallestWord;
    for (int i = 0; i < NofLines; i++) {
        list<letter>::iterator it = Ls[i].Cs.begin();
        while (it != Ls[i].Cs.end()) {
            string temp;
            while (it != Ls[i].Cs.end() && it->ch != ' ') {
                temp += it->ch;
                ++it;
            }
            if (!temp.empty() && temp.size() < min) {
                min = temp.size();
                smallestWord = temp;
            }
            if (it != Ls[i].Cs.end()) {
                ++it;
            }
        }
    }
    gotoRowCol(15, 0);
    if (min == INT_MAX) {
        cout << "No words found in the document." << endl;
    } else {
        cout << "The length of the smallest word in the file is " << min << endl;
        cout << "The smallest word in the file is " << smallestWord << endl;
    }
    system("pause");
    gotoRowCol(0, 0);
}

void document::countParas() {
	int count = 1;
	for (int i = 0; i < NofLines; i++)
	{
		if (Ls[i].isParaStarter == true)
		{
			count++;
		}
	}
	gotoRowCol(11, 0);
	cout << "The number of paragraphs in the file is " << count << endl;
	system("pause");
	gotoRowCol(0, 0);
}
//
void document::mergeFiles(string fname1, string fname2) {
    ifstream file1(fname1);
    ifstream file2(fname2);
	cout << "Enter new file name to save the merged file : ";
	string NName;
	cin >> NName;
	NName = NName + ".txt";
    ofstream outFile(NName, ios::app); // Append to the current document

    if (!file1.is_open() || !file2.is_open() || !outFile.is_open()) {
        cout << "Error opening files!" << endl;
        return;
    }

    cout << "Merging Files" << endl;
    cout << "Want to merge file1 into file2 or file2 into file1? (1/2): ";
    int choice;
    cin >> choice;

    string line;
    if (choice == 1) {
        while (getline(file1, line)) {
            outFile << line << endl;
        }
        while (getline(file2, line)) {
            outFile << line << endl;
        }
    } else if (choice == 2) {
        while (getline(file2, line)) {
            outFile << line << endl;
        }
        while (getline(file1, line)) {
            outFile << line << endl;
        }
    } else {
        cout << "Invalid choice!" << endl;
    }

    file1.close();
    file2.close();
    outFile.close();

    // Reload the document to reflect the changes
    load();
	PrintDocument();
}