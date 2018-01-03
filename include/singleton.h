/********************************************
    * File Name :   "singleton.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  24/12/2017
********************************************/

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include "QString"

template <typename T>
class Singleton
{
protected:
	Singleton() {};
	~Singleton() {};
	Singleton(const T&) = delete;
	T& operator=(const T&) = delete;


public:
	static T* getInstance()
	{
		if (apInstance == NULL)
		{
			std::cout << "Creating singleton" << std::endl;
			apInstance = new T();
		}
		else
			std::cout << "Singleton already created..." << std::endl;

		return (static_cast<T*>(apInstance));
	}

	static T* getInstance(const QString& path)
	{
		if (apInstance == NULL)
		{
			std::cout << "Creating singleton" << std::endl;
			apInstance = new T(path);
		}
		else
			std::cout << "Singleton already created..." << std::endl;

		return (static_cast<T*>(apInstance));
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
	static T* apInstance;
};

template <typename T>
T* Singleton<T>::apInstance = NULL;

#endif // SINGLETON_H