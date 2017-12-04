/********************************************
    * File Name :   "team.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#ifndef TEAM_H
#define TEAM_H

#include <QString>

class Team
{
public:
	Team();
	~Team();

private:
	QString aSmallName;
	QString aFullName;
};

#endif // TEAM_H