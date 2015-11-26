//
//  CommonCrap.hpp
//  Unittesting
//
//  Created by Donovan on 2015-11-25.
//
//

#ifndef CommonCrap_hpp
#define CommonCrap_hpp
#include "cocos2d.h"
USING_NS_CC;
#define MAIN_LAYER 10000
#ifdef UNIT_TESTING

#define WHO_HELLO 10
#define WHO_ONE 1
#define WHO_TWO 2
#define WHO_THREE 3

#endif
namespace CommonCrap
{
#ifdef UNIT_TESTING
	void SetPresentLayer(Layer *, int);
	Layer *GetPresentLayer();
	int GetWhosRunning();
#endif
}

#endif /* CommonCrap_hpp */
