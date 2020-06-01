#include "stdafx.h"
#include "bg_Map.h"


bg_Map::bg_Map()
{
}


bg_Map::~bg_Map()
{
}

HRESULT bg_Map::init()
{
	_bg = IMAGEMANAGER->addImage("배경화면", "images/배경화면.bmp", WINSIZEX, WINSIZEY, true, RGB(255,0,255));
	_bg_sky = IMAGEMANAGER->addImage("카메라", "images/bg_flower2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_bg_boss = IMAGEMANAGER->addImage("bg_boss", "images/BossBackGround3.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_score = IMAGEMANAGER->addImage("score", "images/score.bmp", 47*2, 19*2, true, RGB(255, 0, 255));
	_star = IMAGEMANAGER->addImage("star", "images/UILife.bmp", 16*2, 16*2, true, RGB(255, 0, 255));
	_power = IMAGEMANAGER->addImage("power", "images/UIPower.bmp", 53*2, 19*2, true, RGB(255, 0, 255));
	_skill = IMAGEMANAGER->addImage("skilltext", "images/skilltext.bmp", 53*2, 19*2, true, RGB(255, 0, 255));
	_number = IMAGEMANAGER->addFrameImage("number", "images/number.bmp", WINSIZEX, WINSIZEY, 160*2, 18*2, 10, 1, true, RGB(255, 0, 255));
	return S_OK;
}

void bg_Map::release()
{
}

void bg_Map::update()
{
	_loopY--;
}

void bg_Map::render()
{
	_bg->render(getMemDC());
	if (_em->time > 3800)
	{
		if (look < 254)
		{
			look++;
		}
	}


	_bg_sky->loopAlphaRender(getMemDC(), &RectMake(51, 26, 614, 715), _loopX, _loopY, 255 - look);
	_bg_boss->loopAlphaRender(getMemDC(), &RectMake(51, 26, 614, 715), 0, 0, look);
	_score->render(getMemDC(), 690, 130);

		_current_frame[0] = _em->score % 10;
		_current_frame[1] = (_em->score % 100) / 10;
		_current_frame[2] = (_em->score % 1000) / 100;
		_current_frame[3] = (_em->score % 10000) / 1000;
		_current_frame[4] = (_em->score % 100000) / 10000;
		_current_frame[5] = (_em->score % 1000000) / 100000;
		_current_frame[6] = (_em->score % 10000000) / 1000000;
		_current_frame[7] = (_em->score % 100000000) / 10000000;

	_number->frameRender(getMemDC(), 790, 130, _current_frame[7], 0);
	_number->frameRender(getMemDC(), 790 + 25 * 1, 130, _current_frame[6], 0);
	_number->frameRender(getMemDC(), 790 + 25 * 2, 130, _current_frame[5], 0);
	_number->frameRender(getMemDC(), 790 + 25 * 3, 130, _current_frame[4], 0);
	_number->frameRender(getMemDC(), 790 + 25 * 4, 130, _current_frame[3], 0);
	_number->frameRender(getMemDC(), 790 + 25 * 5, 130, _current_frame[2], 0);
	_number->frameRender(getMemDC(), 790 + 25 * 6, 130, _current_frame[1], 0);
	_number->frameRender(getMemDC(), 790 + 25 * 7, 130, _current_frame[0], 0);	

	_skill->render(getMemDC(), 690, 200);
	for (int i = 0; i < _rocket->getskill_count(); i++)
	{
		_star->render(getMemDC(), 800 + 30 * i, 200);
	}
}
