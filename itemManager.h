#pragma once
#include"gameNode.h"

class itemManager : public gameNode
{
private:

	image * _image;
	RECT _rc;

public:
	itemManager();
	~itemManager();


	HRESULT init();
	HRESULT init(const char* imageName, POINT position);
	void release();
	void update();
	void render();

	virtual void draw();
	virtual void animation();
	virtual void animation(int x, int y);

	RECT getRect() { return _rc; }

};

