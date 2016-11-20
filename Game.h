#ifndef __GAME_H__
#define __GAME_H__

#include "cocos2d.h"

class Game
{
public:
	char turn;
	char ar[3][3];
	Game(cocos2d::Layer *layer);
	short Check();
	void PlaceObj(cocos2d::Layer *layer, int touchX, int touchY);

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

};

#endif // __GAME_H__