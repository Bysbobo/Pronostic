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
    QSqlQuery query;
    query.prepare("SELECT * FROM team;");

    if (isOpen() && query.exec())
    {
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
        return true;
    }

    qDebug() << "printTeam error: " << query.lastError();
    return false;
}

bool DbManager::extractTeam(const int& teamId, Team& t)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM team WHERE id = (:teamId) ;");
    query.bindValue(":teamId", QVariant(teamId));

    /*  0 - Id of this team
     *  1 - Small name
     *  2 - Full name
     *  3 - Ids of league
     */
    if (isOpen() && query.exec() && query.next())
    {
        t.setId(query.value(0).toInt());
        t.setSmallName(query.value(1).toString());
        t.setFullName(query.value(2).toString());
        t.setLeagueIdList(query.value(3).toString());
        
        return true;
    }
    
    //qDebug() << "extractTeam error: " << query.lastError();
    return false;
}

bool DbManager::displayMatches()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM match;");

    if (isOpen() && query.exec())
    {
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
        return true;
    }

    qDebug() << "printTeam error: " << query.lastError();
    return false;
}

bool DbManager::extractMatch(const int& matchId, Match& m)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM match WHERE id = (:matchId) ;");
    query.bindValue(":matchId", QVariant(matchId));

    /*  0 - Id of this match
     *  1 - Home team Id
     *  2 - Away team Id
     *  3 - Id of league
     *  4 - Home team Score
     *  5 - Away team Score
     */
    if (isOpen() && query.exec() && query.next())
    {
        m.setId(query.value(0).toInt());
        m.setHomeTeamName(query.value(1).toString());
        m.setAwayTeamName(query.value(2).toString());
        m.setLeagueId(query.value(3).toInt());
        m.setHomeTeamScore(query.value(4).toInt());
        m.setAwayTeamScore(query.value(5).toInt());

        return true;
    }

    //qDebug() << "extractMatch error: " << query.lastError();
    return false;
}

bool DbManager::displayLeagues()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM league;");

    if (isOpen() && query.exec())
    {
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
        return true;
    }

    qDebug() << "printLeagues error: " << query.lastError();
    return false;
}

bool DbManager::extractLeague(const int& leagueId, League& l)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM league WHERE id = (:leagueId) ;");
    query.bindValue(":leagueId", QVariant(leagueId));

    if (isOpen() && query.exec() && query.next())
    {
        /*  0 - Id of this league
         *  1 - Name
         *  2 - Area
         */
        l.setId(query.value(0).toInt());
        l.setName(query.value(1).toString());
        l.setArea(query.value(2).toString());
    
        return true;
    }

    //qDebug() << "extractLeague error: " << query.lastError();
    return false;
}