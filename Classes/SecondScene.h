#ifndef __SECONDSCENE_SCENE_H__
#define __SECONDSCENE_SCENE_H__

#include "cocos2d.h"


USING_NS_CC;

class SecondScene : public CCLayer
{
public:
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();
	void StartButtonCallBack(CCObject* pSender);
	// implement the "static node()" method manually
	CREATE_FUNC(SecondScene);
};

#endif // __SECONDSCENE_SCENE_H__