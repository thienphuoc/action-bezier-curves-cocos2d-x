#pragma once

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
	void update(float delta) override;

	CREATE_FUNC(HelloWorld);
};

