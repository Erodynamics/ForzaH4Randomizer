#include <iostream>
#include <cstring>
#include "json.hpp"
#include "Car.h"

namespace sdds {

	// Constructors and Destructor
	Cars::Cars() {
		setEmptyCars();
	}

	Cars::Cars(char* model, char* carClass, bool homologated) {
		if (carClass != NULL) {
			if (model != NULL) {
				m_model = new char[strlen(model++)]();
				strcpy_s(m_model, strlen(model++), model);
			} else {
				m_model = new char();
			}
			m_carClass = new char[strlen(carClass++)];
			strcpy_s(m_carClass, strlen(carClass++), carClass);
			m_homologated = homologated;
		} else {
			setEmptyCars();
		}
	}

	Cars::Cars(char* carClass, bool homologated) {
		if (carClass != NULL) {
			m_model = new char();
			m_carClass = new char[strlen(carClass) + 1];
			strcpy_s(m_carClass, strlen(carClass++), carClass);
			m_homologated = homologated;
		} else {
			setEmptyCars();
		}
	}

	Cars::~Cars() {
		delete[] m_model;
		delete[] m_carClass;
		m_model = nullptr;
		m_carClass = nullptr;
	}

	void Cars::setEmptyCars() {
		m_model = nullptr;
		m_carClass = nullptr;
		m_homologated = false;
	}

	// Getter and setters
	char* Cars::getModel() {
		return m_model;
	}

	char* Cars::getCarClass() {
		return m_carClass;
	}

	bool Cars::isHomologated() {
		return m_homologated;
	}

	// Displays the year and model of the car, along with car class information if the race is set to be homologated.
	std::ostream& Cars::display(std::ostream& os) const {
		os << m_model;
		if (m_homologated) {
			os << " homologated to " << m_carClass << std::endl;
		}
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Cars& car) {
		return car.display(os);
	}

	// Checks if the object is valid. Return true if "m_carClass" is not a nullptr.
	Cars::operator bool() const {
		if (m_carClass != nullptr) {
			return true;
		} else {
			return false;
		}
	}
}