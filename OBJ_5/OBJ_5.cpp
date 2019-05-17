#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::map;

typedef unsigned int uint;

struct Words {
	uint count;
	vector<uint> lines;
};


typedef map<string, Words> MAPw;



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

void incrementMap(MAPw& wordDict, string& word, uint& index) {
	MAPw::iterator it = wordDict.begin();
	while (it != wordDict.end())
	{
		if (it->first == word) {
			++(it->second.count);
			it->second.lines.push_back(index);
			break;
		}
		++it;
	}
}

void cleanString(string& line) {
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
		std::getline(failas, line);
		cleanString(line);
		std::stringstream ss(line);

		string word;
		while (ss >> word) {
			if (!wordInDict(wordDict, word)) {
				Words init{ 1, { i } };
				wordDict.insert(MAPw::value_type(word, init));
			}
			else {
				incrementMap(wordDict, word, i);
			}
		}
	}
	return wordDict;
}






int main()
{
	MAPw wordDict = readFile();

	MAPw::iterator it = wordDict.begin();
	int c = 0;
	while (it != wordDict.end())
	{
		if (it->second.count) {
			std::cout << it->first << "\t:: " << it->second.count << " ::\t";
			for (const auto& a : it->second.lines) {
				cout << a << " ";
			}
			cout << endl;
		}

		it++;
		++c;
	}
	cout << c << endl;
}
