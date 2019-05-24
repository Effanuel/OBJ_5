#include "functions.h"


int main()
{
	//std::locale::global(std::locale("Lithuanian"));
	//std::setlocale(LC_ALL, "Lithuanian");
	Console_ console{};

	console.setInterval(1, 3);
	console.cin_number_in_interval("Koki faila norite skenuoti?");

	int file_number;
	file_number = console.get_input();

	console.setInterval(1, 100);
	console.cin_number_in_interval("Kiek kartu norite, kad zodis pasikartotu tekste?");
	console.confirmation("Ar norite, isgauti visus URL link'us?");

	try {
		MAPw wordDict = readFile(console, file_number);
		MAPw::iterator it = wordDict.begin();

		if (it->second.size() == 0) throw std::runtime_error("Teksto failas yra tuscias");
		bool empty = true;
		for(const auto& x : wordDict)
		{
			if (x.second.size() == console.get_input()) {
				empty = false;
				std::cout <<"Zodis |"<< x.first+" \t" << "| buvo pakartotas " << x.second.size() << " kartus(-u) eilutese: ";
				for (const auto& a : x.second) {
					cout << a << " ";                                            
				}
				cout << endl;
			}
		}
		if (empty) {
			cout << std::string(55, '=') << endl;
			cout << "Nerasta tokiu zodziu." << endl;
		}

		if(console.is_confirmed()) {

			cout << std::string(55, '=') << endl;
			cout << "\t\tURLS:" << endl;
			cout << std::string(55, '=') << endl;

			vector<string> URLS = searchURLS(file_number);
			if (URLS.empty()) {
				cout << "Nerasta url." << endl;
			}
			else {	
				for (const auto& url : URLS)
				{
					cout << url << endl;
				}
			}
			cout << std::string(55, '=') << endl;
		}
		
	}
	catch (const std::runtime_error& e) {
		cout << e.what() << endl;
	}

}
