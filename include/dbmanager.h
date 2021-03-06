/********************************************
    * File Name :   "dbmanager.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  30/11/2017
********************************************/

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "singleton.h"
#include "team.h"
#include "match.h"
#include "league.h"
#include <QSqlDatabase>

/**
 * @brief The DbManager class defines the connection to the database for information for Prono application.
 */
class DbManager : public Singleton<DbManager>
{

    friend class Singleton<DbManager>;

private:
    /**
     * @brief The constructor of the DB Manager.
     * @param path : The path of the database.
     */
    DbManager(const QString& path);
    /**
     * @brief The destructor of the DB Manager.
     */
    ~DbManager();

public:
	/**
     * @brief This method is used to check if database connection is correct.
     */
    bool isOpen() const;
    /**
     * @brief This method is used to display all teams from the database.
     */
    bool displayTeams() const;
    /**
     * @brief This method is used to extract teams information from database.
     * @param team : The required team.
     */
    bool extractTeam(const int& teamId, Team& t);
    /**
     * @brief This method is used to display all matches from the database.
     */
    bool displayMatches() const;
    /**
     * @brief This method is used to extract matches information from database.
     * @param match : The required match.
     */
    bool extractMatch(const int& matchId, Match& m);
    /**
     * @brief This method is used to fill matches to the database.
     * @param id : The match id.
     * @param hTName : The hometeam name of the match.
     * @param aTName : The awayteam name of the match.
     * @param hTScore : The hometeam score of the match.
     * @param aTScore : The awayteam score of the match.
     */
    bool fillMatch(const int& id,
                   const int& hTName,
                   const int& aTName,
                   const int& hTScore,
                   const int& aTScore);
    /**
     * @brief This method is used to display all leagues from the database.
     */
    bool displayLeagues() const;
    /**
     * @brief This method is used to extract leagues information from database.
     * @param league : The required league.
     */
    bool extractLeague(const int& leagueId, League& l);

private:
    /**
     * @brief aDb : The DB connection.
     */
    QSqlDatabase aDb;
};

#endif // DBMANAGER_H