/********************************************
    * File Name :   "team.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#ifndef TEAM_H
#define TEAM_H

#include <QVector>
#include <QString>

class Team
{
public:
	Team();
	~Team();

	void displayAll() const;
	
	int getId() const;
	QString getSmallName() const;

	void setId(const int& id);
	void setSmallName(const QString& name);
	void setFullName(const QString& name);
	void setLeagueIdList(const QString& leagueList);

	void addAnOtherMatchId();
private:
	int aId;
	QString aSmallName;
	QString aFullName;
	QVector<int> aLeaguesId;

	QVector<int> aMatchesId;
};

#endif // TEAM_H