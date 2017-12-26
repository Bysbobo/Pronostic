/********************************************
    * File Name :   "singleton.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  24/12/2017
********************************************/

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

//template <typename T>
class Singleton
{
private:
	Singleton() {};
	~Singleton() {};
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;


public:
	static Singleton* getInstance()
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
	
	static void kill()
	{
		if (apInstance != NULL)
		{
			delete apInstance;
			apInstance = NULL;

			std::cout << "Singleton deleted..." << std::endl;
		}
	}


private:
	static Singleton* apInstance;
};

Singleton* Singleton::apInstance = NULL;

#endif // SINGLETON_H