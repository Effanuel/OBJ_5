#include "functions.h"


int main()
{
	//std::locale::global(std::locale("Lithuanian"));
	//std::setlocale(LC_ALL, "Lithuanian");
	int kartai;
	char get_url;
	Console(kartai, get_url);

	MAPw wordDict = readFile(get_url);
	MAPw::iterator it = wordDict.begin();

	try {
		if (it->second.size() == 0) throw std::runtime_error("Teksto failas yra tuscias");
		bool empty = true;
		for(const auto& x : wordDict)
		{
			if (x.second.size() == kartai) {
				empty = false;
				std::cout <<"Zodis "<< x.first+" \t" << " buvo pakartotas " << x.second.size() << " kartus(-u) eilutese: ";
				for (const auto& a : x.second) {
					cout << a << " ";                                            
				}
				cout << endl;
			}
		}
		if (empty) {
			cout << std::string(50, '=') << endl;
			cout << "Nerasta tokiu zodziu" << endl;
		}

		if(get_url == 'y') {
			cout << std::string(50, '=') << endl;
			cout << "\t\tURLS:" << endl;
			cout << std::string(50, '=') << endl;
			vector<string> URLS = searchURLS();
			for (const auto& url : URLS)
			{
				cout << url << endl;
			}
			cout << std::string(50, '=') << endl;
		}
		
	}
	catch (const std::runtime_error& e) {
		cout << e.what() << endl;
	}

}
