//
//  TestScene.hpp
//  Unittesting
//
//  Created by Donovan on 2015-11-25.
//
//

#ifndef TestScene_hpp
#define TestScene_hpp

#include "cocos2d.h"

class TestScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	
	virtual bool init();
	
	CREATE_FUNC(TestScene);
};


#endif /* TestScene_hpp */
