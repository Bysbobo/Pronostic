/********************************************
    * File Name :   "dbmanager.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  30/11/2017
********************************************/

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

class DbManager
{
public:
	    /**
     * @brief The constructor of the DB Manager.
     * @param path : The path of the database.
     */
	DbManager(const QString& path);
	/**
     * @brief The destructor of the DB Manager.
     */
	~DbManager();
	/**
     * @brief This method is used to check if database connection is correct.
     */
	bool isOpen();
	/**
     * @brief This method is used to display all teams from the database.
     */
	bool displayTeams();
	/**
     * @brief This method is used to display all matches from the database.
     */
	bool displayMatches();
	/**
     * @brief This method is used to display all leagues from the database.
     */
	bool displayLeagues();

private:
	QSqlDatabase aDb;
};

#endif // DBMANAGER_H