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

private:
	QString aHomeTeamName;
	QString aAwayTeamName;
	int aHomeTeamScore;
	int aAwayTeamScore;
};

#endif // MATCH_H