#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Track.h"
#include "Car.h"
#include "utils.h"

namespace sdds {
	void dlcEvents();
	int menu();
	int randomTrack();
	int randomCar();

	bool m_dlcEnabled = false;
	int choice = 0;

	int main() {
		dlcEvents();
		choice = menu();
		while (choice != -1) {
			switch (choice) {
			case 1:
				randomTrack();
				randomCar();
				break;
			case 2:
				randomCar();
				break;
			case 3:
				randomTrack();
				break;
			case 4:
				if (m_dlcEnabled) {
					m_dlcEnabled = false;
				} else {
					m_dlcEnabled = true;
				}
				break;
			case 5:
				choice = -1;
			}
		} 
		return 0;
	}

	int randomTrack() {
		return 0;
	}

	int randomCar() {
		return 0;
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
		if (m_dlcEnabled) {
			std::cout << "4. Disable DLC events\n";
		} else {
			std::cout << "4. Enable DLC events\n";
		}
		std::cout << "5. Exit\n";
		std::cout << "> ";
		choice = getInt(1, 5);
		return choice;
	}
}