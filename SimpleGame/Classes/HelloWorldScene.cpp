#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

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

void HelloWorld::upDateSprite(float dt) {
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *sprite = (CCSprite *)this->getChildByTag(1010);
    
    CCPoint spriteP = sprite->getPosition();
    CCSize cttSize = sprite->getContentSize();
    
    float maxRX = winSize.width - spriteP.x + cttSize.width/2;
    float maxLX = spriteP.x + cttSize.width/2;
    float maxTY = winSize.height - spriteP.y + cttSize.height/2;
    float maxBY = spriteP.y + cttSize.height/2;
    
    int direction = arc4random()%4 + 1;
    int X = 0;
    int Y = 0;
    CCLog("direction %d",direction);
    CCLog("winSize %f h %f",winSize.width,winSize.height);
    CCLog("maxRX %f maxLX %f",maxRX,maxLX);
    CCLog("cttSize %f h %f",cttSize.width,cttSize.height);
    switch (direction) {
        case 1:
        {
            X = arc4random()%(int)maxRX;
            Y = arc4random()%(int)maxTY;
        }
            break;
        case 2:
        {
            X = arc4random()%(int)maxLX;
            Y = arc4random()%(int)maxTY;
        }
            break;
        case 3:
        {
            X = arc4random()%(int)maxLX;
            Y = arc4random()%(int)maxBY;
            
        }
            break;
        case 4:
        {
            X = arc4random()%(int)maxRX;
            Y = arc4random()%(int)maxBY;
            
        }
            break;
        default:
            break;
    }
    CCMoveTo *moveAct = CCMoveTo::create(1.5, ccp(X,Y));
    sprite->runAction(moveAct);

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
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSprite *sprite = CCSprite::create("Fruit04.png");
    sprite->setTag(1010);
    sprite->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(sprite);
    


    this->schedule(schedule_selector(HelloWorld::upDateSprite), 1.5);
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
