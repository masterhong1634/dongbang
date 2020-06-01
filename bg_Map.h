#pragma once
#include"gameNode.h"
#include"enemyManager.h"
#include"rocket.h"
class bg_Map : public gameNode
{
public:
	bg_Map();
	~bg_Map();

	image* _bg;
	image* _bg_sky;
	image* _bg_boss;
	image* _score;
	image* _number;
	image* _power;
	image* _skill;
	image* _star;

	rocket* _rocket;

	enemyManager* _em;

	int look = 0;

	int _loopX = 0;
	int _loopY = 0;

	int _current_frame[8] = { 0, };

	HRESULT init();
	void release();
	void update();
	void render();

	void setEnemyMemoryLink(enemyManager* em) { _em = em; }
	void setRocketMemoryLink(rocket* rocket) { _rocket = rocket; }
};

