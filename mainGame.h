#pragma once
#include"gameNode.h"
#include "bg_Map.h"
#include "rocket.h"
#include "enemyManager.h"
#include "bg_Map.h"
class mainGame :  public gameNode
{
private:

public:
	mainGame();
	~mainGame();

	bg_Map* bg;
	rocket* _rocket;
	enemyManager* _enemyManager;

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�
	
};

