/********************************************
    * File Name :   "team.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <QString>
#include "dbmanager.h"

class Team
{
public:
	Team(DbManager *path = 0);
	~Team();

private:
	QString aSmallName;
	QString aFullName;
	std::vector<int> aLeaguesId;
	std::vector<int> aMatchesId;
};

#endif // TEAM_H