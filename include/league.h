/********************************************
    * File Name :   "league.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#ifndef LEAGUE_H
#define LEAGUE_H

#include <vector>
#include <QString>
#include "dbmanager.h"

class League
{
public:
	League(DbManager *path = 0);
	~League();

private:
	QString aName;
	QString aArea;
	std::vector<int> aTeamsId;
	std::vector<int> aMatchesId;
};

#endif // LEAGUE_H