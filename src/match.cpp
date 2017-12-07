/********************************************
    * File Name :   "match.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  04/12/2017
********************************************/

#include "match.h"
#include "dbmanager.h"
#include <iostream>

Match::Match(DbManager *dbMan)
{
	if (dbMan->isOpen())
	{
		std::cout << "Match" << std::endl;
		if (dbMan->extractMatch("1")) std::cout << "OK match" << std::endl;
	}
}

Match::~Match()
{

}
