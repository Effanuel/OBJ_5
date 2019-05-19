#include "functions.h"


int main()
{
	MAPw wordDict = readFile();

	MAPw::iterator it = wordDict.begin();
	try {
		if (it->second.size() == 0) throw std::runtime_error("Teksto failas yra tuscias");
		for(const auto& x : wordDict)
		{
			if (x.second.size()) {
				std::cout <<"Zodis "<< x.first << " buvo pakartotas " << x.second.size() << " karta(-us) eilutese: ";
				for (const auto& a : x.second) {
					cout << a << " ";
				}
				cout << endl;
			}

			++it;
		}
	}
	catch (const std::runtime_error& e) {
		cout << e.what() << endl;
	}

}
