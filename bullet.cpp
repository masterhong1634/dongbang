#include "stdafx.h"
#include "bullet.h"


bullet::bullet(){}
bullet::~bullet(){}

HRESULT bullet::init(char * imageName, int bulletMax, float range)
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;
	return S_OK;
}

void bullet::release()
{
}

void bullet::update()
{
	move();
}

void bullet::render()
{
	_viBullet = _vBullet.begin();

	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->render(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
	}
}

void bullet::fire(float x, float y, float angle, float speed)
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.angle = angle;
	bullet.speed = speed;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getWidth(),
		bullet.bulletImage->getHeight());

	_vBullet.push_back(bullet);
}

void bullet::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		if (_viBullet->x < 51 || _viBullet->x > 664 || _viBullet->y < 26 || _viBullet->y > 742)
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;

	}
}

void bullet::removeMissile(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}

missile::missile(){}
missile::~missile(){}

HRESULT missile::init(int bulletMax, float range)
{

	//사거리 초기화
	_range = range;

	//총알 초기화
	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet));
		bullet.bulletImage = new image;
		bullet.bulletImage->init("images/PlayerNormalBullet.bmp", 26, 124, true, RGB(255, 0, 255));
		bullet.speed = 30.0f;
		bullet.fire = false;
		_vBullet.push_back(bullet);

	}
	return S_OK;
}

void missile::release()
{
}

void missile::update()
{
	move();
}

void missile::render()
{
	_viBullet = _vBullet.begin();

	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire)continue;
		_viBullet->bulletImage->render(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
	}
}

void missile::fire(float x, float y)
{
	_viBullet = _vBullet.begin();

	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->fire)continue;

		_viBullet->fire = true;
		_viBullet->x = _viBullet->fireX = x;
		_viBullet->y = _viBullet->fireY = y;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());
		break;
	}
}

void missile::move()
{
	_viBullet = _vBullet.begin();

	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire)continue;

		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		//총알이 사거리 보다 커지면
		if (_viBullet->x < 51 || _viBullet->x > 664 || _viBullet->y < 80 || _viBullet->y > 742)
		{
			_viBullet->fire = false;
		}

	}
}

nuclear::nuclear()
{
}

nuclear::~nuclear()
{
}

HRESULT nuclear::init(int bulletMax, float range)
{
	_missileMax = bulletMax;
	_range = range;
	return S_OK;
}

void nuclear::release()
{
}

void nuclear::update()
{
	move();
}

void nuclear::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->rc.left, _viBullet->rc.top,
			_viBullet->bulletImage->getFrameX(), 0);
	}
}

void nuclear::fire(float x, float y)
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage->init("images/PlayerNormalBullet.bmp", 0, 0, 30, 64, 1, 1, true, RGB(255, 0, 255));
	bullet.speed = 30.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());
	_vBullet.push_back(bullet);
}

void nuclear::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		//_viBullet->x = 100;
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(), _viBullet->bulletImage->getFrameHeight());
			   

		if (_viBullet->x < 51 || _viBullet->x > 664 || _viBullet->y < 50 || _viBullet->y > 742)
		{
			SAFE_DELETE(_viBullet->bulletImage);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void nuclear::removeNuclear(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}


void missile::removeMissile(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}

skill::skill()
{
}

skill::~skill()
{
}

HRESULT skill::init(int bulletMax, float range)
{
	_skillMax = bulletMax;
	_range = range;
	return S_OK;
}

void skill::release()
{
}

void skill::update()
{
	move();
}

void skill::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->rc.left, _viBullet->rc.top,
			_viBullet->bulletImage->getFrameX(), 0);
	}
}

void skill::fire(float x, float y)
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage->init("images/skill.bmp", 0, 0, 500, 500, 1, 1, true, RGB(255, 0, 255));
	bullet.speed = 5.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());
	_vBullet.push_back(bullet);
}

void skill::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		//_viBullet->x = 100;
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(), _viBullet->bulletImage->getFrameHeight());


		if (_viBullet->x < 51 || _viBullet->x > 664 || _viBullet->y < 50 || _viBullet->y > 742)
		{
			SAFE_DELETE(_viBullet->bulletImage);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void skill::removeSkill(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}
