#include "Flys.h"

//class <Fly : CCSprite> Implement ////////////////////////////////////

Fly::Fly(void)
{
}


Fly::~Fly(void)
{
}



//class <NormalFly : Fly> Implement ///////////////////////////////////

NormalFly::NormalFly(void)
{	
	this->iHP = 1;
	this->iMP = 0;
	this->iSpeed = 5;
	this->iBaseScore = 10;
}



NormalFly::~NormalFly(void)
{
}
