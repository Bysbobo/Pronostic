 /********************************************
    * File Name : 	"DbManager.cpp"
    * Authors : 	P. Boix and E. Moussy
    * Created on : 	30/11/2017
********************************************/

#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
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
    }
}

bool DbManager::printTeam(const QString& table)
{
	bool success = false;

	QSqlQuery query;
	query.prepare("SELECT * FROM (:table);");
	query.bindValue(":table", table);

	if (query.exec())
	{
		success = true;
	}
	else
	{
		qDebug() << "addPerson error:  " << query.lastError();
	}

	return success;
}