#pragma once
#ifndef _RANDOMIZER_TRACK_H
#define _RANDOMIZER_TRACK_H
namespace sdds {
	class Track {
		// Empty state is defined as m_trackID, m_season, m_trackConditions and m_time = NULL or 0.
		int m_trackID;
		char* m_trackName;
		int m_season;
		int m_trackConditions;
		int m_time;
		void setEmptyTrack();

	public:
		Track();
		Track(int id, int season, int conditions, int time);
		~Track();
		int getTrackID();
		char* getTrackName();
		int getSeason();
		int getTrackConditions();
		int getTime();
	};
}
#endif // _RANDOMIZER_TRACK_H