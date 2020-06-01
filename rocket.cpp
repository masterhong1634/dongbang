#include "stdafx.h"
#include "rocket.h"
#include"enemyManager.h"
#pragma warning(disable : 4996)

//cpp에 인클루드 해야 진정한 상호참조...
rocket::rocket()
{
}

rocket::~rocket()
{
}

HRESULT rocket::init()
{

	_player = IMAGEMANAGER->addFrameImage("캐릭터", "images/player1.bmp", 350, WINSIZEY - 200, 256 * 3 / 2, 114 * 3 / 2, 8, 3, true, RGB(255, 0, 255));

	rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _player->getFrameWidth(), _player->getFrameHeight());

	//_destroy = IMAGEMANAGER->addFrameImage("destroy", images/destroy.bmp", 0,0,)

	_missile = new missile;
	_missile->init(300, 1000);

	_nuclear = new nuclear;
	_nuclear->init(30000, 1000);

	_skill = new skill;
	_skill->init(3, 700);


	_maxHP = _currentHP = 100;
	_hpBar = new progressBar;
	_hpBar->init("images/progressBarFront.bmp", "images/progressBarBack.bmp", 0, 0, 50, 10);
	_hpBar->setGauge(_currentHP, _maxHP);
	return S_OK;
}

void rocket::release()
{
	SAFE_DELETE(_missile);
	SAFE_DELETE(_nuclear);
	SAFE_DELETE(_skill);
	SAFE_DELETE(_hpBar);
}

void rocket::update()
{
	//if (_currentHP <= 0)
	//{
	//	this->~rocket();
	//	_maxLife--;
	//}

	//if (_maxLife > 0 && _currentHP <= 0)
	//{
	//	new rocket;
	//	_player1 = IMAGEMANAGER->addFrameImage("캐릭터", "images/player1.bmp", 350, WINSIZEY - 200, 256 * 3 / 2, 114 * 3 / 2, 8, 3, true, RGB(255, 0, 255));

	//	rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _player1->getFrameWidth(), _player1->getFrameHeight());

	//}
	////왼쪽
	//if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _player->getX() > 0)
	//{
	//	_player->setX(_player->getX() - PLAYERSPEED);
	//}

	////오른쪽
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _player->getX() + _player->getWidth() < WINSIZEX)
	//{
	//	_player->setX(_player->getX() + PLAYERSPEED);
	//}

	////위
	//if (KEYMANAGER->isStayKeyDown(VK_UP) && _player->getY() > 0)
	//{
	//	_player->setY(_player->getY() - PLAYERSPEED);
	//}

	////아래
	//if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _player->getY() + _player->getHeight() < WINSIZEY)
	//{
	//	_player->setY(_player->getY() + PLAYERSPEED);
	//}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = true;
		frame_speed++;
		if (frame_speed % 15 == 0)
		{
			frame_count++;
			_player->setFrameY(1);
			_player->setFrameX(frame_count);
		}
		if (rc.left > 51)
		{
			rc.left -= 9;
			rc.right -= 9;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_isLeft = false;
		frame_count = 0;
	}
	if (!_isLeft && !_isRight) // 가만히 서있을때
	{
		frame_speed++;
		if (frame_speed % 12 == 0)
		{
			frame_count++;
			_player->setFrameY(0);
			_player->setFrameX(frame_count);
			if (frame_count > _player->getMaxFrameX())
			{
				frame_count = 0;
			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isRight = true;
		frame_speed++;
		if (frame_speed % 15 == 0)
		{
			frame_count++;
			_player->setFrameY(2);
			_player->setFrameX(frame_count);
		}
		if (rc.right < 664)
		{
			rc.left += 9;
			rc.right += 9;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isRight = false;
		frame_count = 0;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (rc.top > 26)
		{
			rc.top -= 9;
			rc.bottom -= 9;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && rc.bottom < 742)
	{
		if (rc.bottom < 742)
		{
			rc.top += 9;
			rc.bottom += 9;
		}
	}

	//if (KEYMANAGER->isStayKeyDown(VK_LEFT) )
	//{
	//	rc.left -= PLAYERSPEED;
	//	rc.right -= PLAYERSPEED;
	//}

	////오른쪽
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT) )
	//{
	//	rc.left += PLAYERSPEED;
	//	rc.right += PLAYERSPEED;
	//}

	////위
	//if (KEYMANAGER->isStayKeyDown(VK_UP))
	//{
	//	rc.top -= PLAYERSPEED;
	//	rc.bottom -= PLAYERSPEED;
	//}

	////아래
	//if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	//{
	//	rc.top += PLAYERSPEED;
	//	rc.bottom += PLAYERSPEED;
	//}

	if (KEYMANAGER->isStayKeyDown('X'))
	{
		missile_count++;
		if (missile_count == 5)
		{
			_missile->fire(rc.right - (rc.right - rc.left) / 2, rc.top - 50);
			//_missile->fire(_player->getX() + _player->getFrameWidth() / 2, _player->getY() - 50);
			missile_count = 0;
		}

	}
	if (KEYMANAGER->isStayKeyDown('Z'))
	{
		nuclear_count++;
		if (nuclear_count == 5)
		{
			_nuclear->fire(rc.right - (rc.right - rc.left) / 2, rc.top - 10);
			//_nuclear->fire(_player->getX() + _player->getFrameWidth() / 2, _player->getY() - 50);
			nuclear_count = 0;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		skill_count--;
		if (skill_count >= 0)
		{
			_skill->fire(rc.right - (rc.right - rc.left) / 2, rc.top - 10);
		}		
	}

	_missile->update();
	_nuclear->update();
	_skill->update();

	collision();
	collision2();

	//프로그래스
	_hpBar->setX(rc.right - (rc.right - rc.left) / 2);
	_hpBar->setY(rc.top);
	_hpBar->setGauge(_currentHP, _maxHP);
	_hpBar->update();

	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		char temp[64];
		vector<string>vStr;

		vStr.push_back(_itoa(_currentHP, temp, 10));
		vStr.push_back(_itoa(_maxHP, temp, 10));
		vStr.push_back(_itoa(_player->getX(), temp, 10));
		vStr.push_back(_itoa(_player->getY(), temp,10));

		TXTDATA->txtSave("save/rocketData.txt", vStr);
	}
	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		vector<string> vStr (TXTDATA->txtLoad("save/rocketData.txt"));

		_currentHP = stoi(vStr[0]);
		_maxHP = stoi(vStr[1]);
		_player->setX(stoi(vStr[2]));
		_player->setY(stoi(vStr[3]));
	}
}

