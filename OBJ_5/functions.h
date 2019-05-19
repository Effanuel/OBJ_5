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

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::map;

typedef unsigned int uint;
typedef map<string, vector<uint>> MAPw;



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
	vector<char> symbols{ '"', '„', '“', '…', '(', ')', '\\','—','-',',', '.', '?', '!', ':', ';', '\'', '{', '}', '*', '#', '[', ']' };
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	for (auto& a : line) {
		for (const auto& symbol : symbols) {
			if (a == symbol)
				a = ' ';
		}
	}
}



MAPw readFile() {

	MAPw wordDict;
	std::ifstream failas("SAMPLE.txt");

	string line;

	for (uint i = 0; !failas.eof(); ++i) {
		std::getline(failas, line, '\n');
		cout << line << endl;
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

