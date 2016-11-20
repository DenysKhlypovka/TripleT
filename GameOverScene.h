#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__

#include "cocos2d.h"

class GameOver : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene(char turn);

    virtual bool init();
    
    // a selector callback
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);
private:
	void GoToGame(cocos2d::Ref *sender);
	void GoToMainMenu(cocos2d::Ref *sender);
};

#endif // __GAME_OVER_SCENE_H__
