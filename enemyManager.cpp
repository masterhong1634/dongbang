#include "stdafx.h"
#include "enemyManager.h"
#include"rocket.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	this->setMinion(2,5);

	_bullet = new bullet;
	_bullet->init("Minion1Bullet", 100000, 1000);
	return S_OK;
}

void enemyManager::release()
{
	SAFE_DELETE(_bullet);
}

void enemyManager::update()
{

	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	//uf 총알
	_bullet->update();

	collision();
	

	if (time < 200)
	{
		minionMove(3, 0);
		this->minionBulletFire();
	}

	if (time == 200)
	{
		this->setMinion2(2, 5);
	}

	if (time < 400 && time > 200)
	{
		minionMove(-3, 0);
		this->minionBulletFire();
	}
	
	if (time == 400)
	{
		this->setMinion3(2, 3);
	}
	if (time == 600)
	{
		this->setMinion4(2, 3);
	}

	if (time < 800 && time > 400)
	{
		minionMove(0, 3);
		this->minionBulletFire();
	}

	if (time == 800)
	{
		setMinion4(1, 5);
	}
	if (time == 1000)
	{
		setMinion(1, 5);
	}
	if (time < 1200 && time > 800)
	{
		minionMove(-2, 2);
		this->minionBulletFire();
	}

	if (time == 1200)
	{
		setMinion2(1, 5);
	}
	if (time == 1400)
	{
		setMinion3(1, 5);
	}

	if (time < 1600 && time > 1200)
	{
		minionMove(-2, 2);
		this->minionBulletFire();
	}

	if (time == 1600)
	{
		setMinion4(1, 5);
	}
	if (time == 1800)
	{
		setMinion4(1, 5);
	}
	if (time < 2000 && time > 1600)
	{
		minionMove(3, 3);
		this->minionBulletFire2();
	}


	if (time == 2000)
	{
		setMinion4(1, 5);
	}
	if (time == 2200)
	{
		setMinion4(1, 5);
	}
	if (time < 2400 && time > 2000)
	{
		minionMove(-3, 3);
		this->minionBulletFire2();
	}

	if (time == 2400)
	{
		setMinion5(2, 8);
	}

	if (time == 2600)
	{
		setMinion6(2, 8);
	}

	if (time < 2800 && time > 2400)
	{
		minionMove(2, 2);
		this->minionBulletFire2();
	}

	if (time == 2800)
	{
		setMinion7(2, 8);
	}
	if (time == 3000)
	{
		setMinion8(2, 8);
	}
	if (time < 3200 && time > 2800)
	{
		minionMove(-2, 2);
		this->minionBulletFire2();
	}

	if (time == 3200)
	{
		setmiddleboss1(1, 2);
	}
	if (time == 3200)
	{
		setmiddleboss2(1, 2);
	}
	if (time < 3900 && time > 3200)
	{
		minionMove(0, 0);
		this->minionBulletFire3();
	}
	if (time == 3900)
	{
		setboss(1, 1);		
	}
	if (time > 3900 && time < 4300)
	{
		minionMove(-1, 0);
		minionBulletFire4();
	}
	if (time > 4300 && time < 4700)
	{
		minionMove(1, 0);
		minionBulletFire5();
	}
	if (time > 4700 && time < 5100)
	{
		minionMove(0, 1);
		minionBulletFire6();
	}
	if (time > 5100 && time < 5500)
	{
		minionMove(0, -1);
		minionBulletFire7();
	}
	if (time > 5500 && time < 5900)
	{
		minionMove(-1, 0);
		minionBulletFire8();
	}
	if (time > 5900 && time < 6300)
	{
		minionMove(1, 0);
		minionBulletFire9();
	}

	time++;
	score += 1;
}

void enemyManager::render()
{
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}
	_bullet->render();
}

void enemyManager::setMinion(int x, int y)
{

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* enemy1;
			enemy1 = new minion;
			enemy1->init("enemy1", PointMake(100 + j * 100, 100 + i * 100));
			_vMinion.push_back(enemy1);
		}
	}
}

void enemyManager::setMinion2(int x, int y)
{
	_bullet->init("Minion2Bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* enemy2;
			enemy2 = new minion;
			enemy2->init("enemy2", PointMake(600 - j * 100, 100 + i * 100));
			_vMinion.push_back(enemy2);
		}
	}
}

void enemyManager::setMinion3(int x, int y)
{
	_bullet->init("Minion3Bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* enemy3;
			enemy3 = new minion;
			enemy3->init("enemy3", PointMake(150 + j * 100, 100 + i * 100));
			_vMinion.push_back(enemy3);
		}
	}
}

void enemyManager::setMinion4(int x, int y)
{
	_bullet->init("Minion4Bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* enemy4;
			enemy4 = new minion;
			enemy4->init("enemy4", PointMake(600 - j * 100, 100 + i * 100));
			_vMinion.push_back(enemy4);
		}
	}
}

