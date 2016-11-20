#include "GameOverScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"


USING_NS_CC;

char Winner = ' ';

Scene* GameOver::createScene(char turn)
{

	Winner = turn;
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOver::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Game Over.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	auto Result = LabelTTF::create("", "fonts/Marker Felt.ttf", 26);

	if (Winner == 'O')
		Result->setString("X Wins");
	else if (Winner == 'X')
		Result->setString("O Wins");
	else
		Result->setString("Draw");

	Result->setColor(Color3B(200,100,100));
	Result->setPosition(Point(visibleSize.width / 2 + origin.x, 3 * visibleSize.height / 4 + origin.y));
	this->addChild(Result);

	auto retryItem = MenuItemImage::create("Retry Button.png", "Retry Button Clicked.png", CC_CALLBACK_1(GameOver::GoToGame, this));
	retryItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2));

	auto menuItem = MenuItemImage::create("Menu Button.png", "Menu Button Clicked.png", CC_CALLBACK_1(GameOver::GoToMainMenu, this));
	menuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 - 45));

	auto menu = Menu::create(retryItem, menuItem, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);

    return true;
}

void GameOver::GoToGame(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameOver::GoToMainMenu(cocos2d::Ref *sender)
{
	auto scene = MainMenu::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}