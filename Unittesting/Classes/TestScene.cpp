//
//  TestScene.cpp
//  Unittesting
//
//  Created by Donovan on 2015-11-25.
//
//

#include "TestScene.hpp"

USING_NS_CC;

Scene* TestScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TestScene::create();
	scene->addChild(layer);
	return scene;
}

bool TestScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	
	return true;
}