void enemyManager::setMinion5(int x, int y)
{
	_bullet->init("Minion1Bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* enemy5;
			enemy5 = new minion;
			enemy5->init("minion1", PointMake(100 + j * 50, 100 + i * 50));
			_vMinion.push_back(enemy5);
			enemy5->_currentHP = 150;
			enemy5->_maxHP = 150;
		}
	}
}

void enemyManager::setMinion6(int x, int y)
{
	_bullet->init("Minion2Bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* enemy6;
			enemy6 = new minion;
			enemy6->init("minion2", PointMake(100 + j * 50, 100 + i * 50));
			_vMinion.push_back(enemy6);
			enemy6->_currentHP = 150;
			enemy6->_maxHP = 150;
		}
	}
}

void enemyManager::setMinion7(int x, int y)
{
	_bullet->init("Minion3Bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* enemy7;
			enemy7 = new minion;
			enemy7->init("minion3", PointMake(600 - j * 50, 100 + i * 50));
			_vMinion.push_back(enemy7);
			enemy7->_currentHP = 150;
			enemy7->_maxHP = 150;
		}
	}
}

void enemyManager::setMinion8(int x, int y)
{
	_bullet->init("Minion4Bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* enemy8;
			enemy8 = new minion;
			enemy8->init("minion4", PointMake(600 - j * 50, 100 + i * 50));
			_vMinion.push_back(enemy8);
			enemy8->_currentHP = 150;
			enemy8->_maxHP = 150;
		}
	}
}

void enemyManager::setmiddleboss1(int x, int y)
{
	_bullet->init("Minion4Bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* middleboss1;
			middleboss1 = new minion;
			middleboss1->init("middleboss1", PointMake(150 + j * 50, 100 + i * 50));
			_vMinion.push_back(middleboss1);
			middleboss1->_currentHP = 1200;
			middleboss1->_maxHP = 1200;
		}
	}
}

void enemyManager::setmiddleboss2(int x, int y)
{
	_bullet->init("Minion4Bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* middleboss2;
			middleboss2 = new minion;
			middleboss2->init("middleboss2", PointMake(550 - j * 50, 100 + i * 50));
			_vMinion.push_back(middleboss2);
			middleboss2->_currentHP = 1200;
			middleboss2->_maxHP = 1200;
		}
	}
}

void enemyManager::setboss(int x, int y)
{
	_bullet->init("boss_bullet", 10000, 1000);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			enemy* middleboss2;
			middleboss2 = new minion;
			middleboss2->init("boss", PointMake(550 - j * 50, 100 + i * 50));
			_vMinion.push_back(middleboss2);
			middleboss2->_currentHP = 30000;
			middleboss2->_maxHP = 30000;
		}
	}
}

void enemyManager::minionMove(int x, int y)
{
	_viMinion = _vMinion.begin();
	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->animation(x, y);
	}
}

void enemyManager::minionBulletFire()
{
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire(20))
		{
			//나로호로 발사하기
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom + (rc.top - rc.bottom) / 2,
				getAngle(rc.left + (rc.right - rc.left) / 2,
					rc.bottom + (rc.top - rc.bottom) / 2,
					(_rocket->getRocketRect().left+ _rocket->getRocketRect().right) / 2,
					(_rocket->getRocketRect().top + _rocket->getRocketRect().bottom) / 2), 6.0f);
		}
	}
}

void enemyManager::minionBulletFire2()
{
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire(20))
		{
			////회전 발사
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle, 5.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle+1, 5.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle+2, 5.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle+3, 5.0f);
		}
	}
	angle -= 0.05;
}
void enemyManager::minionBulletFire3()
{
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire(5))
		{
			////회전 발사
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle*2 , 2.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle*3, 2.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle*4, 2.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle*5, 2.0f);
		}
	}
	angle -= 0.05;
}
void enemyManager::minionBulletFire4()
{
	_bullet->init("boss_bullet2", 10000, 1000);
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire(5))
		{
			////회전 발사
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 2, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 3, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 4, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 5, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 6, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 7, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 8, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 9, 10.0f);
		}
	}
	angle -= 0.05;
}

void enemyManager::minionBulletFire5()
{
	_bullet->init("boss_bullet3", 10000, 1000);
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire(5))
		{
			////회전 발사
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 2, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 3, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 4, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 5, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 6, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 7, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 8, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 9, 10.0f);
		}
	}
	bullet_count++;
	angle -= 0.05 + bullet_count;
}

