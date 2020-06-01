#pragma once
#include"gameNode.h"
#include"bullet.h"
#include"minion.h"
#include"enemy.h"


class rocket;
class enemyManager :  public gameNode
{
public:

	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;
	rocket* _rocket;

public:

	vEnemy		_vMinion;
	viEnemy		_viMinion;
	bullet*     _bullet;

	float angle = PI_4;//
	float angle2 = PI_8;//

	int count = 0; // 
	int time = 0;
	int bullet_count = 0;
	int score = 0;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();


	void setMinion(int x, int y);
	void setMinion2(int x, int y);
	void setMinion3(int x, int y);
	void setMinion4(int x, int y);
	void setMinion5(int x, int y);
	void setMinion6(int x, int y);
	void setMinion7(int x, int y);
	void setMinion8(int x, int y);
	void setmiddleboss1(int x, int y);
	void setmiddleboss2(int x, int y);
	void setboss(int x, int y);

	void minionMove(int x, int y);
	void minionBulletFire();
	void minionBulletFire2();
	void minionBulletFire3();
	void minionBulletFire4();
	void minionBulletFire5();
	void minionBulletFire6();
	void minionBulletFire7();
	void minionBulletFire8();
	void minionBulletFire9();



	vEnemy		getVMinion() { return _vMinion; }
	viEnemy		getViMinion() { return _viMinion; }

//	int getTime() { return time; }

	void removeMinion(int arrNum);

	void collision();

	void setRocketMemoryLink(rocket* rocket) { _rocket = rocket; }

};

