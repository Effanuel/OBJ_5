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
	//console.cin_number_in_interval("Kiek maziausiai kartu turi zodius pasikartoti tekste?");
	console.confirmation("Ar norite, isgauti visus URL link'us?");
	

	try {
		MAPw wordDict = readFile(console, file_number);
		MAPw::iterator it = wordDict.begin();

		if (it->second.size() == 0) throw std::runtime_error("Teksto failas yra tuscias");
		bool empty = true;
		//std::ofstream failas;
		std::ofstream failas("OUTPUT.txt");

		int maxWordLimit = 0;
		for (auto& m : wordDict) { // surasti koks yra max zodzio pasikartojimas
			m.second.erase(m.second.begin());
			if (m.second.size() > maxWordLimit) {
				maxWordLimit = m.second.size();
			}
		}
		for (int a = 2; a <= maxWordLimit; ++a) {
			for (const auto& x : wordDict)
			{
				//cout << x.first << x.second.size() << endl;
				if (x.second.size() == a) {
					empty = false;
					failas << "Zodis |" << x.first + " \t\t\t" << "| buvo pakartotas " << x.second.size() << " kartus(-u) eilutese: ";
					std::cout << "Zodis |" << x.first + " \t\t\t" << "| buvo pakartotas " << x.second.size() << " kartus(-u) eilutese: ";
					for (const auto& a : x.second) {
						failas << a << " ";
						cout << a << " ";
					}
					failas << "\n";
					cout << endl;
				}
			}
		}
		
		if (empty) {
			cout << std::string(60, '=') << endl;
			cout << "Nerasta tokiu zodziu." << endl;
		}

		if(console.is_confirmed()) {

			cout << std::string(60, '=') << endl;
			cout << "\t\tURLS:" << endl;
			cout << std::string(60, '=') << endl;

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