void enemyManager::minionBulletFire6()
{
	_bullet->init("boss_bullet3", 10000, 1000);
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire(5))
		{
			////회전 발사
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle - angle * 2, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 - 50, rc.bottom -50, angle - angle * 3, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 - 50, rc.bottom -100, angle - angle * 4, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 - 50, rc.bottom -150, angle - angle * 5, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom - 200, angle - angle * 6, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 + 50, rc.bottom - 50, angle - angle * 7, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 + 50, rc.bottom - 100, angle - angle * 8, 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 + 50, rc.bottom - 150, angle - angle * 9, 10.0f);
		}
	}
	bullet_count++;
	angle -= 0.05 + bullet_count;
}

void enemyManager::minionBulletFire7()
{
	_bullet->init("boss_bullet4", 10000, 1000);
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire(5))
		{
			//나로호로 발사하기
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom,
				getAngle(rc.left + (rc.right - rc.left) / 2,
					rc.bottom + (rc.top - rc.bottom) / 2,
					(_rocket->getRocketRect().left + _rocket->getRocketRect().right) / 2,
					(_rocket->getRocketRect().top + _rocket->getRocketRect().bottom) / 2), 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 - 50, rc.bottom - 50,
				getAngle(rc.left + (rc.right - rc.left) / 2,
					rc.bottom + (rc.top - rc.bottom) / 2,
					(_rocket->getRocketRect().left + _rocket->getRocketRect().right) / 2,
					(_rocket->getRocketRect().top + _rocket->getRocketRect().bottom) / 2), 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 - 50, rc.bottom - 100,
				getAngle(rc.left + (rc.right - rc.left) / 2,
					rc.bottom + (rc.top - rc.bottom) / 2,
					(_rocket->getRocketRect().left + _rocket->getRocketRect().right) / 2,
					(_rocket->getRocketRect().top + _rocket->getRocketRect().bottom) / 2), 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 - 50, rc.bottom - 150,
				getAngle(rc.left + (rc.right - rc.left) / 2,
					rc.bottom + (rc.top - rc.bottom) / 2,
					(_rocket->getRocketRect().left + _rocket->getRocketRect().right) / 2,
					(_rocket->getRocketRect().top + _rocket->getRocketRect().bottom) / 2), 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 + 50, rc.bottom - 50,
				getAngle(rc.left + (rc.right - rc.left) / 2,
					rc.bottom + (rc.top - rc.bottom) / 2,
					(_rocket->getRocketRect().left + _rocket->getRocketRect().right) / 2,
					(_rocket->getRocketRect().top + _rocket->getRocketRect().bottom) / 2), 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 + 50, rc.bottom - 100,
				getAngle(rc.left + (rc.right - rc.left) / 2,
					rc.bottom + (rc.top - rc.bottom) / 2,
					(_rocket->getRocketRect().left + _rocket->getRocketRect().right) / 2,
					(_rocket->getRocketRect().top + _rocket->getRocketRect().bottom) / 2), 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2 + 50, rc.bottom - 150,
				getAngle(rc.left + (rc.right - rc.left) / 2,
					rc.bottom + (rc.top - rc.bottom) / 2,
					(_rocket->getRocketRect().left + _rocket->getRocketRect().right) / 2,
					(_rocket->getRocketRect().top + _rocket->getRocketRect().bottom) / 2), 10.0f);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom - 200,
				getAngle(rc.left + (rc.right - rc.left) / 2,
					rc.bottom + (rc.top - rc.bottom) / 2,
					(_rocket->getRocketRect().left + _rocket->getRocketRect().right) / 2,
					(_rocket->getRocketRect().top + _rocket->getRocketRect().bottom) / 2), 10.0f);
		}
	}
}

void enemyManager::minionBulletFire8()
{
	_bullet->init("boss_bullet5", 10000, 1000);
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire(5))
		{
			bullet_count++;
			////회전 발사
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 2, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 3, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 4, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 5, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 6, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 7, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 8, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 9, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 10, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 11, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 12, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 13, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 14, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 15, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 16, bullet_count);
		}

		if (bullet_count > 12)
		{
			bullet_count = 0;
		}
	}
}

void enemyManager::minionBulletFire9()
{
	_bullet->init("boss_bullet6", 10000, 1000);
	_viMinion = _vMinion.begin();

	for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire(5))
		{
			bullet_count++;
			////회전 발사
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 2, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 3, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 4, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 5, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 6, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 7, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 8, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 9, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 10, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 11, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 12, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 13, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 14, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 15, bullet_count);
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom, angle2 * 16, bullet_count);
		}

		if (bullet_count > 21)
		{
			bullet_count = 0;
		}
	}
}
void enemyManager::removeMinion(int arrNum)
{
	score += 100;
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void enemyManager::collision()
{
	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		RECT rc;

		if (IntersectRect(&rc, &_bullet->getVBullet()[i].rc, &_rocket->getRocketRect()))
		{
			_bullet->removeMissile(i);
			_rocket->hitDamage(5);
		}
	}
}
