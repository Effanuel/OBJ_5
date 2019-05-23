#pragma once
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

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::map;
using std::cin;

typedef unsigned int uint;
typedef map<string, vector<uint>> MAPw;


bool wordInDict(MAPw& mapOfWords, string& val);

void incrementMap(MAPw& wordDict, string& word, uint& index);

void removeURLS(string& line);
void cleanString(string & line);
vector<string> searchURLS();

void getURL(string, vector<string>&);

MAPw readFile(char);

template <typename T> T cin_and_checkFormat_in_interval(double, double);
void Console(int&, char&);

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
		if (it->first == word) {
			it->second.push_back(index + 1);
			break;
		}
		++it;
	}
}

void cleanString(string & line) {
	//vector<char> symbols{ '"', '„', '“', '…', '(', ')', '\\','—','-',',', '.', '?', '!', ':', ';', '\'', '{', '}', '*', '#', '[', ']' };
	
	//for (auto& a : line) {
	//	for (const auto& symbol : symbols) {
	//		if (a == symbol)
	//			a = ' ';
	//	}
	//}
	//((http | https) : / {2}) ? (? = \4)(www.) ? (\w + .(com | org | lt)) { 1 }
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	std::regex reg("\\W");
	line = std::regex_replace(line, reg, " ");
}

void removeURLS(string& line) {
	std::regex reg("((http|https):\/\/)?(www\\.)?(\\w+\\.(com|org|lt)){1}");
	line = std::regex_replace(line, reg, " ");
}



void getURL(string line, vector<string>& URLS) {
	try {
		std::regex reg("((http|https):\/\/)?(www\\.)?(\\w+\\.(com|org|lt)){1}");
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



vector<string> searchURLS() {

	std::ifstream failas("SAMPLE.txt");
	vector<string> URLS;
	string line;
	for (uint i = 0; !failas.eof(); ++i) {
		std::getline(failas, line, '\n');
		//cout << line << endl;
		getURL(line, URLS);
	}
	return URLS;
}




MAPw readFile(char get_url = 'n') {


	std::ifstream failas("SAMPLE.txt");
	//failas.imbue(std::locale("Lithuanian"));
	MAPw wordDict;
	string line;
	for (uint i = 0; !failas.eof(); ++i) {
		std::getline(failas, line, '\n');
		//cout << line << endl;
		if (get_url == 'y') removeURLS(line);
		cleanString(line);
		
		std::stringstream ss(line);
		string word;
		while (ss >> word) {
			if (!wordInDict(wordDict, word)) {
				vector<uint> init{ 1 };
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


template <typename T> T cin_and_checkFormat_in_interval(double a, double b) {
	T input;
	while (!(cin >> input) || a > input || input > b) {
		std::cout << "Netinkamas ivesties formatas. Iveskite is naujo: " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return input;
}



void Console(int& kartai, char& url) {
	cout << "Kiek kartu norite, kad zodis pasikartotu tekste?(1-100)" << endl;
	kartai = cin_and_checkFormat_in_interval<int>(1, 100);
	cout << "Ar norite, isgauti visus URL link'us?(y/n)" << endl;
	std::cin >> url;
}
