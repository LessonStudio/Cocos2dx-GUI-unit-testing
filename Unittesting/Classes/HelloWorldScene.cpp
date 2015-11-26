#include "HelloWorldScene.h"
#include "CommonCrap.h"
#include "SceneOne.hpp"
#include "SceneTwo.hpp"
#include "SceneThree.hpp"

USING_NS_CC;
Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
	layer->setTag(MAIN_LAYER);
#ifdef UNIT_TESTING
	CommonCrap::SetPresentLayer(layer, WHO_HELLO);
#endif
    scene->addChild(layer);
	
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::ClickButDoLittle, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    return true;
}

#include <math.h>
void HelloWorld::ClickButDoLittle(Ref* pSender)
{
	srand(time(NULL));
	int random=rand()%3;
	Scene *scene=NULL;
	if(random==0)
	{
		scene=SceneOne::createScene();
	}
	else if (random==1)
	{
		scene=SceneTwo::createScene();
	}
	else if (random==2)
	{
		scene=SceneThree::createScene();
	}
	Director::getInstance()->replaceScene(scene);
#ifdef UNIT_TESTING
	printf("Do little!!!");
#endif
}
