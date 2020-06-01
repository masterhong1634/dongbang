#pragma once
#include"gameNode.h"
#include"progressBar.h"
//에너미 클래스를 상속받아서 보스나 부하들을 만들어된다.
class enemy : public gameNode
{
public :

	image * _image;
	RECT _rc;

	int _currentFrameX;
	int _currentFrameY;
	int _count;
	bool _life = 1;

	//랜덤으로 총알 발사할 변수들
	int _fireCount;
	int _rndFireCount;


	// 프로그레스바
	progressBar* _hpBar;
	float _maxHP;
	float _currentHP;


public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(const char* imageName, POINT position);
	void release();
	void update();
	void render();
	

	virtual void draw();
	virtual void animation();
	virtual void animation(int x, int y);

	bool bulletCountFire(int x);

	RECT getRect() { return _rc; }

	//피깎는 함수
	void hitDamage(float damage);

};

