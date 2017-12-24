/********************************************
    * File Name :   "singleton.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  24/12/2017
********************************************/

#include "singleton.h"
#include <iostream>

Singleton* Singleton::apInstance = NULL;

Singleton::Singleton()
{

}

Singleton::~Singleton()
{

}

Singleton* Singleton::getInstance()
{
	if (apInstance == NULL)
	{
		std::cout << "Creating singleton" << std::endl;
		apInstance = new Singleton();
	}
	else
		std::cout << "Singleton already created..." << std::endl;

	return apInstance;
}

void Singleton::kill()
{
	if (apInstance != NULL)
	{
		delete apInstance;
		apInstance = NULL;

		std::cout << "Singleton deleted..." << std::endl;
	}
}