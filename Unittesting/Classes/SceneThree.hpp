//
//  SceneThree.hpp
//  Unittesting
//
//  Created by Donovan on 2015-11-25.
//
//

#ifndef SceneThree_hpp
#define SceneThree_hpp

#include "cocos2d.h"

class SceneThree : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	
	virtual bool init();
	
	// a selector callback
	void SpecialScene3Button(cocos2d::Ref* pSender);
	
	// implement the "static create()" method manually
	CREATE_FUNC(SceneThree);
};


#endif /* SceneThree_hpp */
