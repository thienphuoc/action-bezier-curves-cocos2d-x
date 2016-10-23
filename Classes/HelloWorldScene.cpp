#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
	auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto layerColor = LayerColor::create(Color4B::BLACK);
	addChild(layerColor, -10);

	cocos2d::ccBezierConfig bezier;
	bezier.controlPoint_1 = Point(200, 200);
	bezier.controlPoint_2 = Point(250, 300);
	bezier.endPosition	= Point(300, 200);

	auto controlPoint_1 = Sprite::create("point.png");
	controlPoint_1->setColor(Color3B::RED);
	controlPoint_1->setPosition(bezier.controlPoint_1);
	addChild(controlPoint_1);

	auto controlPoint_2 = Sprite::create("point.png");
	controlPoint_2->setColor(Color3B::BLUE);
	controlPoint_2->setPosition(bezier.controlPoint_2);
	addChild(controlPoint_2);

	auto endPosition = Sprite::create("point.png");
	endPosition->setColor(Color3B::GREEN);
	endPosition->setPosition(bezier.endPosition);
	addChild(endPosition);

	auto sprTest = Sprite::create("10x10.png");
	sprTest->setPosition(100, 100);
	sprTest->setName("sprTest");
	sprTest->runAction(BezierTo::create(2, bezier));
	addChild(sprTest);

 	scheduleUpdate();
    return true;
}
void HelloWorld::update(float delta){

	auto sprTest = (Sprite*) this->getChildByName("sprTest");
	//cocos2d::log("x=%f,y=%f", sprTest->getPositionX(), sprTest->getPositionY());
	auto point = Sprite::createWithTexture(cocos2d::TextureCache::getInstance()->addImage("1x1.png"));
	point->setPosition(sprTest->getPosition());
	addChild(point);

}

