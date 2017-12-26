/********************************************
    * File Name :   "league.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#ifndef LEAGUE_H
#define LEAGUE_H

#include <vector>
#include <QString>

class League
{
public:
	League();
	~League();

	void setId(const int& id);
	void setName(const QString& name);
	void setArea(const QString& area);

	void addAnOtherTeamId();
	void addAnOtherMatchId();

private:
	int aId;
	QString aName;
	QString aArea;

	std::vector<int> aTeamsId;
	std::vector<int> aMatchesId;
};

#endif // LEAGUE_H