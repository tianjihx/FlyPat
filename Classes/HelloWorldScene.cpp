#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	anode = CCNode::create();
	this->addChild(anode,0);
	anode->setTag(100);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);//将菜单作为子节点加入之前定义的节点中

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello!Cocos2d-x!", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    //this->addChild(pLabel, 1);
	anode->addChild(pLabel,1);
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
	pSprite->setTag(101);
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	pSprite->setScale(1.5);
    // add the sprite as a child to this layer
    //this->addChild(pSprite, 0);
    anode->addChild(pSprite,0);

	CCSprite* pFlySprite = CCSprite::create("fly_64.png");
	pFlySprite->setTag(111);
	pFlySprite->setPosition(ccp(200,200));
	anode->addChild(pFlySprite);
	
	anode->setPosition(0,0);
	/*CCActionInterval* move = CCMoveBy::create(1,ccp(200,200));
	CCActionInterval* back = move->reverse();
	CCFiniteTimeAction* swq = CCSequence::create(move,back,NULL);
	pFlySprite->runAction(CCRepeatForever::create((CCActionInterval*)swq));*/
	this->setTouchEnabled(true);
	scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta)
{
	//int x,y;
	//getChildByTag(2)->getPosition(x,y);
	//(this->getChildByTag(100)->getChildByTag(101))->setPosition(this->getChildByTag(100)->getChildByTag(102)->getPosition());
}


void HelloWorld::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	CCPoint touchLocation = touch->getLocation();
	//this->anode->getChildByTag(111)->setPosition(ccp(touchLocation.x, touchLocation.y));


	CCActionInterval* move = CCBlink::create(1,2);
	CCActionInterval* waterWave = CCWaves::create(2,ccp(10,10),10,10,1,1);

	this->anode->getChildByTag(111)->stopAllActions();
	this->anode->getChildByTag(111)->runAction(move);
	this->anode->getChildByTag(101)->runAction(waterWave);
}



void  HelloWorld::ccTouchesMoved(CCSet*pTouches, CCEvent *pEvent)
{
	/*CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	CCPoint touchLocation = touch->getLocation();
	this->anode->getChildByTag(111)->setPosition(ccp(touchLocation.x, touchLocation.y));*/
	//this->anode->getChildByTag(111)->stopAllActions();
}



void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
