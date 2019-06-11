#pragma once
#include "Console.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <exception>
#include <clocale>
#include <regex>
#include <locale>
#include <codecvt>

using std::vector;
using std::map;

typedef unsigned int uint;
typedef map<string, vector<uint>> MAPw;


bool wordInDict(MAPw& mapOfWords, string& val);
void incrementMap(MAPw& wordDict, string& word, uint& index);
void removeURLS(string& line);
void cleanString(string & line);
vector<string> searchURLS(int);
void getURL(string, vector<string>&);
MAPw readFile(Console_&, int);

bool wordInDict(MAPw& mapOfWords, string& val)
{
	MAPw::iterator it = mapOfWords.begin();
	while (it != mapOfWords.end())
	{
		if (it->first == val)
			return true;
		++it;
	}
	return false;
}

void incrementMap(MAPw & wordDict, string & word, uint & index) {
	MAPw::iterator it = wordDict.begin();
	while (it != wordDict.end())
	{
		if (it->first == word && !std::count(it->second.begin(), it->second.end(), index+1)) { // egzamino
			it->second.push_back(index + 1);
			break;
		}
		
		++it;
	}
}

void cleanString(string& line) {
	//std::vector<char> characters{ '/', '%', '[', ']', '-',',', '.', '?', '!', ':', ';', '(', ')', '\\', '\'', '{', '}', '*', '#' };
	//for (auto& str : line)
	//{
	//	for (auto& ch : characters)
	//	{
	//		if (str == ch)
	//		{
	//			str = ' ';
	//		}
	//	}
	//}
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	std::regex reg("\\W");
	line = std::regex_replace(line, reg, " ");

}

void removeURLS(string& line) {
	std::regex reg("((http|https):\\/\\/)?(www\\.)?(\\w+\\.(com|org|lt)){1}");
	line = std::regex_replace(line, reg, " ");
}


void getURL(string line, vector<string>& URLS) {
	try {
		std::regex reg("((http|https):\\/\\/)?(www\\.)?(\\w+\\.(com|org|lt)){1}");
		std::sregex_iterator next(line.begin(), line.end(), reg);
		std::sregex_iterator end;
		while (next != end) {
			std::smatch match = *next;
			if (match.str() != "")
				URLS.push_back(match.str());
			next++;
		}
	}
	catch (std::regex_error & e) {
		cout << e.what() << endl;
	}
}

vector<string> searchURLS(int file_number) {

	std::ifstream failas(std::to_string(file_number) + "_SAMPLE.txt");;
	vector<string> URLS;
	string line;
	for (uint i = 0; !failas.eof(); ++i) {
		std::getline(failas, line, '\n');
		//cout << line << endl;
		getURL(line, URLS);
	}
	return URLS;
}


MAPw readFile(Console_& console, int file_number) {


	std::ifstream failas;
	//failas.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));
	failas.open(std::to_string(file_number) + "_SAMPLE.txt");
	
	if (failas.fail()) throw std::runtime_error("Nera tokio failo."); //jei nera failo
	cout << "\nFILE " << std::to_string(file_number) + "_SAMPLE.txt" << " contents:\n\n";
	cout << std::string(55, '=') << endl;
	//failas.imbue(std::locale("Lithuanian"));
	MAPw wordDict;
	string line;
	for (uint i = 0; !failas.eof(); ++i) {
		std::getline(failas, line, '\n');
		//cout << line << endl;
		if (console.is_confirmed()) removeURLS(line);
		cleanString(line);
		
		std::stringstream ss(line);
		string word;
		while (ss >> word) {
			if (!wordInDict(wordDict, word)) {
				vector<uint> init{ 0 };
				wordDict.insert(MAPw::value_type(word, init));
			}
			else {
				incrementMap(wordDict, word, i);
			}
		}
		line.clear();
	}
	return wordDict;
}
