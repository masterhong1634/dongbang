#include "stdafx.h"
#include "itemManager.h"


itemManager::itemManager()
{
}


itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	return S_OK;
}

HRESULT itemManager::init(const char * imageName, POINT position)
{
	_image = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(position.x, position.y, _image->getWidth(), _image->getHeight());
	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
}

void itemManager::render()
{
	draw();
}

void itemManager::draw()
{
	if (_rc.left > 51 && _rc.right < 664 && _rc.top > 26 && _rc.bottom < 742)
	{
		_image->render(getMemDC(), _rc.left, _rc.top);
	}
	else
	{
		release();
	}
}

void itemManager::animation()
{
}

void itemManager::animation(int x, int y)
{
}
