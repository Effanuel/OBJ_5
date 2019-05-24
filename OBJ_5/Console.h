#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

class Console_ {
private:
	int interval_start_;
	int interval_end_;
	char c_;
	int input_;
public:
	Console_(int a = 2, int b = 100, char c = 'n', int input = 2) : interval_start_(a), interval_end_(b), c_(c), input_(input) {}

	int interval_start() const { return interval_start_; }
	int interval_end() const { return interval_end_; }
	char get_c() const { return c_; }
	char get_input() const { return input_; }

	void setInterval(int a, int b);
	void cin_number_in_interval(string text);
	void confirmation(string text);
	bool is_confirmed();
};

void Console_::setInterval(int a, int b) {
	interval_start_ = a;
	interval_end_ = b;
}
void Console_::cin_number_in_interval(string text) {
	cout << text + "(" << interval_start() << "-" << interval_end() << ")" << endl;
	int input;
	while (!(cin >> input) || interval_start() > input || input > interval_end()) {
		std::cout << "Netinkamas ivesties formatas. Iveskite is naujo: " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	input_ = input;
}
void Console_::confirmation(string text) {
	cout << text + "(y/n)" << endl;
	char c;
	if (cin >> c) c_ = std::tolower(c);
}
bool Console_::is_confirmed() {
	return get_c() == 'y';
}