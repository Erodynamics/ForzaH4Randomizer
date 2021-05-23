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
		char* getModel();
		char* getCarClass();
		bool isHomologated();
		operator bool()const;
	};
}
#endif // _RANDOMIZER_TRACK_H