/********************************************
    * File Name : 	"dbmanager.cpp"
    * Authors : 	P. Boix and E. Moussy
    * Created on : 	30/11/2017
********************************************/

#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

DbManager::DbManager(const QString& path)
{
    aDb = QSqlDatabase::addDatabase("QSQLITE");
    aDb.setDatabaseName(path);
 
    if (!aDb.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DbManager::~DbManager()
{
    if (aDb.isOpen())
    {
        aDb.close();
        qDebug() << "Database: deconnection ok";
    }
}

bool DbManager::isOpen()
{
    return aDb.isOpen();
}

bool DbManager::displayTeams()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("SELECT * FROM team;");
    if (query.exec())
    {
        success = true;

        int idId = query.record().indexOf("id");
        int idSmallName = query.record().indexOf("small_name");
        int idFullName = query.record().indexOf("full_name");
        int idLeaguesId = query.record().indexOf("leagues_id");
        while (query.next())
        {
            QString theId = query.value(idId).toString();
            QString theSmallName = query.value(idSmallName).toString();
            QString theFullName = query.value(idFullName).toString();
            QString theLeaguesId = query.value(idLeaguesId).toString();
            qDebug() << theId << "-"
                     << theSmallName << "-"
                     << theFullName << "-"
                     << theLeaguesId;
        }
    }
    else
        qDebug() << "printTeam error: " << query.lastError();

    return success;
}

bool DbManager::displayMatches()
{
	bool success = false;

    QSqlQuery query;
    query.prepare("SELECT * FROM match;");
    if (query.exec())
    {
        success = true;

        int idId = query.record().indexOf("id");
        int idHomeTeamId = query.record().indexOf("home_team_id");
        int idAwayTeamId = query.record().indexOf("away_team_id");
        int idLeagueId = query.record().indexOf("league_id");
        int idHomeTeamScore = query.record().indexOf("home_team_score");
        int idAwayTeamScore = query.record().indexOf("away_team_score");
        while (query.next())
        {
            QString theId = query.value(idId).toString();
            QString theHomeTeamId = query.value(idHomeTeamId).toString();
            QString theAwayTeamId = query.value(idAwayTeamId).toString();
            QString theLeagueId = query.value(idLeagueId).toString();
            QString theHomeTeamScore = query.value(idHomeTeamScore).toString();
            QString theAwayTeamScore = query.value(idAwayTeamScore).toString();
            qDebug() << theId << "-"
                     << theHomeTeamId << "-"
                     << theAwayTeamId << "-"
                     << theLeagueId << "-"
                     << theHomeTeamScore << "-"
                     << theAwayTeamScore;
        }
    }
    else
        qDebug() << "printTeam error: " << query.lastError();

    return success;
}

bool DbManager::displayLeagues()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("SELECT * FROM league;");
    if (query.exec())
    {
        success = true;

        int idId = query.record().indexOf("id");
        int idName = query.record().indexOf("name");
        int idArea = query.record().indexOf("area");
        while (query.next())
        {
            QString theId = query.value(idId).toString();
            QString theName = query.value(idName).toString();
            QString theAera = query.value(idArea).toString();
            qDebug() << theId << "-"
                     << theName << "-"
                     << theAera;
        }
    }
    else
        qDebug() << "printTeam error: " << query.lastError();

    return success;
}
