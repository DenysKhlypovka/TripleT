#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Game.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
	void GoToGameOverScene(float dt);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	Game *game;
};

#endif // __GAME_SCENE_H__
