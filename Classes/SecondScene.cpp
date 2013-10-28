#include "SecondScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;
//class HelloWorld;

CCScene* SecondScene::scene()
{
	CCScene *scene = CCScene::create();

	SecondScene *layer = SecondScene::create();
	scene->addChild(layer);

	return scene;
}

bool SecondScene::init()
{
	if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSprite* bk = CCSprite::create("welcome_bk.jpg");
	bk->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(bk,0);
	
	//按钮
	CCMenuItemImage* startButton = CCMenuItemImage::create("welcome_button.png","welcome_button.png",this,menu_selector(SecondScene::StartButtonCallBack));
	CCMenu* pMenu = CCMenu::create(startButton, NULL);
	pMenu->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(pMenu, 1);//将菜单作为子节点加入之前定义的节点中

    return true;
}

void SecondScene::StartButtonCallBack(CCObject* pSender)
{
	CCScene* scene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1, scene));
}