//
//  SceneTwo.hpp
//  Unittesting
//
//  Created by Donovan on 2015-11-25.
//
//

#ifndef SceneTwo_hpp
#define SceneTwo_hpp

#include "cocos2d.h"

class SceneTwo : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	
	virtual bool init();
	
	// a selector callback
	void ClickCloseButDoLittle(cocos2d::Ref* pSender);
	
	// implement the "static create()" method manually
	CREATE_FUNC(SceneTwo);
};


#endif /* SceneTwo_hpp */
