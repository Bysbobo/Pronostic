/********************************************
    * File Name :   "team.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#include "team.h"
#include "dbmanager.h"
#include <iostream>

Team::Team(DbManager *dbMan)
{
	if (dbMan->isOpen())
	{
		std::cout << "Team" << std::endl;
		if (dbMan->extractTeam("17")) std::cout << "OK team" << std::endl;
	}
}

Team::~Team()
{

}