#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "json.hpp"
#include "Track.h"

using json = nlohmann::json;
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
}