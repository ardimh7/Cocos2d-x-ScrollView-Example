#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    
    ui::ScrollView *scrollView = ui::ScrollView::create();
    scrollView->setDirection(ui::ScrollView::Direction::BOTH);
    scrollView->setContentSize( Size(visibleSize.width + origin.x, visibleSize.height + origin.y) ); // ukuran "SELURUH" nya, (frame, luar nya)
    
    scrollView->setBackGroundImage("belakang.png");
    //scrollView->setBounceEnabled(true);
    scrollView->setAnchorPoint( Vec2( 0.5, 0.5 ) );
    scrollView->setPosition( Vec2( visibleSize.width / 2, visibleSize.height / 2 ) );
    
    
    Sprite* map = Sprite::create("gunung.jpg");
    map->setPosition(Vec2( visibleSize.width * 0, visibleSize.height * 0 ));
    map->setAnchorPoint(Vec2(0,0));
    map->setScale(2);
    
    scrollView->setInnerContainerSize( Size(map->getBoundingBox().size.width, map->getBoundingBox().size.height) );
    
    
    scrollView->addChild( map );
    
    
    this->addChild( scrollView );
    
    
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