void rocket::render()
{
	_player->frameRender(getMemDC(), rc.left, rc.top, _player->getFrameX(), _player->getFrameY());
	//_player->render(getMemDC(), rc.left, rc.top);

	_missile->render();
	_nuclear->render();
	_skill->render();

	_hpBar->render(); // hp bar.

	//for (int j = 0; j < _em->getVMinion().size(); j++)
	//{
	//	if (_em->getVMinion()[j]->_life = 0)
	//	{
	//		frameRender(getMemDC(), )
	//	}
	//}
	

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}
}

void rocket::removeMissile(int arrNum)
{
	_nuclear->removeNuclear(arrNum);
}

void rocket::removeSkill(int arrNum)
{
	_skill->removeSkill(arrNum);
}

void rocket::collision()
{
	for (int i = 0; i < _nuclear->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			if (IntersectRect(&temp, &_nuclear->getVBullet()[i].rc, &_em->getVMinion()[j]->getRect()))
			{
				_nuclear->removeNuclear(i);
				_em->getVMinion()[j]->hitDamage(50);
				_em->score += 30;
				if (_em->getVMinion()[j]->_currentHP <= 0)
				{
					_em->removeMinion(j);
					break;
				}
				break;
			}
		}
	}
}

void rocket::collision2()
{
	for (int i = 0; i < _skill->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			if (IntersectRect(&temp, &_skill->getVBullet()[i].rc, &_em->getVMinion()[j]->_rc))
			{
				_em->removeMinion(j);
				break;
			}
		}
	}
}

void rocket::hitDamage(float damage) // damage
{
	_currentHP -= damage;
}

