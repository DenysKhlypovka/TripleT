#include "Game.h"
#include "Definitions.h"

USING_NS_CC;

Game::Game(cocos2d::Layer *layer)
{
	turn = 'X';
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ar[i][j] = '0';
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
}

void Game::PlaceObj(cocos2d::Layer *layer, int touchX, int touchY)
{
	//Obj->setPosition(Point(x, y));
	//layer->addChild(Obj);

	Sprite* grid = Sprite::create("grid.png");
	Size gridSize = grid->getContentSize();
	
	int gridBeginsX = visibleSize.width / 2 + origin.x - gridSize.width / 2;
	int gridBeginsY = visibleSize.height / 2 + origin.y - gridSize.height / 2;

	if ((touchX < gridBeginsX || touchX > gridBeginsX + gridSize.width) ||
		(touchY < gridBeginsY || touchY > gridBeginsY + gridSize.height))
		return;

	float coeffX = (touchX - gridBeginsX) / gridSize.width;
	float coeffY = (touchY - gridBeginsY) / gridSize.height;

	if (coeffX < 0.34)
		coeffX = 0;
	else if (coeffX < 0.67)
		coeffX = 1;
	else
		coeffX = 2;


	if (coeffY < 0.34)
		coeffY = 0;
	else if (coeffY < 0.67)
		coeffY = 1;
	else
		coeffY = 2;

	if (ar[(int)coeffX][(int)coeffY] == '0')
	{

		Sprite* Obj = Sprite::create();
		if (turn == 'X')
		{
			turn = 'O';
			Obj = Sprite::create("X.png");
		}
		else if (turn == 'O')
		{
			Obj = Sprite::create("O.png");
			turn = 'X';
		}

		ar[(int)coeffX][(int)coeffY] = turn;

		int coordX = (1 + coeffX * 2) * gridSize.width / 6 + gridBeginsX;
		int coordY = (1 + coeffY * 2) * gridSize.height / 6 + gridBeginsY;

		Obj->setPosition(Point(coordX, coordY));
		layer->addChild(Obj);
	}
}

short Game::Check()
{
	if ((ar[0][0] == turn && ar[1][0] == turn && ar[2][0] == turn) ||
		(ar[0][1] == turn && ar[1][1] == turn && ar[2][1] == turn) ||
		(ar[0][2] == turn && ar[1][2] == turn && ar[2][2] == turn) ||

		(ar[0][0] == turn && ar[0][1] == turn && ar[0][2] == turn) ||
		(ar[1][0] == turn && ar[1][1] == turn && ar[1][2] == turn) ||
		(ar[2][0] == turn && ar[2][1] == turn && ar[2][2] == turn) ||

		(ar[0][0] == turn && ar[1][1] == turn && ar[2][2] == turn) ||
		(ar[2][0] == turn && ar[1][1] == turn && ar[0][2] == turn))
		return 1;

	int count = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (ar[i][j] != '0')
				count++;
	if (count == 9)
		return 0;
	return 10;
}
