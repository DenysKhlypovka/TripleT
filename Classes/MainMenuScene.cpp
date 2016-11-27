#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Background.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	auto titleSprite = Sprite::create("Title.png");
	titleSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize().height));

	this->addChild(titleSprite);

	auto playItem = MenuItemImage::create("Play Button.png", "Play Button Clicked.png", CC_CALLBACK_1(MainMenu::GoToGame, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2));

	auto exitItem = MenuItemImage::create("Exit Button.png", "Exit Button Clicked.png", CC_CALLBACK_1(MainMenu::Exit, this));
	exitItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 - 45));

	auto menu = Menu::create(playItem, exitItem, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);
    
    return true;
}


void MainMenu::GoToGame(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void MainMenu::Exit(cocos2d::Ref *sender)
{
	exit(0);
}