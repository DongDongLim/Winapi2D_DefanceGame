#pragma once

#define SINGLETON(CLASS)			\
									\
private:							\
	CLASS();						\
	~CLASS();						\
									\
public:								\
	static	CLASS* getInst()		\
	{								\
		static CLASS _instance;		\
		return &_instance;			\
	}								\
private:

