/********************************************
    * File Name :   "league.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#ifndef LEAGUE_H
#define LEAGUE_H

#include <QVector>
#include <QString>

class League
{
public:
	League();
	~League();

	void displayAll() const;

	void setId(const int& id);
	void setName(const QString& name);
	void setNumberTeams(const int& numberTeams);
	void setArea(const QString& area);

	void addAnOtherTeamId();
	void addAnOtherMatchId();

private:
	int aId;
	QString aName;
	int aNumberTeams;
	QString aArea;

	QVector<int> aTeamsId;
	QVector<int> aMatchesId;
};

#endif // LEAGUE_H