//
//  SceneOne.hpp
//  Unittesting
//
//  Created by Donovan on 2015-11-25.
//
//

#ifndef SceneOne_hpp
#define SceneOne_hpp

#include "cocos2d.h"

class SceneOne : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	
	virtual bool init();
	
	// a selector callback
	void ClickCloseButDoLittle(cocos2d::Ref* pSender);
	
	// implement the "static create()" method manually
	CREATE_FUNC(SceneOne);
};


#endif /* SceneOne_hpp */
