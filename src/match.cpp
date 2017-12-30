/********************************************
    * File Name :   "match.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#include <iostream>
#include "match.h"

Match::Match()
{

}

Match::~Match()
{

}

void Match::displayAll() const
{
	std::cout << aId << " - "
			  << aHomeTeamName.toStdString() << " - "
			  << aAwayTeamName.toStdString() << " - "
			  << aLeagueId << " - "
			  << aHomeTeamScore << " - "
			  << aAwayTeamScore << std::endl;
}

void Match::setId(const int& id)
{
	aId = id;
}

void Match::setLeagueId(const int& LeagueId)
{
	aLeagueId = LeagueId;
}

void Match::setHomeTeamName(const QString& homeTeamName)
{
	aHomeTeamName = homeTeamName;
}

void Match::setAwayTeamName(const QString& awayTeamName)
{
	aAwayTeamName = awayTeamName;
}

void Match::setHomeTeamScore(const int& homeTeamScore)
{
	aHomeTeamScore = homeTeamScore;
}

void Match::setAwayTeamScore(const int& awayTeamScore)
{
	aAwayTeamScore = awayTeamScore;
}


