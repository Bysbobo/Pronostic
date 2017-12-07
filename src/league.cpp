/********************************************
    * File Name :   "league.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#include "league.h"
#include "dbmanager.h"
#include <iostream>

League::League(DbManager *dbMan)
{
	if (dbMan->isOpen())
	{
		std::cout << "League" << std::endl;
		if (dbMan->extractLeague("1")) std::cout << "OK league" << std::endl;
	}
}

League::~League()
{

}
