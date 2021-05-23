#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Track.h"
#include "utils.h"

namespace sdds {
	bool m_dlcEnabled = false;
	bool exit = false;

	int main() {
		dlcEvents();
		
		return 0;
	}

	int randomTrack() {
		
	}

	void dlcEvents() {
		int choice = 0;
		std::cout << "Enable DLC events?";
		std::cout << "1. Yes";
		std::cout << "2. No";
		choice = getInt(1, 2);
		if (choice == 1) {
			m_dlcEnabled = true;
		} else {
			m_dlcEnabled = false;
		}
	}

	int menu() {
		int choice = 0;
		std::cout << "Choose a task\n";
		std::cout << "1. Randomize Cars and Tracks\n";
		std::cout << "2. Randomize Cars only\n";
		std::cout << "3. Randomize Track only\n";
		std::cout << "> ";
	}
}