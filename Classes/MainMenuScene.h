#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);

private:
	void GoToGame(cocos2d::Ref *sender);
	void Exit(cocos2d::Ref *sender);
};

#endif // __MAIN_MENU_SCENE_H__
