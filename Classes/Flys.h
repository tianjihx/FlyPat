#ifndef _FLYS_CLASSES
#define _FLYS_CLASSES
#include "cocos2d.h"
USING_NS_CC;



class Fly : CCSprite
{
public:
	Fly(void);
	~Fly(void);
	

protected:
	int iHP;
	int iMP;
	int iSpeed;
	int iBaseScore;
};

class NormalFly :
	public Fly
{
public:
	NormalFly(void);
	~NormalFly(void);
};


//Ω· ¯∫Í∂®“Â
#endif