#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Track.h"

namespace sdds {
	void Track::setEmptyTrack() {
		m_trackID = 0;
		m_trackName = nullptr;
		m_season = 0;
		m_trackConditions = 0;
		m_time = 0;
	}

	Track::Track() {
		setEmptyTrack();
	}

	Track::Track(int id, int season, int conditions, int time) {
		m_trackID = id;
		m_trackName = new char[100]();
		m_season = season;
		m_trackConditions = conditions;
		m_time = time;
	}

	Track::~Track() {
		delete[] m_trackName;
		m_trackName = nullptr;
	}

	int Track::getTrackID() {
		return m_trackID;
	}

	char* Track::getTrackName() {
		return m_trackName;
	}

	int Track::getSeason() {
		return m_season;
	}

	int Track::getTrackConditions() {
		return m_trackConditions;
	}

	int Track::getTime() {
		return m_time;
	}

	void Cars::setEmptyCars() {
		m_model = nullptr;
		m_carClass = nullptr;
		m_homologated = false;
	}

	Cars::Cars() {
		setEmptyCars();
	}

	Cars::Cars(char* model, char* carClass, bool homologated) {
		if (carClass != NULL) {
			if (model != NULL) {
				m_model = new char[strlen(model) + 1]();
				strcpy(m_model, model);
			} else {
				m_model = new char();
			}
			m_carClass = new char[strlen(carClass) + 1];
			strcpy(m_carClass, carClass);
			m_homologated = homologated;
		} else {
			setEmptyCars();
		}
	}

	Cars::Cars(char* carClass, bool homologated) {
		if (carClass != NULL) {
			m_model = new char();
			m_carClass = new char[strlen(carClass) + 1];
			strcpy(m_carClass, carClass);
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

	char* Cars::getModel() {
		return m_model;
	}

	char* Cars::getCarClass() {
		return m_carClass;
	}

	bool Cars::isHomologated() {
		return m_homologated;
	}

	Cars::operator bool() const {
		if (m_carClass != nullptr) {
			return true;
		} else {
			return false;
		}
	}
}