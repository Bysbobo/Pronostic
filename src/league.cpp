/********************************************
    * File Name :   "league.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#include <iostream>
#include "league.h"

League::League()
{

}

League::~League()
{

}

void League::displayAll() const
{
	std::cout << aId << " - "
			  << aName.toStdString() << " - "
			  << aArea.toStdString() << std::endl;
}

void League::setId(const int& id)
{
	aId = id;
}

void League::setName(const QString& name)
{
	aName = name;
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
