/********************************************
    * File Name :   "match.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#ifndef MATCH_H
#define MATCH_H

#include <QString>

class Match
{
public:
	Match();
	~Match();

	void displayAll() const;

	void setId(const int& id);
	void setLeagueId(const int& LeagueId);
	void setHomeTeamName(const QString& homeTeamName);
	void setAwayTeamName(const QString& awayTeamName);
	void setHomeTeamScore(const int& homeTeamScore);
	void setAwayTeamScore(const int& awayTeamScore);

private:
	int aId;
	int aLeagueId;
	QString aHomeTeamName;
	QString aAwayTeamName;
	int aHomeTeamScore;
	int aAwayTeamScore;
};

#endif // MATCH_H