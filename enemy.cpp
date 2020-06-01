#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT enemy::init()
{
	return S_OK;
}

HRESULT enemy::init(const char * imageName, POINT position)
{
	//프레임 초기화
	_count= 0;
	_currentFrameX = 0;
	_currentFrameY = 0;
	//랜덤
	_fireCount = 0;
	_rndFireCount = RND->getFromIntTo(1, 5);
	//이미지, 렉트

	_image = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(position.x, position.y, _image->getFrameWidth(), _image->getFrameHeight());

	_maxHP = _currentHP = 100;
	_hpBar = new progressBar;
	_hpBar->init("images/progressBarFront.bmp", "images/progressBarBack.bmp", 0, 0, _image->getFrameWidth(), 10);
	_hpBar->setGauge(_currentHP, _maxHP);


	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	//프로그래스
	_hpBar->setX(_rc.left);
	_hpBar->setY(_rc.top);
	_hpBar->setGauge(_currentHP, _maxHP);
	_hpBar->update();
}

void enemy::render()
{
	draw();

}

void enemy::draw()
{
	if (_rc.left > 51 && _rc.right < 664 && _rc.top > 26 && _rc.bottom < 742)
	{			
		_image->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
		_hpBar->render(30,0); // hp bar.
	}	
	else
	{
		release();
	}
}

void enemy::animation()
{
	_count++;
	if (_count % 10 == 0)
	{
		_image->setFrameX(_image->getFrameX() + 1);
		_currentFrameX++;

		if (_currentFrameX >= _image->getMaxFrameX())
		{
			_currentFrameX = 0;
		}
	}
}

void enemy::animation(int x, int y)
{
	_count++;
	if (_count % 10 == 0)
	{
		_image->setFrameX(_image->getFrameX() + 1);
		_currentFrameX++;

		if (_currentFrameX >= _image->getMaxFrameX())
		{
			_currentFrameX = 0;
		}
	}
	_rc.right += x;
	_rc.left += x;
	_rc.top += y;
	_rc.bottom += y;
}

bool enemy::bulletCountFire(int x)
{
	if (_rc.left > 51 && _rc.right < 664 && _rc.top > 26 && _rc.bottom < 742)
	{
		_fireCount++;

		if (_fireCount % _rndFireCount == 0)
		{
			_rndFireCount = RND->getFromIntTo(1, x);
			_fireCount = 0;
			return true;
		}
	}
		return false;	
}

void enemy::hitDamage(float damage)
{
	_currentHP -= damage;
}
