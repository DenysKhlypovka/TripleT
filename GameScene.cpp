#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include <string>

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	game = new Game(this);

	auto backgroundSprite = Sprite::create("Game.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	Sprite* grid = Sprite::create("grid.png");
	grid->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));


	this->addChild(grid);
    
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	this->scheduleUpdate();

    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	Vec2 t = touch->getLocation();

	game->PlaceObj(this, t.x, t.y);
	if (game->Check() != 10)
	{
		char GO;
		if (game->Check() == 1)
			GO = game->turn;
		else 
			GO = 'D';

		auto scene = GameOver::createScene(GO);
		Director::getInstance()->replaceScene((TransitionFade::create(TRANSITION_TIME, scene)));
	
	}

	return true;
}

void GameScene::GoToGameOverScene(float dt)
{
	//auto scene = GameOver::createScene(game->turn);

	//Director::getInstance()->replaceScene(scene);
}