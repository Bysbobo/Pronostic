/********************************************
    * File Name :   "singleton.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  24/12/2017
********************************************/

#ifndef SINGLETON_H
#define SINGLETON_H

<<<<<<< HEAD
#include <QString>
=======
#include <iostream>
#include "QString"
>>>>>>> 64a4111d650ff3d541d30e0c219f49ae1bee7548

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
			qDebug() << "Creating singleton";
			apInstance = new T();
		}
		else
			qDebug() << "Singleton already created...";


		return (static_cast<T*>(apInstance));
	}

	static T* getInstance(const QString& path)
	{
		if (apInstance == NULL)
		{
			qDebug() << "Creating singleton";
			apInstance = new T(path);
		}
		else
			qDebug() << "Singleton already created...";

		return (static_cast<T*>(apInstance));
	}
	
	static void kill()
	{
		if (apInstance != NULL)
		{
			delete apInstance;
			apInstance = NULL;

			qDebug() << "Singleton deleted...";
		}
	}


private:
	static T* apInstance;
};

template <typename T>
T* Singleton<T>::apInstance = NULL;

#endif // SINGLETON_H