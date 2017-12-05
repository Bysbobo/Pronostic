/********************************************
    * File Name :   "match.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#ifndef MATCH_H
#define MATCH_H

#include <QString>
#include "dbmanager.h"

class Match
{
public:
	Match(DbManager *path = 0);
	~Match();

private:
	QString aHomeTeamName;
	QString aAwayTeamName;
	int aHomeTeamScore;
	int aAwayTeamScore;
	int aLeagueId;
};

#endif // MATCH_H