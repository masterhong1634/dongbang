#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);
	bg = new bg_Map;
	bg->init();

	SCENEMANAGER->addScene("bg_Map", new bg_Map);

	IMAGEMANAGER->addImage("bullet", "images/bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	//enemy
	IMAGEMANAGER->addFrameImage("enemy1", "images/enemy1.bmp", 396*2, 60*2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enemy2", "images/enemy2.bmp", 396*2, 60*2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enemy3", "images/enemy3.bmp", 396*2, 60*2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enemy4", "images/enemy4.bmp", 396*2, 60*2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("minion1", "images/minion1.bmp", 396*2, 60*2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("minion2", "images/minion2.bmp", 396*2, 60*2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("minion3", "images/minion3.bmp", 396*2, 60*2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("minion4", "images/minion4.bmp", 396*2, 60*2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("middleboss1", "images/middleboss1.bmp", 840*2, 50*2, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("middleboss2", "images/middleboss2.bmp", 840*2, 50*2, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("boss", "images/boss.bmp", 191*2, 131*2, 3, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Hpgauge", "images/Hpgauge.bmp", 267*2, 6*2, 1, 1, true, RGB(255, 0, 255));
	//enemy_bullet
	IMAGEMANAGER->addImage("Minion1Bullet", "images/Minion1Bullet.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Minion2Bullet", "images/Minion2Bullet.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Minion3Bullet", "images/Minion3Bullet.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Minion4Bullet", "images/Minion4Bullet.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("boss_bullet", "images/boss_bullet.bmp", 10, 17, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("boss_bullet2", "images/boss_bullet2.bmp", 15, 15, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("boss_bullet3", "images/boss_bullet3.bmp", 15, 15, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("boss_bullet4", "images/boss_bullet4.bmp", 10, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("boss_bullet5", "images/boss_bullet5.bmp", 10, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("boss_bullet6", "images/boss_bullet6.bmp", 16, 16, true, RGB(255, 0, 255));



	_rocket = new rocket;
	_rocket->init();


	_enemyManager = new enemyManager;
	_enemyManager->init();


	_rocket->setEnemyMemoryLink(_enemyManager);
	bg->setEnemyMemoryLink(_enemyManager);
	bg->setRocketMemoryLink(_rocket);
	_enemyManager->setRocketMemoryLink(_rocket);
	
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	bg->release();
	SAFE_DELETE(_enemyManager);
}
void mainGame::update()
{
	gameNode::update();
	bg->update();
	_rocket->update();
	_enemyManager->update();
	SCENEMANAGER->update();
}

void mainGame::render(/*HDC hdc*/)
{	
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	bg->render();
	
	_rocket->render();
	_enemyManager->render();
	TIMEMANAGER->render(getMemDC());
	SCENEMANAGER->render();

	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

