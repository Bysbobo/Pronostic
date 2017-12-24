/********************************************
    * File Name :   "singleton.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  24/12/2017
********************************************/

#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;


public:
	static Singleton* getInstance();
	static void kill();


private:
	static Singleton* apInstance;
};

#endif // SINGLETON_H