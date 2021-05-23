#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "utils.h"
#include "Time.h"

using namespace std;
namespace sdds {
	bool debug = false;  // made global in utils.h

	int getInt(const char* prompt) {
		bool valid = true;
		int input = -1;

		if (prompt != nullptr) {
			std::cout << prompt;
		}

		do {
			valid = true;
			std::cin >> input;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(512, '\n');
				valid = false;
				std::cout << "Bad integer value, try again: ";
			} else if (std::cin.get() != '\n') {
				std::cin.clear();
				std::cin.ignore(512, '\n');
				valid = false;
				std::cout << "Enter only an integer, try again: ";
			}

			
		} while (!valid);
		return input;
	}

	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
		int input = -2;

		do {
			if (input == -2) {
				input = getInt(prompt);
			} else {
				input = getInt();
			}

			if (min > input || input > max) {
				if (errorMessage != NULL) {
					std::cout << errorMessage;
					input = -1;
				}
				if (showRangeAtError) {
					std::cout << '[' << min << " <= value <= " << max << ']' << ": ";
					input = -1;
				}
			}
		} while (input <= -1);
		return input;
	}

	char* getcstr(const char* prompt, std::istream& istr, char delimiter) {
		char* returned;
		char temp[1024] = { 0 };
		if (prompt != NULL) {
			std::cout << prompt;
			if (delimiter != '\0') {
				istr.getline(temp, 1024, delimiter);
			} else {
				istr.getline(temp, 1024);
			}
		}
		returned = new char[strlen(temp) + 1]();
		strcpy(returned, temp);
		return returned;
	}

	int getHour(int minutes) {
		return minutes / 60;
	}

	int getMinute(int minutes) {
		return minutes % 60;
	}
}