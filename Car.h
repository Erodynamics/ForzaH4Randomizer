#pragma once
#ifndef _RANDOMIZER_CAR_H
#define _RANDOMIZER_CAR_H

namespace sdds {
	class Cars {
		// Empty State is defined as m_carClass == NULL.
		char* m_model;
		char* m_carClass;
		bool m_homologated;
		void setEmptyCars();

	public:
		Cars();
		Cars(char* model, char* carClass, bool homologated);
		Cars(char* carClass, bool homologated);
		~Cars();

		// Functions
		char* getModel();
		char* getCarClass();
		bool isHomologated();

		// Operators
		std::ostream& display(std::ostream& os) const;
		operator bool()const;
	};

	std::ostream& operator<<(std::ostream& os, const Cars& car);
}

#endif // _RANDOMIZER_CAR_H