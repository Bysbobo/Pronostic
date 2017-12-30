/********************************************
    * File Name :   "team.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#include <iostream>
#include "team.h"

Team::Team()
{
	
}

Team::~Team()
{

}

void Team::displayAll() const
{
	std::cout << aId << " - "
			  << aSmallName.toStdString() << " - "
			  << aFullName.toStdString() << std::endl;
}

int Team::getId() const
{
	return aId;
}

QString Team::getSmallName() const
{
	return aSmallName;
}

void Team::setId(const int& id)
{
	aId = id;
}

void Team::setSmallName(const QString& name)
{
	aSmallName = name;
}

void Team::setFullName(const QString& name)
{
	aFullName = name;
}

void Team::setLeagueIdList(const QString& leagueList)
{
	QString list = leagueList;

	int max = list.count(",");
	for (int i = 0; i <= max; ++i)
	{
		int separatorIndex = list.indexOf(","); // Find the first separator
		aLeaguesId.push_back(list.left(separatorIndex).toInt()); // Extract data before separatorIndex
		list.remove(0, separatorIndex+1); // Delete char already saved
	}
	/*
	for (unsigned int i = 0; i < aLeaguesId.size(); ++i)
		std::cout << aLeaguesId[i] << std::endl;
	*/
}

void Team::addAnOtherMatchId()
{
	
}