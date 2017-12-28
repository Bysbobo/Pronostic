/********************************************
    * File Name :   "team.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <QString>

class Team
{
public:
	Team();
	~Team();

	void displayAll() const;
	
	void setId(const int& id);
	void setSmallName(const QString& name);
	void setFullName(const QString& name);
	void setLeagueIdList(const QString& leagueList);

	void addAnOtherMatchId();
private:
	int aId;
	QString aSmallName;
	QString aFullName;
	std::vector<int> aLeaguesId;

	std::vector<int> aMatchesId;
};

#endif // TEAM_H