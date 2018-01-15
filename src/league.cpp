/********************************************
    * File Name :   "league.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#include <QDebug>
#include "league.h"

League::League()
{

}

League::~League()
{

}

void League::displayAll() const
{
	qDebug() << aId << " - "
			 << aName << " - "
			 << aNumberTeams << " - "
			 << aArea;
}

int League::getId() const
{
	return aId;
}

void League::setId(const int& id)
{
	aId = id;
}

void League::setName(const QString& name)
{
	aName = name;
}

void League::setNumberTeams(const int& numberTeams)
{
	aNumberTeams = numberTeams;
}

void League::setArea(const QString& area)
{
	aArea = area;
}

void League::addAnOtherTeamId()
{

}

void League::addAnOtherMatchId()
{

}
