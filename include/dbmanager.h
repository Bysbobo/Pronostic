/********************************************
    * File Name :   "DbManager.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  30/11/2017
********************************************/

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

class DbManager
{
public:
	DbManager(const QString& path);
	~DbManager();

	bool printTeam(const QString& table);

private:
	QSqlDatabase aDb;
};

#endif // DBMANAGER_H